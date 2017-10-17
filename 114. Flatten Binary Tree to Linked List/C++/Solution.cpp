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
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        flatten(left);
        flatten(right);
        root->left = nullptr;
        root->right = left;
        TreeNode *temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        temp->right = right;
    }
};