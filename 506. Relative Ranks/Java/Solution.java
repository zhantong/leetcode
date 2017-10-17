public class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int maxNum = -1;
        for (int num : nums) {
            if (num > maxNum) {
                maxNum = num;
            }
        }
        int[] map = new int[maxNum + 1];
        for (int i = 0; i < nums.length; i++) {
            map[nums[i]] = i + 1;
        }
        String[] result = new String[nums.length];
        int rank = 1;
        for (int i = map.length - 1; i > -1; i--) {
            int index = map[i];
            if (index > 0) {
                String value = "";
                if (rank == 1) {
                    value = "Gold Medal";
                } else if (rank == 2) {
                    value = "Silver Medal";
                } else if (rank == 3) {
                    value = "Bronze Medal";
                } else {
                    value = String.valueOf(rank);
                }
                result[index - 1] = value;
                rank++;
            }
        }
        return result;
    }
}