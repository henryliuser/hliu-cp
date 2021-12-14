#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v(10000);
auto *av = new vector<atomic<int>>(10000);

void foo()
{
    for (int i = 0; i < 10000; ++i)
        ++v[i], ++(*av)[i];
}

int main() {
    cout << av << "\n";
    cout << &a << "\n";
    // vector<thread> t;
    // for (int i = 0; i < 10; ++i)
    //     t.push_back( thread(foo) );
    // for (auto &x : t)
    //     x.join();
    //
    // for (auto &x : *av)
    //     cout << x << "\n";

    // atomic<int> a = 15;
    // atomic<int> b = 16;
    // atomic<int> c = 17;
    // atomic_compare_exchange_strong(&a, &b, c);
    // cout << a << "\n";
}
