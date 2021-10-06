#include <bits/stdc++.h>
using namespace std;

int main() {
    int dim_x = 5, dim_y = 5;
    vector<vector<int>> costs = {
        {1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 0, 1 ,1 , 0},
        {1,1,2,2,1},
        {0,0,1,1,0}
    };
    std::vector<std::vector<int>> sumHori(dim_y, std::vector<int>(dim_x+1));
    std::vector<std::vector<int>> sumVert(dim_y+1, std::vector<int>(dim_x));
    for (int i = 0; i < dim_y; ++i) {
        for (int j = 1; j <= dim_x; ++j) {
          sumHori[i][j] = sumHori[i][j-1] + costs[i][j-1];
          printf("%d ", sumHori[i][j]);
        }
        printf("\n");
    }

}
