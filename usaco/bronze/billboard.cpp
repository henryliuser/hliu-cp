#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    // O(1) math
    struct Rect {
        int x1, y1, x2, y2;
        int area() { return (x2-x1) * (y2-y1); }
    };

    auto intersect = [] (Rect& a, Rect&b) {
        int xOverlap = max(0, min(a.x2, b.x2) - max(a.x1, b.x1) );
        int yOverlap = max(0, min(a.y2, b.y2) - max(a.y1, b.y1) );
        return xOverlap * yOverlap;
    };

    Rect a, b, c;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    int ans = a.area() + b.area();
    ans -= intersect(a, c) + intersect(b, c);
    cout << ans << endl;



    // O(N)
    // vector<vector<bool> > grid(2001, vector<bool>(2001, false));
    //
    // for (int z = 0; z < 3; z++) {
    //     int p[4] = {0, 0, 0, 0};
    //     for (int a = 0; a < 4; a++) {
    //         cin >> p[a]; p[a] += 1000;
    //     }
    //     for (int r = p[3]; r > p[1]; r--) {
    //         for (int c = p[0]; c < p[2]; c++)
    //             if (z == 2) grid[r][c] = false;
    //             else grid[r][c] = true;
    //     }
    // }
    // int ans = 0;
    // for (int r = 0; r < 2001; r++) {
    //     for (int c = 0; c < 2001; c++) {
    //         if (grid[r][c] == true) ans++;
    //     }
    // }
    // cout << ans;



}
