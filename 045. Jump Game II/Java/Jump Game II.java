public class Solution {
    public int jump(int[] nums) {
        int result = 0;
        int index = 0;
        int current = 0;
        int next = 0;
        while (current < nums.length - 1) {
            result++;
            while (index <= current) {
                next = Math.max(next, index + nums[index]);
                index++;
            }
            current = next;
        }
        return result;
    }
}