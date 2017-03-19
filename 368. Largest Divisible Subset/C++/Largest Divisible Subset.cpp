class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        if (nums.size() == 0) {
            return vector<int>();
        }
        sort(nums.begin(), nums.end());
        vector<int> lengths(nums.size(), 1);
        vector<int> childs(nums.size(), -1);
        int maxLength = 0;
        int maxLengthIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && lengths[i] <= lengths[j]) {
                    lengths[i] = lengths[j] + 1;
                    childs[i] = j;
                    if (lengths[i] > maxLength) {
                        maxLength = lengths[i];
                        maxLengthIndex = i;
                    }
                }
            }
        }
        vector<int> result;
        int index = maxLengthIndex;
        while (index != -1) {
            result.push_back(nums[index]);
            index = childs[index];
        }
        return result;
    }
};