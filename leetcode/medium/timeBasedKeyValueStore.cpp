class TimeMap {
public:
    unordered_map<string, map<int, string>> m;

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        if (it == m[key].begin()) return "";
        return prev(it)->second;
    }

    string get(string key, int timestamp) {  // bounds are whack
        auto& d = m[key];
        int N = d.size();
        int lo = 0, hi = N;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (d[mid].first <= timestamp) lo = mid + 1;
            else hi = mid;
        }
        if (hi == 0) return "";
        return d[lo-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
