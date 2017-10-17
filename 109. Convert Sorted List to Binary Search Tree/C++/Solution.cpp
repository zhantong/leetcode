/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        class Utils {
        public:
            TreeNode *toBST(ListNode *head, ListNode *tail) {
                if (head == tail) {
                    return nullptr;
                }
                ListNode *slow = head;
                ListNode *fast = head;
                while (fast != tail && fast->next != tail) {
                    slow = slow->next;
                    fast = fast->next->next;
                }
                TreeNode *node = new TreeNode(slow->val);
                node->left = toBST(head, slow);
                node->right = toBST(slow->next, tail);
                return node;
            }
        };
        Utils utils;
        return utils.toBST(head, nullptr);
    }
};