public class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numsSet = new HashSet<>();
        for (int num : nums) {
            numsSet.add(num);
        }
        int result = 0;
        for (int num : nums) {
            if (numsSet.contains(num)) {
                int current = num;
                int count = 1;
                while (numsSet.contains(current - 1)) {
                    numsSet.remove(current - 1);
                    current--;
                    count++;
                }
                current = num;
                while (numsSet.contains(current + 1)) {
                    numsSet.remove(current + 1);
                    current++;
                    count++;
                }
                result = Math.max(result, count);
            }
        }
        return result;
    }
}