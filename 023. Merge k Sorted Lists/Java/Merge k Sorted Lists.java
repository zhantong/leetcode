/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        class Utils {
            ListNode partition(ListNode[] lists, int start, int end) {
                if (start == end) {
                    return lists[start];
                }
                if (start < end) {
                    int mid = (start + end) / 2;
                    ListNode list1 = partition(lists, start, mid);
                    ListNode list2 = partition(lists, mid + 1, end);
                    return merge(list1, list2);
                }
                return null;
            }

            ListNode merge(ListNode list1, ListNode list2) {
                ListNode fakeHead = new ListNode(0);
                ListNode current = fakeHead;
                while (list1 != null && list2 != null) {
                    if (list1.val < list2.val) {
                        current.next = list1;
                        list1 = list1.next;
                    } else {
                        current.next = list2;
                        list2 = list2.next;
                    }
                    current = current.next;
                }
                current.next = list1 == null ? list2 : list1;
                return fakeHead.next;
            }
        }
        Utils utils = new Utils();
        return utils.partition(lists, 0, lists.length - 1);
    }
}