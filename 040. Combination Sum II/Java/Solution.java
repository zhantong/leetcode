public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        class Utils {
            void combination(int[] candidates, int target, int start, List<List<Integer>> result, List<Integer> current) {
                if (target < 0) {
                    return;
                }
                if (target == 0) {
                    result.add(new ArrayList<>(current));
                }
                for (int i = start; i < candidates.length; i++) {
                    if (i > start && candidates[i] == candidates[i - 1]) {
                        continue;
                    }
                    current.add(candidates[i]);
                    combination(candidates, target - candidates[i], i + 1, result, current);
                    current.remove(current.size() - 1);
                }
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(candidates);
        Utils utils = new Utils();
        utils.combination(candidates, target, 0, result, new ArrayList<>());
        return result;
    }
}