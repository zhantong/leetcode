/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int getMinimumDifference(TreeNode root) {
        int result = Integer.MAX_VALUE;
        Stack<TreeNode> stack = new Stack<>();
        Integer prev = null;
        while (root != null || !stack.empty()) {
            if (root != null) {
                stack.add(root);
                root = root.left;
            } else {
                TreeNode node = stack.pop();
                if (prev != null) {
                    result = Math.min(result, node.val - prev);
                }
                prev = node.val;
                root = node.right;
            }
        }
        return result;
    }
}