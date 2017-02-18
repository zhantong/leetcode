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
    bool isSymmetric(TreeNode *root) {
        class Utils {
        public:
            bool symmetric(TreeNode *left, TreeNode *right) {
                if (left == nullptr && right == nullptr) {
                    return true;
                }
                if (left != nullptr && right != nullptr && left->val == right->val) {
                    return symmetric(left->left, right->right) && symmetric(left->right, right->left);
                }
                return false;
            }
        };
        if (root == nullptr) {
            return true;
        }
        Utils utils;
        return utils.symmetric(root->left, root->right);
    }
};