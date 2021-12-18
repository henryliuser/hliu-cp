#include <bits/stdc++.h>
using namespace std;

int main() {

    int N; cin >> N;
    vector<int> nums(N);
    for (int z = 0; z < N; z++)
        cin >> nums[z];

    int ans = 0;
    for (int z = 0; z < N; z++) {
        int b = nums[z];
        int left = 0, right = 0;
        for (int l = z-1; l >= 0; --l) {
            if (nums[l] <= nums[l+1]) left++;
            else break;
        }
        for (int r = z+1; r < N; ++r) {
            if (nums[r] <= nums[r-1]) right++;
            else break;
        }
        ans = max(ans, left + right + 1);
    }
    cout << ans << endl;
}
