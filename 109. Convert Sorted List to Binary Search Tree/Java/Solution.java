/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        class Utils {
            TreeNode toBST(ListNode head, ListNode tail) {
                if (head == tail) {
                    return null;
                }
                ListNode slow = head;
                ListNode fast = head;
                while (fast != tail && fast.next != tail) {
                    slow = slow.next;
                    fast = fast.next.next;
                }
                TreeNode node = new TreeNode(slow.val);
                node.left = toBST(head, slow);
                node.right = toBST(slow.next, tail);
                return node;
            }
        }
        Utils utils = new Utils();
        return utils.toBST(head, null);
    }
}