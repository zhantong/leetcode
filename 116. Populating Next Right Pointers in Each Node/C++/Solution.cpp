/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeLinkNode *prev = root;
        while (prev->left != nullptr) {
            TreeLinkNode *current = prev;
            while (current != nullptr) {
                current->left->next = current->right;
                if (current->next != nullptr) {
                    current->right->next = current->next->left;
                }
                current = current->next;
            }
            prev = prev->left;
        }
    }
};