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
    bool isBalanced(TreeNode *root) {
        class Utils {
        public:
            int balanced(TreeNode *root) {
                if (root == nullptr) {
                    return 0;
                }
                int left = balanced(root->left);
                int right = balanced(root->right);
                if (left == -1 || right == -1 || abs(left - right) > 1) {
                    return -1;
                }
                return 1 + max(left, right);
            }
        };
        Utils utils;
        return utils.balanced(root) != -1;
    }
};