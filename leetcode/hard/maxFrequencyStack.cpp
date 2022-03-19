// https://leetcode.com/problems/maximum-frequency-stack/
class FreqStack {
public:
    using ti = array<int, 3>;
    int c = 0;
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> st;
    multiset<ti> ms;
    FreqStack() {

    }

    void push(int val) {
        auto &s = st[val];
        if (cnt.count(val)) {
            int t = cnt[val];
            int j = s.top();
            ms.erase( ms.find( {t,j,val} ) );
        }
        s.push(c);
        ms.insert( {--cnt[val], c--, val} );
    }

    int pop() {
        auto it = ms.begin();
        int v = (*it)[2];
        int q = ++cnt[v];
        auto &s = st[v];
        ms.erase(it);
        s.pop();
        if (q) {
            int j = s.top();
            ms.insert( {q,j,v} );
        }
        else cnt.erase(v);
        return v;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
