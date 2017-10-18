class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        class Utils {
            boolean win(int choosed, Map<Integer, Boolean> memory, int total) {
                if (memory.containsKey(choosed)) {
                    return memory.get(choosed);
                }
                for (int i = 1; i <= maxChoosableInteger; i++) {
                    if ((choosed & (1 << i)) == 0) {
                        if (total <= i || !win(choosed | (1 << i), memory, total - i)) {
                            memory.put(choosed, true);
                            return true;
                        }
                    }
                }
                memory.put(choosed, false);
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
        return utils.win(0, new HashMap<>(), desiredTotal);
    }
}