class TweetCounts {
public:
    vector<int> ti = {60, 3600, 86400};
    map<string, int> d = { {"minute",0}, {"hour",1}, {"day",2} };
    unordered_map<string, map<int, multiset<int>>> mp[3];
    // 0:minute, 1:hour, 2:day
    TweetCounts() {}

    void recordTweet(string name, int time) {
        for (int i : {0,1,2}) {
            int t = time / ti[i];
            mp[i][name][t].insert(time);
        }
    }

    vector<int> getTweetCountsPerFrequency(string freq, string name, int startTime, int endTime) {
        vector<int> res;
        int j = d[freq];
        int t = startTime / ti[j];
        int e =   endTime / ti[j];
        auto &s = mp[j][name][t];
        auto itU = s.lower_bound(startTime);
        int sz = distance(s.end(), itU);
        res.push_back(sz);
        for (int i = t+1; i < e; ++i) {
            sz = mp[j][name][i].size();
            res.push_back(sz);
        }
        if (t == e) return res;
        auto &r = mp[j][name][e];
        itU = r.upper_bound(endTime);
        if (itU == begin(r)) sz = 0;
        else sz = distance(r.begin(), (--itU));
        res.push_back(sz);

        return res;
    }
};

int main() {
    
}
