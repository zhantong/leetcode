public class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        int[] heights = new int[matrix[0].length];
        int result = 0;
        for (char[] row : matrix) {
            for (int i = 0; i < row.length; i++) {
                if (row[i] == '1') {
                    heights[i]++;
                } else {
                    heights[i] = 0;
                }
            }
            Stack<Integer> stack = new Stack<>();
            int i = 0;
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
        }
        return result;
    }
}