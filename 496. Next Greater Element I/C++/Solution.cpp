class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        vector<int> result;
        if (findNums.empty()) {
            return result;
        }
        int numMax = *max_element(nums.begin(), nums.end());
        vector<int> map(numMax + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < findNums.size(); i++) {
            int currentNum = findNums[i];
            if (currentNum > numMax) {
                result.push_back(-1);
            } else {
                int currentIndex = map[currentNum] + 1;
                while (currentIndex < nums.size()) {
                    if (nums[currentIndex] > currentNum) {
                        result.push_back(nums[currentIndex]);
                        break;
                    }
                    currentIndex++;
                }
                if (currentIndex == nums.size()) {
                    result.push_back(-1);
                }
            }
        }
        return result;
    }
};