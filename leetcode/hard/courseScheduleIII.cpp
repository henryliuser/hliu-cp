class Solution {
public:
    // COURTESY OF sgallivan ON LEETCODE
    int scheduleCourse(vector<vector<int>>& courses) {
        int t = 0; // time
        priority_queue<int> pq; // courses we're taking
        // in order from longest to shortest;

        // sort courses by increasing end times
        sort(courses.begin(), courses.end(),
             [] (auto& a, auto& b) {return a[1] < b[1];});

        for (auto& c : courses) {
            int dur = c[0], end = c[1];
            if (t + dur <= end) { // if it fits, take it!
                t += dur;
                pq.push(dur);
            }
            else if (!pq.empty() && dur < pq.top()) {
                // or, if it's a better fit than our current
                // longest course, "swap" them
                t += dur - pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};
