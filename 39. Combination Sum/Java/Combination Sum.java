public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        class Utils {
            void combination(int[] candidates, List<List<Integer>> result, List<Integer> current, int start, int left) {
                if (left == 0) {
                    result.add(new ArrayList<>(current));
                } else {
                    for (int i = start; i < candidates.length; i++) {
                        int candidate = candidates[i];
                        if (candidate <= left) {
                            current.add(candidate);
                            combination(candidates, result, current, i, left - candidate);
                            current.remove(current.size() - 1);
                        }
                    }
                }
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.combination(candidates, result, new ArrayList<>(), 0, target);
        return result;
    }
}