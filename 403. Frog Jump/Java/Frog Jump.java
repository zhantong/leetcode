public class Solution {
    public boolean canCross(int[] stones) {
        class Utils {
            boolean backTrace(int[] stones, int current, int length, Map<Long, Boolean> memory) {
                long key = current;
                key = (key << 32) | length;
                if (memory.containsKey(key)) {
                    return memory.get(key);
                }
                if (current == 0 && length == 1) {
                    memory.put(key, true);
                    return true;
                }
                if (current == 0) {
                    memory.put(key, false);
                    return false;
                }
                for (int i = current - 1; i >= 0; i--) {
                    int tempLength = stones[current] - stones[i];
                    if (tempLength < length - 1) {
                        continue;
                    }
                    if (tempLength > length + 1) {
                        memory.put(key, false);
                        return false;
                    }
                    if (backTrace(stones, i, tempLength, memory)) {
                        memory.put(key, true);
                        return true;
                    }
                }
                memory.put(key, false);
                return false;
            }
        }
        int last = stones[stones.length - 1];
        Map<Long, Boolean> memory = new HashMap<>();
        Utils utils = new Utils();
        for (int i = stones.length - 2; i >= 0; i--) {
            if (utils.backTrace(stones, i, last - stones[i], memory)) {
                return true;
            }
        }
        return false;
    }
}