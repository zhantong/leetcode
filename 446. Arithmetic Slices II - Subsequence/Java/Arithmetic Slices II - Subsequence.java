public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int result = 0;
        int length = A.length;
        Map<Integer, Integer>[] memory = new Map[length];
        for (int i = 0; i < length; i++) {
            memory[i] = new HashMap<>();
            for (int j = 0; j < i; j++) {
                long diffInLong = (long) A[i] - A[j];
                if (diffInLong > Integer.MAX_VALUE || diffInLong < Integer.MIN_VALUE) {
                    continue;
                }
                int diff = (int) diffInLong;
                int current = 0;
                if (memory[j].containsKey(diff)) {
                    result += memory[j].get(diff);
                    current += memory[j].get(diff);
                }
                if (memory[i].containsKey(diff)) {
                    current += memory[i].get(diff);
                }
                memory[i].put(diff, current + 1);
            }
        }
        return result;
    }
}