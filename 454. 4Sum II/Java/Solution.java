public class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> sumABDict = new HashMap<>();
        for (int a : A) {
            for (int b : B) {
                int sumAB = a + b;
                if (!sumABDict.containsKey(sumAB)) {
                    sumABDict.put(sumAB, 0);
                }
                sumABDict.put(sumAB, sumABDict.get(sumAB) + 1);
            }
        }
        int result = 0;
        for (int c : C) {
            for (int d : D) {
                int sumCD = -c - d;
                if (sumABDict.containsKey(sumCD)) {
                    result += sumABDict.get(sumCD);
                }
            }
        }
        return result;
    }
}