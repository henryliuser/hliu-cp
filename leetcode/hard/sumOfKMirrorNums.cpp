using ll = unsigned long long;
class Solution {
public:
    vector<ll> pows;
    bool isPal(string &d) {
        int len = d.size();
        for (int i = 0; i < len/2; ++i)
            if (d[i] != d[len-i-1])
                return false;
        return true;
    }
    ll toLL(vector<int> &c) {
        ll res = 0;
        int dig = c.size();
        for (int i = 0; i < dig; ++i)
            res += pows[i] * c[i];
        return res;

    }
    void nextPal(vector<int> &c, int k) {
        int dig = c.size();
        int i = (dig/2) - (dig%2==0);
        int j = dig - i - 1;
        if (i == j && c[i] < k-1) {
            ++c[i];
            return;
        }
        while (i>=0 && c[i] == k-1) {
            j = dig-i-1;
            c[i--] = 0;
            c[j] = 0;
        }
        if (i != -1) {
            j = dig-i-1;
            ++c[i]; ++c[j];
        }
        else {
            c.push_back(1);
            c[0] = 1;
            for (int z = 1; z < dig; ++z)
                c[z] = 0;
        }

    }
    long long kMirror(int k, int n) {
        int L = ceil(log(1e18) / log(k)) + 1;
        pows.assign(L+1, 1);
        for (int i = 1; i <= L; ++i)
            pows[i] = pows[i-1]*k;
        ll ans = 0;
        vector<int> curr = {1};
        while (n) {
            ll y = toLL(curr);
            string ss = to_string(y);
            if (isPal(ss)) {
                --n;
                ans += y;
            }
            nextPal(curr, k);
        }
        return ans;
    }
};
