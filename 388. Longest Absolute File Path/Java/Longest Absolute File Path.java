public class Solution {
    public int lengthLongestPath(String input) {
        Stack<Integer> stack = new Stack<>();
        int maxLength = 0;
        String[] items = input.split("\n");
        for (String item : items) {
            int countTabs = item.lastIndexOf('\t') + 1;
            while (stack.size() > countTabs) {
                stack.pop();
            }
            int length = (stack.size() == 0 ? 0 : stack.peek()) + item.length() - countTabs + 1;
            if (item.contains(".")) {
                maxLength = Math.max(maxLength, length - 1);
            }
            stack.push(length);
        }
        return maxLength;
    }
}