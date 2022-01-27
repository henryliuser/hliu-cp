#include <bits/stdc++.h>
using namespace std;

template<typename K, typename V>
class HashMap {
public:
    HashMap(int r) : mp(r), cap(r) {
        hsh = std::hash<K>{};
    }
    HashMap(int r, function<int(K)> f)
            : mp(r), hsh(f), cap(r) {}

    V &operator[](K key) {
        int idx = hsh(key) % cap;
        auto &chain = mp[idx];
        for (auto &t : chain)
            if (t.first == key)
                return t.second;
        pair<K,V> newEntry = {key, V{}};
        chain.push_back(newEntry);
        ++sz;
        return chain.back().second;
    }
    bool count(K key) {
        int idx = hsh(key) % cap;
        auto &chain = mp[idx];
        for (auto &t : chain)
            if (t.first == key)
                return true;
        return false;
    }
    unsigned int size() {
        return sz;
    }
private:
    unsigned int sz=0, cap;
    function<int(K)> hsh;
    vector<deque<pair<K,V>>> mp;
};

int sthash(string s) {
    int res = 0;
    for (char ch : s) {
        res += ch;
        res *= ch;
    }
    return res;
}

int main() {
    HashMap<string, int> mp(100);
    string s1 = "abcd";
    mp[s1] = 5;
    cout << mp[s1] << '\n';
    cout << mp.size() << '\n';
}
