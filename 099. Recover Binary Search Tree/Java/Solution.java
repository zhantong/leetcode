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
    public void recoverTree(TreeNode root) {
        TreeNode pre = null;
        TreeNode first = null;
        TreeNode second = null;
        while (root != null) {
            if (root.left != null) {
                TreeNode temp = root.left;
                while (temp.right != null && temp.right != root) {
                    temp = temp.right;
                }
                if (temp.right == null) {
                    temp.right = root;
                    root = root.left;
                } else {
                    temp.right = null;
                    if (pre != null && pre.val > root.val) {
                        if (first != null) {
                            second = root;
                        } else {
                            first = pre;
                            second = root;
                        }
                    }
                    pre = root;
                    root = root.right;
                }
            } else {
                if (pre != null && pre.val > root.val) {
                    if (first != null) {
                        second = root;
                    } else {
                        first = pre;
                        second = root;
                    }
                }
                pre = root;
                root = root.right;
            }
        }
        if (first != null && second != null) {
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }
    }
}