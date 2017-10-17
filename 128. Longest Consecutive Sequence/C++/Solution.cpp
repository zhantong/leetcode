class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int result = 0;
        for (int num : nums) {
            if (numsSet.find(num) != numsSet.end()) {
                int current = num;
                int count = 1;
                while (numsSet.find(current - 1) != numsSet.end()) {
                    numsSet.erase(current - 1);
                    current--;
                    count++;
                }
                current = num;
                while (numsSet.find(current + 1) != numsSet.end()) {
                    numsSet.erase(current + 1);
                    current++;
                    count++;
                }
                result = max(result, count);
            }
        }
        return result;
    }
};