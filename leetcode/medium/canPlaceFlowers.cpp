class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int M = flowerbed.size();
        for (int z = 0; z < M; ++z) {
            if (flowerbed[z] == 0) {
                int l = z-1, r = z+1;
                if ((l < 0   || flowerbed[l] == 0) &&
                    (r >= M  || flowerbed[r] == 0)) {
                    --n;
                    flowerbed[z] = 1;
                }
            }
        }
        return n <= 0;
    }
};
