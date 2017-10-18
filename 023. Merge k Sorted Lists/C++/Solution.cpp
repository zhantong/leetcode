/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        class Utils {
        public:
            ListNode *partition(vector<ListNode *> &lists, int start, int end) {
                if (start == end) {
                    return lists[start];
                }
                if (start < end) {
                    int mid = (start + end) / 2;
                    ListNode *list1 = partition(lists, start, mid);
                    ListNode *list2 = partition(lists, mid + 1, end);
                    return merge(list1, list2);
                }
                return nullptr;
            }

            ListNode *merge(ListNode *list1, ListNode *list2) {
                ListNode *fakeHead = new ListNode(0);
                ListNode *current = fakeHead;
                while (list1 != nullptr && list2 != nullptr) {
                    if (list1->val < list2->val) {
                        current->next = list1;
                        list1 = list1->next;
                    } else {
                        current->next = list2;
                        list2 = list2->next;
                    }
                    current = current->next;
                }
                current->next = list1 == nullptr ? list2 : list1;
                return fakeHead->next;
            }
        };
        Utils utils;
        return utils.partition(lists, 0, lists.size() - 1);
    }
};