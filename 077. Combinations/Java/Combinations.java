public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        class Utils {
            void comb(List<List<Integer>> result, List<Integer> current, int start, int n, int k) {
                if (k == 0) {
                    result.add(new ArrayList<>(current));
                } else {
                    for (int i = start; i <= n; i++) {
                        current.add(i);
                        comb(result, current, i + 1, n, k - 1);
                        current.remove(current.size() - 1);
                    }
                }
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.comb(result, new ArrayList<>(), 1, n, k);
        return result;
    }
}