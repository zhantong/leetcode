public class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            stack.add(i);
        }
        int[] result = new int[nums.length];
        for (int i = nums.length - 1; i >= 0; i--) {
            while ((!stack.isEmpty()) && nums[stack.peek()] <= nums[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                result[i] = nums[stack.peek()];
            } else {
                result[i] = -1;
            }
            stack.add(i);
        }
        return result;
    }
}