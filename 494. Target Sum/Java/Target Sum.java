public class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int sumNums = 0;
        for (int num : nums) {
            sumNums += num;
        }
        if (S > sumNums || S < -sumNums) {
            return 0;
        }
        int[] map = new int[2 * sumNums + 1];
        map[sumNums] = 1;
        for (int num : nums) {
            int[] newMap = new int[2 * sumNums + 1];
            for (int i = 0; i < 2 * sumNums + 1; i++) {
                if (map[i] != 0) {
                    newMap[i + num] += map[i];
                    newMap[i - num] += map[i];
                }
            }
            map = newMap;
        }
        return map[sumNums + S];
    }
}