public class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stack = new Stack<>();
        int[] counts = new int[128];
        for (char letter : s.toCharArray()) {
            counts[letter]++;
        }
        boolean[] exists = new boolean[128];
        for (char letter : s.toCharArray()) {
            counts[letter]--;
            if (exists[letter]) {
                continue;
            }
            while (!stack.empty() && letter < stack.peek() && counts[stack.peek()] > 0) {
                int temp = stack.pop();
                exists[temp] = false;
            }
            stack.push(letter);
            exists[letter] = true;
        }
        StringBuilder builder = new StringBuilder();
        for (char letter : stack) {
            builder.append(letter);
        }
        return builder.toString();
    }
}