// https://codeforces.com/contest/1637/problem/D
// reduce reduce reduce. especially when it's explicitly a math question...
// C(a) given as sum( (a[i]+a[j])^2 )
// C(a) = sum( a[i]^2 + a[j]^2 + 2a[i]a[j] )
// = sum(a[i]^2) + sum(a[j]^2) + 2sum(a[i]a[j])
// let S = sum(a)
// C(a) = (n-1) sum(a[i]^2) + sum( a[i] * (S-a[i]) )
//      = (n-1) sum(a[i]^2) + sum( S*a[i] - a[i]*a[i] )
//      = (n-1) sum(a[i]^2) + S*sum(a[i]) - sum(a[i]^2)
//      = (n-2) sum(a[i]^2) + S^2
// C(a) + C(b) = (n-2) sum(a[i]^2+b[i]^2) + sum(a)^2 + sum(b)^2
// first term is constant, so we minimize [sum(a)^2 + sum(b)^2]
// W = sum(A) + sum(B)
// sum(B) = W - sum(A) at any point
// enumerate all possible values of sum(A) with knapsack
// to make impl easier, start with minSumA and add diff's from B
// then update answer using formula
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {

}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
