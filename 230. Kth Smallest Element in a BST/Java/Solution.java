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
    public int kthSmallest(TreeNode root, int k) {
        class Utils {
            int k;
            int result;

            public Utils(int k) {
                this.k = k;
            }

            void smallest(TreeNode root) {
                if (root == null) {
                    return;
                }
                smallest(root.left);
                k--;
                if (k == 0) {
                    result = root.val;
                    return;
                }
                smallest(root.right);
            }
        }
        Utils utils = new Utils(k);
        utils.smallest(root);
        return utils.result;
    }
}