class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int low = 1;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int &num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            if (count <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};