/**
 * Parallel VLSI Wire Routing via OpenMP
 * Henry Liu (henryli2), Annie Xu (ajxu)
 */

#ifndef __WIREOPT_H__
#define __WIREOPT_H__

#include <omp.h>

typedef struct {
    int x, y;
} point;

point make_point(int a, int b) {
    point p;
    p.x = a, p.y = b;
    return p;
}

typedef struct {
    int x1, y1, x2, y2;
} wire_t;

typedef struct {
    int sum = 0;
    int mx = 0;
    point start;
    point bend1;
    point end;
} path_t;

path_t make_path(point s, point e, point b, int sm, int m)
{
  path_t p;
  p.start = s, p.end = e, p.bend1 = b;
  p.sum = sm, p.mx = m;
  return p;
}

typedef int cost_t;

const char *get_option_string(const char *option_name,
                              const char *default_value);
int get_option_int(const char *option_name, int default_value);
float get_option_float(const char *option_name, float default_value);

void updateWires(int dim_x, int dim_y, cost_t* costs, wire_t* wires, path_t* paths);

#endif
