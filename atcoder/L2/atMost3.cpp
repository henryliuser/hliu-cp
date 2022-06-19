#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

int main() {
    printf("298\n");
    for (int i = 1; i < 100; ++i)
        printf("%d ", i);
    for (int i = 100; i < 10000; i += 100)
        printf("%d ", i);
    for (int i = 10000; i <= 1000000; i += 10000)
        printf("%d ", i);
}
