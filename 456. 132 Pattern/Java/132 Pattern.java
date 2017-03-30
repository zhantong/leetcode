public class Solution {
    public boolean find132pattern(int[] nums) {
        class Pair {
            int min;
            int max;

            public Pair(int min, int max) {
                this.min = min;
                this.max = max;
            }
        }
        if (nums.length < 3) {
            return false;
        }
        Stack<Pair> stack = new Stack<>();
        for (int num : nums) {
            if (stack.empty() || stack.peek().min > num) {
                stack.push(new Pair(num, num));
            } else if (stack.peek().min < num) {
                if (stack.peek().max > num) {
                    return true;
                }
                int theMin = stack.peek().min;
                stack.pop();
                while (!stack.empty() && stack.peek().max <= num) {
                    stack.pop();
                }
                if (!stack.empty() && stack.peek().min < num) {
                    return true;
                }
                stack.push(new Pair(theMin, num));
            }
        }
        return false;
    }
}