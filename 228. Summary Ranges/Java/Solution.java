public class Solution {
    public List<String> summaryRanges(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<>();
        }
        int start = 0;
        int offset = nums[0];
        List<String> result = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if (i + offset != nums[i]) {
                if (start == i - 1) {
                    result.add("" + nums[start]);
                } else {
                    result.add(nums[start] + "->" + nums[i - 1]);
                }
                offset = nums[i] - i;
                start = i;
            }
        }
        if (start == nums.length - 1) {
            result.add("" + nums[start]);
        } else {
            result.add(nums[start] + "->" + nums[nums.length - 1]);
        }
        return result;
    }
}