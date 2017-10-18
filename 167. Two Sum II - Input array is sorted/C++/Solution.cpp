class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int twoSum = numbers[i] + numbers[j];
            if (twoSum == target) {
                break;
            }
            if (twoSum > target) {
                j--;
            } else {
                i++;
            }
        }

        return vector<int> {i + 1, j + 1};
    }
};