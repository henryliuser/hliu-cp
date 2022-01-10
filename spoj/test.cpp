#include <bits/stdc++.h>
using namespace std;

struct T {
    unordered_map<string, map<int, string>> m;
    void set(string key, string value, int timestamp) {
      m[key].insert({ timestamp, value });
    }
    string get(string key, int timestamp) {
      auto it = m[key].upper_bound(timestamp);
      return it == m[key].begin() ? "" : prev(it)->second;
    }
};

int main() {
    T t;
    t.set("foo", "bar", 1);
    cout << t.get("foo", 1) << "\n";
}
