class Solution {
public:
    // count number of correct positions
    int minSwaps(string s) {
        int count[2] = {0,0};
        int zfe = 0, ofe = 0;
        for (int z = 0; z < s.size(); z++) {
            char& c = s[z];
            ofe += (z%2==0 && c=='0') + (z%2==1 && c=='1');
            zfe += (z%2==0 && c=='1') + (z%2==1 && c=='0');
            count[0] += (c=='0');
            count[1] += (c=='1');
        }
        if (abs(count[0] - count[1]) > 1) return -1;
        if (zfe % 2 == 1) zfe = INT_MAX;
        if (ofe % 2 == 1) ofe = INT_MAX;
        return min(zfe/2, ofe/2);
    }
};
