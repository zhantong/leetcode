public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < 1 << nums.length; i++) {
            List<Integer> current = new ArrayList<>();
            for (int j = 0; j < nums.length; j++) {
                if ((i & 1 << j) != 0) {
                    current.add(nums[j]);
                }
            }
            result.add(current);
        }
        return result;
    }
}