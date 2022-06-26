// #include <iostream>
// #include <cstdio>
#include <bits/stdc++.h>  // includes all std files
using namespace std;      // unpacks the std namespace into the local namespace

int d = 5;
int x = 5;

namespace Henry {
    int d = 0;
    int x = 1;
}

int square(int x)
{
    return x * x;
}

int main()
{
    cout << square(x) << '\n';            // 25
    cout << d + x << '\n';                // 10
    cout << Henry::d + Henry::x << '\n';  // 1
    cout << "Hello world!";               // Hello world!
    return 0;
}
