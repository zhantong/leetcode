public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        class Utils {
            void combination(List<List<Integer>> result, List<Integer> current, int start, int k, int n) {
                if (k == 0 && n == 0) {
                    result.add(new ArrayList<>(current));
                } else if (k > 0 && n > 0) {
                    for (int i = start; i < 10; i++) {
                        current.add(i);
                        combination(result, current, i + 1, k - 1, n - i);
                        current.remove(current.size() - 1);
                    }
                }
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.combination(result, new ArrayList<>(), 1, k, n);
        return result;
    }
}