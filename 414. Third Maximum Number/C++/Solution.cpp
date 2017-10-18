class Solution {
public:
    int thirdMax(vector<int> &nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (auto &num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        if (third == LONG_MIN) {
            return (int) first;
        }
        return (int) third;
    }
};