class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int base = 1 << i;
            int countOnes = 0;
            for (int &num : nums) {
                if (base & num) {
                    countOnes++;
                }
            }
            result += countOnes * (nums.size() - countOnes);
        }
        return result;
    }
};