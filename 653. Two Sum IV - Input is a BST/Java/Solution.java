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
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> candidates = new HashSet<>();
        Stack<TreeNode> stack = new Stack<>();
        while (!stack.empty() || root != null) {
            if (root != null) {
                int val = root.val;
                if (candidates.contains(val)) {
                    return true;
                } else {
                    candidates.add(k - val);
                }
                stack.add(root);
                root = root.left;
            } else {
                TreeNode node = stack.pop();
                root = node.right;
            }
        }
        return false;
    }
}