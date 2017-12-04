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
    public int diameterOfBinaryTree(TreeNode root) {
        class Utils {
            int result = -1;

            int diameter(TreeNode root) {
                if (root == null) {
                    return 0;
                }
                int left = diameter(root.left);
                int right = diameter(root.right);
                int length = left + right + 1;
                result = Math.max(result, length);
                return Math.max(left, right) + 1;
            }
        }
        Utils utils = new Utils();
        utils.diameter(root);
        return utils.result == -1 ? 0 : utils.result - 1;
    }
}