class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        int current = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                current++;
            }
            if (current == n) {
                return true;
            }
        }
        return false;
    }
};