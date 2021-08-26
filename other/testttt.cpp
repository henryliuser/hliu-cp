#include <bits/stdc++.h>
using namespace std;

int main() {
    int dp[100000];
    dp[0] = 1;
    dp[1] = 2;
    int count = 2;
    for(int i = 2; i < 1000000; i++){
        dp[i] = dp[i-1] + dp[i-2];
        if(dp[i] > 4000000){
            break;
        }
        if(dp[i]%2 == 0){
            count += dp[i];
        }
    }
    cout<<count;
    
}
