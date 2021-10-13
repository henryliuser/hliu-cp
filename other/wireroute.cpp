/**
 * Parallel VLSI Wire Routing via OpenMP
 * Henry Liu (henryli2), Annie Xu (ajxu)
 */

#include "wireroute.h"

#include <assert.h>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <omp.h>
#include <vector>
#include <random>
#include <climits>
#include <stdio.h>
#include <fstream>
#include <iostream>

static int _argc;
static const char **_argv;

const char *get_option_string(const char *option_name,
                              const char *default_value) {
  for (int i = _argc - 2; i >= 0; i -= 2)
    if (strcmp(_argv[i], option_name) == 0)
      return _argv[i + 1];
  return default_value;
}

int get_option_int(const char *option_name, int default_value) {
  for (int i = _argc - 2; i >= 0; i -= 2)
    if (strcmp(_argv[i], option_name) == 0)
      return atoi(_argv[i + 1]);
  return default_value;
}

float get_option_float(const char *option_name, float default_value) {
  for (int i = _argc - 2; i >= 0; i -= 2)
    if (strcmp(_argv[i], option_name) == 0)
      return (float)atof(_argv[i + 1]);
  return default_value;
}

static void show_help(const char *program_path) {
  printf("Usage: %s OPTIONS\n", program_path);
  printf("\n");
  printf("OPTIONS:\n");
  printf("\t-f <input_filename> (required)\n");
  printf("\t-n <num_of_threads> (required)\n");
  printf("\t-p <SA_prob>\n");
  printf("\t-i <SA_iters>\n");
}

bool myCmp(int s, int e, int a, int b, bool include) {
  if (s < e) return (include) ? (a <= b) : (a < b);
  else return (include) ? (a >= b) : (a > b);
}

void writeCost(path_t &p, int val, cost_t *costs, int dim_x, int dim_y)
{
    #pragma omp critical
    {
      if (p.bend1.x != p.start.x)
      {
        for (int c = p.start.x; myCmp(p.start.x, p.end.x, c, p.bend1.x, 0); c += dirX)
          costs[p.start.y * dim_x + c] += val;
        for (int r = p.start.y; myCmp(p.start.y, p.end.y, r, p.end.y, 1); r += dirY)
          costs[r * dim_x + p.bend1.x] += val;
        for (int c = p.bend1.x + dirX; myCmp(p.start.x, p.end.x, c, p.end.x, 1); c += dirX)
          costs[p.end.y * dim_x + c] += val;
      }
      else
      {
        for (int c = p.start.y; myCmp(p.start.y, p.end.y, c, p.bend1.y, 0); c += dirY)
          costs[c * dim_x + p.start.x] += val;
        for (int r = p.start.x; myCmp(p.start.x, p.end.x, r, p.end.x, 1); r += dirX)
          costs[p.bend1.y * dim_x + r] += val;
        for (int c = p.bend1.y + dirY; myCmp(p.start.y, p.end.y, c, p.end.y, 1); c += dirY)
          costs[c * dim_x + p.end.x] += val;
      }
    }
}

void tryHorizontals(wire_t &wi, int dirX, int dirY,
                    int bestMax, int bestSum, cost_t *costs,
                    vector<path_t> &myPaths, int dim_x, int dim_y)
{
  for (int b1 = wi.x1 + dirX; myCmp(wi.x1, wi.x2, b1, wi.x2, 1); b1 += dirX) {
    int mx = 0;
    int sum = 0;
    for (int c = wi.x1; myCmp(wi.x1, wi.x2, c, b1, 0); c += dirX) {
      int co = costs[wi.y1 * dim_x + c]+1;
      sum = sum+co, mx = std::max(mx, co);
    }
    for (int r = wi.y1; myCmp(wi.y1, wi.y2, r, wi.y2, 1); r += dirY) {
      int co =  costs[r * dim_x + b1]+1;
      sum = sum+co, mx = std::max(mx, co);
    }
    for (int c = b1+dirX; myCmp(wi.x1, wi.x2, c, wi.x2, 1); c += dirX) {
      int co = costs[wi.y2 * dim_x + c]+1;
      sum = sum+co, mx = std::max(mx, co);
    }
    if (mx < bestMax) {
      best = make_point(b1, wi.y1);
      bestMax = mx, bestSum = sum;
    }
    else if (mx == bestMax && sum < bestSum) {
      best = make_point(b1, wi.y1);
      bestMax = mx, bestSum = sum;
    }
    path_t good = make_path(st, end, make_point(b1, wi.y1), sum, mx);
    #pragma omp critical { myPaths.push_back(good); }
  }
}

void tryVerticals(wire_t &wi, int dirX, int dirY,
                    int bestMax, int bestSum, cost_t *costs,
                    vector<path_t> &myPaths, int dim_x, int dim_y)
{
  for (int b1 = wi.y1 + dirY; myCmp(wi.y1, wi.y2, b1, wi.y2, 1); b1 += dirY) {
    int sum = 0;
    int mx = 0;
    for (int c = wi.y1; myCmp(wi.y1, wi.y2, c, b1, 0); c += dirY) {
      int co = costs[c * dim_x + wi.x1]+1;
      sum = sum+co, mx = std::max(mx, co);
    }
    for (int r = wi.x1; myCmp(wi.x1, wi.x2, r, wi.x2, 1); r += dirX) {
      int co = costs[b1 * dim_x + r]+1;
      sum = sum+co, mx = std::max(mx, co);
    }
    for (int c = b1+dirY; myCmp(wi.y1, wi.y2, c, wi.y2, 1); c += dirY) {
      int co = costs[c * dim_x + wi.x2]+1;
      sum = sum+co, mx = std::max(mx, co);
    }
    if (mx < bestMax) {
      best = make_point(wi.x1, b1);
      bestMax = mx, bestSum = sum;
    }
    else if (mx == bestMax && sum < bestSum) {
      best = make_point(wi.x1, b1);
      bestMax = mx, bestSum = sum;
    }
    path_t good = make_path(st, end, make_point(b1, wi.y1), sum, mx);
    #pragma omp critical { myPaths.push_back(good); }
  }
}

void updateWires(int dim_x, int dim_y, cost_t* costs,
                 int num_of_wires, int num_of_threads,
                 wire_t* wires, path_t* paths, double SA_prob,
                 int& randhits)
{
  int w;
  // int numProcs = omp_get_num_procs();
  omp_set_num_threads(num_of_threads);
  #pragma omp parallel for default(shared) private(w) schedule(dynamic)
  for (w = 0; w < num_of_wires; ++w) {
    wire_t& wi = wires[w];
    int bestMax = paths[w].mx;
    int bestSum = paths[w].sum;
    point best = paths[w].bend1;
    int dirX = (wi.x1 < wi.x2) ? 1 : -1;
    int dirY = (wi.y1 < wi.y2) ? 1 : -1;
    point st = make_point(wi.x1, wi.y1);
    point end = make_point(wi.x2, wi.y2);
    std::vector<path_t> myPaths;
    path_t p = paths[w];
    writeCost(p, -1, costs);  // undo previous path, critical

    // consider paths going horizontal first
    tryHorizontals(wi, dirX, dirY, bestMax,
      bestSum, costs, myPaths, dim_x, dim_y);

    // consider paths going vertical first
    tryVerticals(wi, dirX, dirY, bestMax,
      bestSum, costs, myPaths, dim_x, dim_y);

    // rng
    double randnum = (rand() / (double) RAND_MAX);
    if (randnum < SA_prob) {
      __sync_fetch_and_add(randhits, 1);
      int i = rand() % myPaths.size();
      p = myPaths[i];
    }
    else
      p = make_path(st, end, best, bestMax, bestSum);

    paths[w] = p;
    writeCost(p, 1, costs);  // update cost array
  }
}

int main(int argc, const char *argv[]) {
  using namespace std::chrono;
  typedef std::chrono::high_resolution_clock Clock;
  typedef std::chrono::duration<double> dsec;

  auto init_start = Clock::now();
  double init_time = 0;

  _argc = argc - 1;
  _argv = argv + 1;

  const char *input_filename = get_option_string("-f", NULL);
  int num_of_threads = get_option_int("-n", 1);
  double SA_prob = get_option_float("-p", 0.1f);
  int SA_iters = get_option_int("-i", 5);

  int error = 0;

  if (input_filename == NULL) {
    printf("Error: You need to specify -f.\n");
    error = 1;
  }

  if (error) {
    show_help(argv[0]);
    return 1;
  }

  printf("Number of threads: %d\n", num_of_threads);
  printf("Probability parameter for simulated annealing: %lf.\n", SA_prob);
  printf("Number of simulated annealing iterations: %d\n", SA_iters);
  printf("Input file: %s\n", input_filename);

  FILE *input = fopen(input_filename, "r");

  if (!input) {
    printf("Unable to open file: %s.\n", input_filename);
    return 1;
  }

  int dim_x, dim_y;
  int num_of_wires;

  fscanf(input, "%d %d\n", &dim_x, &dim_y);
  fscanf(input, "%d\n", &num_of_wires);

  wire_t *wires = (wire_t *)calloc(num_of_wires, sizeof(wire_t));
  /* Read the grid dimension and wire information from file */
  for (int i = 0; i < num_of_wires; ++i) {
    int x1, y1, x2, y2;
    fscanf(input, "%d %d %d %d", &x1, &y1, &x2, &y2);
    wire_t w;
    w.x1 = x1, w.y1 = y1;
    w.x2 = x2, w.y2 = y2;
    wires[i] = w;
  }

  cost_t *costs = (cost_t *)calloc(dim_x * dim_y, sizeof(cost_t));
  /* Initialize cost matrix */

  /* Initailize additional data structures needed in the algorithm */
  path_t *bestPaths = (path_t *)calloc(num_of_wires, sizeof(path_t));

  // initial path guess
  for (int i = 0; i < num_of_wires; ++i) {
    wire_t& w = wires[i];
    path_t path;
    path.start = make_point(w.x1, w.y1);
    path.end = make_point(w.x2, w.y2);
    int dirX = (w.x1 < w.x2) ? 1 : -1;
    int dirY = (w.y1 < w.y2) ? 1 : -1;
    if (w.y2 != w.y1)
      path.bend1 = make_point(w.x1, w.y2);
    else
      path.bend1 = make_point(-1, -1);


    for (int r = w.y1; myCmp(w.y1, w.y2, r, w.y2, 1); r += dirY) {
      ++costs[r * dim_x + w.x1];
      path.sum += costs[r * dim_x + w.x1];
      path.mx = std::max(path.mx, costs[r * dim_x + w.x1]);
    }

    for (int c = w.x1+dirX; myCmp(w.x1, w.x2, c, w.x2, 1); c += dirX) {
      ++costs[w.y2 * dim_x + c];
      path.sum += costs[w.y2 * dim_x + c];
      path.mx = std::max(path.mx, costs[w.y2 * dim_x + c]);
    }
    // printf("%d %d\n", path.sum, path.mx);
    bestPaths[i] = path;
  }



  init_time += duration_cast<dsec>(Clock::now() - init_start).count();
  printf("Initialization Time: %lf.\n", init_time);

  auto compute_start = Clock::now();
  double compute_time = 0;

  /**
   * Implement the wire routing algorithm here
   * Feel free to structure the algorithm into different functions
   * Don't use global variables.
   * Use OpenMP to parallelize the algorithm.
   */

  // WIRE LOOP
  int randhits = 0;
  for (int iter = 0; iter < SA_iters; ++iter) {
    updateWires(dim_x, dim_y, costs, num_of_wires, num_of_threads,
                wires, bestPaths, SA_prob, randhits);
  }

  compute_time += duration_cast<dsec>(Clock::now() - compute_start).count();
  printf("Computation Time: %lf.\n", compute_time);

  /* Write wires and costs to files */

  char *inputFileName = strdup(input_filename);
  char* inFile = strtok(inputFileName, "/");
  inFile = strtok(NULL, "/");
  inFile = strtok(NULL, "/");
  inFile[strlen(inFile)-4] = '\0';
  char buf[0x100];
  snprintf(buf, sizeof(buf), "output_%s_%d.txt", inFile, num_of_threads);
  FILE *wireOutFile = fopen(buf, "w");

  fprintf(wireOutFile, "%d %d\n", dim_x, dim_y);
  fprintf(wireOutFile, "%d\n", num_of_wires);
  for (int w = 0; w < num_of_wires; ++w) {
    path_t p = bestPaths[w];
    int b2x = -1, b2y = -1;
    if (p.bend1.x != -1 && (p.bend1.x != p.end.x && p.bend1.y != p.end.y)) {
      if (p.start.x != p.bend1.x)
        b2x = p.bend1.x, b2y = p.end.y;
      else
        b2x = p.end.x, b2y = p.bend1.y;
    }

    if (p.bend1.x == -1)
      fprintf(wireOutFile, "%d %d %d %d\n", p.start.x, p.start.y, p.end.x, p.end.y);
    else if (b2x == -1)
      fprintf(wireOutFile, "%d %d %d %d %d %d\n", p.start.x, p.start.y, p.bend1.x,
        p.bend1.y, p.end.x, p.end.y);
    else
      fprintf(wireOutFile, "%d %d %d %d %d %d %d %d\n", p.start.x, p.start.y, p.bend1.x,
        p.bend1.y, b2x, b2y, p.end.x, p.end.y);
  }
  fclose(wireOutFile);

  char buf2[0x100];
  snprintf(buf2, sizeof(buf2), "costs_%s_%d.txt", inFile, num_of_threads);
  FILE *costOutFile = fopen(buf2, "w");

  fprintf(costOutFile, "%d %d\n", dim_x, dim_y);
  int mymax = 0;
  for (int y = 0; y < dim_y; ++y) {
    for (int x = 0; x < dim_x; ++x) {
      int co = costs[y * dim_x + x];
      fprintf(costOutFile, "%d ", co);
      mymax = std::max(mymax, co);
    }
    fprintf(costOutFile, "\n");
  }
  fclose(costOutFile);
  printf("cost graph max: %d\n", mymax);

  mymax = 0;
  int mysum = 0;
  for (int w = 0 ; w < num_of_wires; ++w) {
    path_t p = bestPaths[w];
    mymax = std::max(mymax, p.mx);
    mysum = std::max(mysum, p.sum);
  }
  printf("path max:       %d\n", mymax);
  printf("path sum max:   %d\n", mysum);
  printf("# of randoms:   %d\n", randhits);

  return 0;
};
