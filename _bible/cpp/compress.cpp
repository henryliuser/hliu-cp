// in-place coordinate compression
int compress(vector<int> &A) {
    int uq = 0;
    map<int,int> cmprs;
    for (int x : A) cmprs[x];
    for (auto &[k,v] : cmprs) v = uq++;
    for (int &x : A) x = cmprs[x];
    return uq;
}
