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
    void recoverTree(TreeNode *root) {
        TreeNode *pre = nullptr;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        while (root != nullptr) {
            if (root->left != nullptr) {
                TreeNode *temp = root->left;
                while (temp->right != nullptr && temp->right != root) {
                    temp = temp->right;
                }
                if (temp->right == nullptr) {
                    temp->right = root;
                    root = root->left;
                } else {
                    temp->right = nullptr;
                    if (pre != nullptr && pre->val > root->val) {
                        if (first != nullptr) {
                            second = root;
                        } else {
                            first = pre;
                            second = root;
                        }
                    }
                    pre = root;
                    root = root->right;
                }
            } else {
                if (pre != nullptr && pre->val > root->val) {
                    if (first != nullptr) {
                        second = root;
                    } else {
                        first = pre;
                        second = root;
                    }
                }
                pre = root;
                root = root->right;
            }
        }
        if (first != nullptr && second != nullptr) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};