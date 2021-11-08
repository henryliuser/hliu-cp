#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    multiset<int> m;
    while (N--) {
        char c; int x;
        cin >> c >> x;
        if (c == '?') {
            cout << m.count(x) << endl;
            continue;
        }
        string s;
        while (x > 9) {
            int q = (x%10) % 2;
            s.push_back(q+'0');
            x /= 10;
        }
        s.push_back(((x%10) % 2)+'0');
        reverse(s.begin(), s.end());
        int y = stoi(s);
        // cout << "y: " << y << endl;
        if (c == '+')
            m.insert(y);
        if (c == '-')
            m.erase(m.find(y));
    }
}
