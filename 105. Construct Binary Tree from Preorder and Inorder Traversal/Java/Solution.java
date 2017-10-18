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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        class Utils {
            TreeNode build(int[] preorder, int[] inorder, int preorderHead, int inorderHead, int inorderTail) {
                if (preorderHead >= preorder.length || inorderHead > inorderTail) {
                    return null;
                }
                TreeNode node = new TreeNode(preorder[preorderHead]);
                int index = 0;
                for (int i = inorderHead; i <= inorderTail; i++) {
                    if (inorder[i] == node.val) {
                        index = i;
                        break;
                    }
                }
                node.left = build(preorder, inorder, preorderHead + 1, inorderHead, index - 1);
                node.right = build(preorder, inorder, preorderHead + index - inorderHead + 1, index + 1, inorderTail);
                return node;
            }
        }
        Utils utils = new Utils();
        return utils.build(preorder, inorder, 0, 0, inorder.length - 1);
    }
}