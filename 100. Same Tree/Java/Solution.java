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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if ((p == null && q == null) ||
        (p != null && q != null && p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right))) {
            return true;
        }
        return false;
    }
}