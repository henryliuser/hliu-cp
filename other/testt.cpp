#include <bits/stdc++.h>
using namespace std;

uint64_t negabinary(int64_t num) {
    const uint64_t mask = 0xAAAAAAAAAAAAAAAA;
    return (mask + num) ^ mask;
}

int main() {
    cout << negabinary(-1) << endl;
}
