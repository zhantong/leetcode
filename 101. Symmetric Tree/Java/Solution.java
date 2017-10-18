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
    public boolean isSymmetric(TreeNode root) {
        class Utils {
            boolean symmetric(TreeNode left, TreeNode right) {
                if (left == null && right == null) {
                    return true;
                }
                if (left != null && right != null && left.val == right.val) {
                    return symmetric(left.left, right.right) && symmetric(left.right, right.left);
                }
                return false;
            }
        }
        Utils utils = new Utils();
        if (root == null) {
            return true;
        }
        return utils.symmetric(root.left, root.right);
    }
}