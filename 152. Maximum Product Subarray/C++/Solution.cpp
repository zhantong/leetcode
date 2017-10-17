class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxHere = nums[0];
        int minHere = nums[0];
        int maxSoFar = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            maxHere *= num;
            minHere *= num;
            int tempMaxHere = max(max(maxHere, minHere), num);
            minHere = min(min(maxHere, minHere), num);
            maxHere = tempMaxHere;
            maxSoFar = max(maxHere, maxSoFar);
        }
        return maxSoFar;
    }
};