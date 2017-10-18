class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for (auto &num : nums) {
            if (num < first) {
                first = num;
            } else if (num < second && num > first) {
                second = num;
            } else if (num > second) {
                return true;
            }
        }
        return false;
    }
};