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
        TreeLinkNode *head = nullptr;
        TreeLinkNode *current = root;
        TreeLinkNode *levelPrev = nullptr;
        while (current != nullptr) {
            while (current != nullptr) {
                if (current->left != nullptr) {
                    if (levelPrev != nullptr) {
                        levelPrev->next = current->left;
                    } else {
                        head = current->left;
                    }
                    levelPrev = current->left;
                }
                if (current->right != nullptr) {
                    if (levelPrev != nullptr) {
                        levelPrev->next = current->right;
                    } else {
                        head = current->right;
                    }
                    levelPrev = current->right;
                }
                current = current->next;
            }
            current = head;
            levelPrev = nullptr;
            head = nullptr;
        }
    }
};