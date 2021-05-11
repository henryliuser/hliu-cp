int maxVolume(vector<int>& start, vector<int>& duration, vector<int>& volume) {
    int N = start.size();
    priority_queue<pair<int, int>> pq; // end time, volume
    vector<vector<int>> v;
    for (int z = 0; z < N; z++) {
        v.push_back( {start[z], duration[z], volume[z]} );
    }
    sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    int cur = 0;
    for (int z = 0; z < N; z++) {
        while (pq.size() && -pq.top().first < v[z][0]) {
            cur = max(cur, pq.top().second);
            pq.pop();
        }
        pq.push(-{v[z][0] - v[z][1], cur+v[z][2]}); // sort increasing
    }
    while (pq.size()) {
        cur = max(cur, pq.top().second);
        pq.pop();
    }
    return cur;
}
