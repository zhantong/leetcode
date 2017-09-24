class Solution {
    public int triangleNumber(int[] nums) {
        int result = 0;
        Arrays.sort(nums);
        for (int i = 2; i < nums.length; i++) {
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
}