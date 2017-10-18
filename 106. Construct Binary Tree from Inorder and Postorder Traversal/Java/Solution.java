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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        class Utils {
            int postorderTail;

            public Utils(int tail) {
                postorderTail = tail;
            }

            TreeNode build(int[] inorder, int[] postorder, int inorderHead, int inorderTail) {
                if (inorderHead > inorderTail || postorderTail < 0) {
                    return null;
                }
                TreeNode node = new TreeNode(postorder[postorderTail]);
                postorderTail--;
                int index = inorderHead;
                for (int i = inorderHead; i <= inorderTail; i++) {
                    if (inorder[i] == node.val) {
                        index = i;
                        break;
                    }
                }
                node.right = build(inorder, postorder, index + 1, inorderTail);
                node.left = build(inorder, postorder, inorderHead, index - 1);
                return node;
            }
        }
        if (inorder.length == 0 || postorder.length == 0) {
            return null;
        }
        Utils utils = new Utils(postorder.length - 1);
        return utils.build(inorder, postorder, 0, inorder.length - 1);
    }
}