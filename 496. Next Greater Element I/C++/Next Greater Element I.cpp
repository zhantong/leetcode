class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        if (findNums.empty()) {
            vector<int> temp;
            return temp;
        }
        int numMax = *max_element(nums.begin(), nums.end());
        int map[numMax + 1]{0};
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        vector<int> result(findNums.size());
        for (int i = 0; i < findNums.size(); i++) {
            int currentNum = findNums[i];
            if (currentNum > numMax) {
                result[i] = -1;
            } else {
                int currentIndex = map[currentNum] + 1;
                while (currentIndex < nums.size()) {
                    if (nums[currentIndex] > currentNum) {
                        result[i] = nums[currentIndex];
                        break;
                    }
                    currentIndex++;
                }
                if (currentIndex == nums.size()) {
                    result[i] = -1;
                }
            }
        }
        return result;
    }
};