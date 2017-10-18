class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> needs;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (needs.find(num) != needs.end()) {
                return vector<int> {needs[num], i};
            }
            needs.insert({target - num, i});
        }
    }
};