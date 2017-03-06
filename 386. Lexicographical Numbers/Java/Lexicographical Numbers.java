public class Solution {
    public List<Integer> lexicalOrder(int n) {
        class Utils {
            void dfs(List<Integer> result, int current, int n) {
                if (current > n) {
                    return;
                }
                result.add(current);
                current *= 10;
                for (int i = 0; i < 10; i++) {
                    if (current + i <= n) {
                        dfs(result, current + i, n);
                    }
                }
            }
        }
        List<Integer> result = new ArrayList<>();
        Utils utils = new Utils();
        for (int i = 1; i < 10; i++) {
            utils.dfs(result, i, n);
        }
        return result;
    }
}