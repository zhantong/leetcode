public class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        class Utils {
            void subsequences(int[] nums, Set<List<Integer>> result, List<Integer> current, int start) {
                if (current.size() >= 2) {
                    result.add(new ArrayList<>(current));
                }
                for (int i = start; i < nums.length; i++) {
                    if (current.isEmpty() || current.get(current.size() - 1) <= nums[i]) {
                        current.add(nums[i]);
                        subsequences(nums, result, current, i + 1);
                        current.remove(current.size() - 1);
                    }
                }
            }
        }
        Set<List<Integer>> resultSet = new HashSet<>();
        Utils utils = new Utils();
        utils.subsequences(nums, resultSet, new ArrayList<>(), 0);
        return new ArrayList<>(resultSet);
    }
}