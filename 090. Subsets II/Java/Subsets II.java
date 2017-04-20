public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        class Utils {
            void subsets(int[] nums, List<List<Integer>> result, List<Integer> current, int start) {
                result.add(new ArrayList<>(current));
                for (int i = start; i < nums.length; i++) {
                    if (i == start || nums[i] != nums[i - 1]) {
                        current.add(nums[i]);
                        subsets(nums, result, current, i + 1);
                        current.remove(current.size() - 1);
                    }
                }
            }
        }
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.subsets(nums, result, new ArrayList<>(), 0);
        return result;
    }
}