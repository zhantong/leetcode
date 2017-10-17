class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); i++) {
            int first = 0;
            int second = i - 1;
            while (first < second) {
                if (nums[first] + nums[second] > nums[i]) {
                    result += second - first;
                    second--;
                } else {
                    first++;
                }
            }
        }
        return result;
    }
};