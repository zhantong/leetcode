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
    public TreeNode convertBST(TreeNode root) {
        TreeNode originRoot = root;
        Stack<TreeNode> stack = new Stack<>();
        int current = 0;
        while (root != null || !stack.empty()) {
            if (root != null) {
                stack.push(root);
                root = root.right;
            } else {
                TreeNode node = stack.pop();
                current += node.val;
                node.val = current;
                root = node.left;
            }
        }
        return originRoot;
    }
}