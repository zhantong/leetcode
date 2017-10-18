/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int longestUnivaluePath(TreeNode root) {
        class Utils {
            int result = 0;

            int dfs(TreeNode node) {
                int left = 0;
                if (node.left != null) {
                    left = dfs(node.left);
                    left = (node.left.val == node.val) ? left + 1 : 0;
                }
                int right = 0;
                if (node.right != null) {
                    right = dfs(node.right);
                    right = (node.right.val == node.val) ? right + 1 : 0;
                }
                result = Math.max(result, left + right);
                return Math.max(left, right);
            }
        }
        if (root == null) {
            return 0;
        }
        Utils utils = new Utils();
        utils.dfs(root);
        return utils.result;
    }
}