class Solution {
public:
    int jump(vector<int> &nums) {
        int result = 0;
        int index = 0;
        int current = 0;
        int next = 0;
        while (current < nums.size() - 1) {
            result++;
            while (index <= current) {
                next = max(next, index + nums[index]);
                index++;
            }
            current = next;
        }
        return result;
    }
};