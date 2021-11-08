#include <bits/stdc++.h>
using namespace std;

int a, b, t;
int main() {
    cin >> a >> b;
    int t = abs(a-b);
    if (a - t - 1 >= 0) printf("%d\n", a-t-1);
    else printf("%d\n", a+t+1);
}
