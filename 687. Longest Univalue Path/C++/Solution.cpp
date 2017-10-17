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
    int longestUnivaluePath(TreeNode *root) {
        class Utils {
        public:
            int result = 0;

            int dfs(TreeNode *node) {
                int left = 0;
                if (node->left != nullptr) {
                    left = dfs(node->left);
                    left = (node->left->val == node->val) ? left + 1 : 0;
                }
                int right = 0;
                if (node->right != nullptr) {
                    right = dfs(node->right);
                    right = (node->right->val == node->val) ? right + 1 : 0;
                }
                result = max(result, left + right);
                return max(left, right);
            }
        };
        if (root == nullptr) {
            return 0;
        }
        Utils utils;
        utils.dfs(root);
        return utils.result;
    }
};