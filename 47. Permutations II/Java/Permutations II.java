public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>());
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            List<List<Integer>> currentResult = new ArrayList<>();
            for (List<Integer> item : result) {
                for (int j = 0; j <= i; j++) {
                    if (j > 0 && num == item.get(j - 1)) {
                        break;
                    }
                    List<Integer> temp = new ArrayList<>(item);
                    temp.add(j, num);
                    currentResult.add(temp);
                }
            }
            result = currentResult;
        }
        return result;
    }
}