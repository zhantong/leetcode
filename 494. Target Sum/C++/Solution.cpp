class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int sumNums = 0;
        for (auto &num : nums) {
            sumNums += num;
        }
        if (S > sumNums || S < -sumNums) {
            return 0;
        }
        vector<int> map(2 * sumNums + 1);
        map[sumNums] = 1;
        for (auto num : nums) {
            vector<int> newMap(2 * sumNums + 1);
            for (int i = 0; i < 2 * sumNums + 1; i++) {
                if (map[i] != 0) {
                    newMap[i + num] += map[i];
                    newMap[i - num] += map[i];
                }
            }
            map = newMap;
        }
        return map[sumNums + S];
    }
};