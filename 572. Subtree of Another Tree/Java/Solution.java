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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        class Utils {
            boolean isSame(TreeNode s, TreeNode t) {
                if (s == null && t == null) {
                    return true;
                }
                if (s == null || t == null || s.val != t.val) {
                    return false;
                }
                return isSame(s.left, t.left) && isSame(s.right, t.right);
            }
        }
        if (s == null) {
            return false;
        }
        Utils utils = new Utils();
        return utils.isSame(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t);
    }
}