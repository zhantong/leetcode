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
    public int maxPathSum(TreeNode root) {
        class Utils {
            int maxValue = Integer.MIN_VALUE;

            int pathSum(TreeNode root) {
                if (root == null) {
                    return 0;
                }
                int left = Math.max(0, pathSum(root.left));
                int right = Math.max(0, pathSum(root.right));
                maxValue = Math.max(maxValue, left + right + root.val);
                return Math.max(left, right) + root.val;
            }
        }
        Utils utils = new Utils();
        utils.pathSum(root);
        return utils.maxValue;
    }
}