public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>());
        for (int i = 0; i < nums.length; i++) {
            List<List<Integer>> newResult = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                for (List<Integer> item : result) {
                    List<Integer> newItem = new ArrayList<>(item);
                    newItem.add(j, nums[i]);
                    newResult.add(newItem);
                }
            }
            result = newResult;
        }
        return result;
    }
}