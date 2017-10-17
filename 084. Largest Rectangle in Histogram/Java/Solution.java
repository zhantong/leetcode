public class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        int result = 0;
        while (i < heights.length) {
            while (!stack.empty() && heights[i] < heights[stack.peek()]) {
                int index = stack.pop();
                int current = heights[index] * (i - (stack.empty() ? -1 : stack.peek()) - 1);
                result = Math.max(result, current);
            }
            stack.push(i);
            i++;
        }
        while (!stack.empty()) {
            int index = stack.pop();
            int current = heights[index] * (i - (stack.empty() ? -1 : stack.peek()) - 1);
            result = Math.max(result, current);
        }
        return result;
    }
}