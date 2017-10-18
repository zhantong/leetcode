/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class Solution {
    public NestedInteger deserialize(String s) {
        if (s.isEmpty()) {
            return null;
        }
        if (s.charAt(0) != '[') {
            return new NestedInteger(Integer.valueOf(s));
        }
        int prevIndex = 0;
        int index = 0;
        Stack<NestedInteger> stack = new Stack<>();
        NestedInteger current = null;
        while (index < s.length()) {
            if (s.charAt(index) == '[') {
                if (current != null) {
                    stack.push(current);
                }
                current = new NestedInteger();
                prevIndex = index + 1;
            }
            if (s.charAt(index) == ',') {
                if (s.charAt(index - 1) != ']') {
                    int item = Integer.valueOf(s.substring(prevIndex, index));
                    current.add(new NestedInteger(item));
                }
                prevIndex = index + 1;
            }
            if (s.charAt(index) == ']') {
                if (s.charAt(index - 1) != ']' && s.charAt(index - 1) != '[') {
                    int item = Integer.valueOf(s.substring(prevIndex, index));
                    current.add(new NestedInteger(item));
                }
                if (!stack.empty()) {
                    NestedInteger outer = stack.pop();
                    outer.add(current);
                    current = outer;
                }
            }
            index++;
        }
        return current;
    }
}