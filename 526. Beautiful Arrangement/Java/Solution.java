public class Solution {
    public int countArrangement(int N) {
        class Utils {
            int result = 0;

            void arrangement(int index, boolean[] used) {
                if (index == used.length) {
                    result++;
                    return;
                }
                for (int i = 1; i < used.length; i++) {
                    if (!used[i] && (i % index == 0 || index % i == 0)) {
                        used[i] = true;
                        arrangement(index + 1, used);
                        used[i] = false;
                    }
                }
            }
        }
        Utils utils = new Utils();
        utils.arrangement(1, new boolean[N + 1]);
        return utils.result;
    }
}