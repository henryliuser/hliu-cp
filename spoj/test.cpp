#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {0,1,2,3,4,5,6,7};
    vector<bool> seen(3)[2];
    int lo = 0, hi = 7;
    while (lo < hi) {
        int mid = lo + ceil((hi-lo) / 2.0);
        if (mid <= 2) lo = mid;
        else hi = mid-1;
    }
    cout << lo << endl;



}
