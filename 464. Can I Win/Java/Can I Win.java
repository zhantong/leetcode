public class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        class Utils {
            int toKey(boolean[] choosed) {
                int result = 0;
                for (boolean item : choosed) {
                    result <<= 1;
                    if (item) {
                        result |= 1;
                    }
                }
                return result;
            }

            boolean win(boolean[] choosed, Map<Integer, Boolean> memory, int total) {
                int key = toKey(choosed);
                if (memory.containsKey(key)) {
                    return memory.get(key);
                }
                for (int i = 1; i < choosed.length; i++) {
                    if (!choosed[i]) {
                        choosed[i] = true;
                        if (total <= i || !win(choosed, memory, total - i)) {
                            memory.put(key, true);
                            choosed[i] = false;
                            return true;
                        }
                        choosed[i] = false;
                    }
                }
                memory.put(key, false);
                return false;
            }
        }
        if (desiredTotal == 0) {
            return true;
        }
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        Utils utils = new Utils();
        return utils.win(new boolean[maxChoosableInteger + 1], new HashMap<>(), desiredTotal);
    }
}