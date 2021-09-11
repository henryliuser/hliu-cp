// pq n log n (92 ms)  because pq implemented with array
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int N = heights.size();
        priority_queue<int> pq;
        unsigned long long brickSum = 0;
        for (int i = 0; i < N-1; ++i) {
            int a = heights[i];
            int b = heights[i+1];
            if (a >= b) continue;
            int j = b-a;
            pq.push(-j);
            if (pq.size() > ladders) {
                brickSum -= pq.top();
                pq.pop();
            }
            if (brickSum > bricks)
                return i;
        }
        return N-1;
    }
};


// multiset n log n (244 ms)  because multiset<T> implemented with RB tree
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        unsigned long long total = 0;
        unsigned long long topSum = 0;
        int N = heights.size();
        multiset<int> topDiff;
        for (int i = 0; i < N-1; ++i) {
            int a = heights[i];
            int b = heights[i+1];
            if (a >= b) continue;
            int j = b-a;
            total += j;
            if (topDiff.size() < ladders) {
                topDiff.insert(j);
                topSum += j;
            }
            else if (ladders != 0) {
                auto topMin = topDiff.begin();
                if (j > *topMin) {
                    topSum -= *topMin;
                    topDiff.erase(topMin);
                    topDiff.insert(j);
                    topSum += j;
                }
            }
            if (total - topSum > bricks)
                return i;
        }
        return N-1;
    }
};


// bad binary search n log n
class Solution {
public:
    int N, B, L;
    bool canReach(int h, vector<int>& heights) {
        vector<int> jumps;
        for (int z = 0; z < h; ++z) {
            int a = heights[z], b = heights[z+1];
            if (a < b) jumps.push_back(b-a);
        }
        int J = jumps.size();
        sort(jumps.begin(), jumps.end());
        unsigned long long total = 0, lad = 0;
        for (int z = J-1; z >= 0; --z) {
            int j = jumps[z];
            if (J-z <= L)
                lad += j;
            total += j;
        }
        return J <= L || total - lad <= B;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        N = heights.size();
        B = bricks, L = ladders;
        int lo = 0, hi = N-1;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (canReach(mid, heights))
                lo = mid;
            else
                hi = mid-1;
        }
        return lo;
    }
};
