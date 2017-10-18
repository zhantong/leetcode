/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null) {
            return;
        }
        TreeLinkNode head = null;
        TreeLinkNode current = root;
        TreeLinkNode levelPrev = null;
        while (current != null) {
            while (current != null) {
                if (current.left != null) {
                    if (levelPrev != null) {
                        levelPrev.next = current.left;
                    } else {
                        head = current.left;
                    }
                    levelPrev = current.left;
                }
                if (current.right != null) {
                    if (levelPrev != null) {
                        levelPrev.next = current.right;
                    } else {
                        head = current.right;
                    }
                    levelPrev = current.right;
                }
                current = current.next;
            }
            current = head;
            levelPrev = null;
            head = null;
        }
    }
}