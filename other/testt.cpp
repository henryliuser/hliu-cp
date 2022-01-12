#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    while (b)
        swap(a %= b, b);
    return a;
}

int main() {
    vector<int> A = {2,6,5,3};
    cout << gcd(122, 427);

}
