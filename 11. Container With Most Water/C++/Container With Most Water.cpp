class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxWater = 0;
        int low = 0;
        int high = height.size() - 1;
        while (low < high) {
            int tall = min(height[low], height[high]);
            maxWater = max(maxWater, tall * (high - low));
            while (low < high && height[low] <= tall) {
                low++;
            }
            while (low < high && height[high] <= tall) {
                high--;
            }
        }
        return maxWater;
    }
};