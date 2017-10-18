class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums;
        }
        int a = nums[0];
        int b = nums[0];
        int countA = 0;
        int countB = 0;
        for (int num : nums) {
            if (num == a) {
                countA++;
            } else if (num == b) {
                countB++;
            } else if (countA == 0) {
                a = num;
                countA = 1;
            } else if (countB == 0) {
                b = num;
                countB = 1;
            } else {
                countA--;
                countB--;
            }
        }
        if (a == b) {
            return vector<int> {a};
        }
        vector<int> result;
        countA = 0;
        countB = 0;
        for (int num : nums) {
            if (a == num) {
                countA++;
            }
            if (b == num) {
                countB++;
            }
        }
        if (countA > nums.size() / 3) {
            result.push_back(a);
        }
        if (countB > nums.size() / 3) {
            result.push_back(b);
        }
        return result;
    }
};