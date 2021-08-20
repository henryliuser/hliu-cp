long long modPow(long long x, long long y, int m)
{
    if (y == 0) return 1;
    auto p = modPow(x, y / 2, m);
    return p * p * (y % 2 ? x : 1) % m;
}

unoredered_set<long long> rabinKarp(
    vector<int>& src,
    int m, int b, long long q)
{
    long long t = 0, d = 1 << b;
    long long h = modPow(2, b*m-b, q);
    unordered_set<long long> hashes;
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
