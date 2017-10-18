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
    public int findTilt(TreeNode root) {
        class Util {
            int tilt;

            int sum(TreeNode root) {
                if (root == null) {
                    return 0;
                }
                int sumLeft = sum(root.left);
                int sumRight = sum(root.right);
                tilt += Math.abs(sumLeft - sumRight);
                return sumLeft + sumRight + root.val;
            }
        }
        Util util = new Util();
        util.sum(root);
        return util.tilt;
    }
}