#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int NOT(int x) {
    int res = 0;
    int y = log2(x);
    for (int b = y; b >= 0; --b) {
        if (x & (1 << b)) continue;
        else res |= (1<<b);
    }
    return res;
}

int main() {
    int x = 10;
    cout << NOT(x) << '\n';

}
