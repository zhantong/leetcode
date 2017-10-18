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
    public boolean isBalanced(TreeNode root) {
        class Utils {
            int balanced(TreeNode root) {
                if (root == null) {
                    return 0;
                }
                int left = balanced(root.left);
                int right = balanced(root.right);
                if (left == -1 || right == -1 || Math.abs(left - right) > 1) {
                    return -1;
                }
                return 1 + Math.max(left, right);
            }
        }
        Utils utils = new Utils();
        return utils.balanced(root) != -1;
    }
}