using ll = long long;

ll modPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

unordered_set<ll> rabinKarp(vector<int>& src, int m, int b, ll q)
{
    ll t = 0, d = 1 << b;
    ll h = modPow(2, b*m-b, q);
    unordered_set<ll> hashes;
    for (int i = 0; i < m; ++i) {
        t = (d * t + src[i]) % q;
    }
    hashes.insert(t);  // calculate first hash
    for (int i = m; i < src.size(); ++i) {
        t = (d * (t - src[i-m] * h) + src[i]) % q;
        hashes.insert(t);  // rolling hash
    }
    return hashes;
}
