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
    int diameterOfBinaryTree(TreeNode *root) {
        class Utils {
        public:
            int result = -1;

            int diameter(TreeNode *root) {
                if (root == nullptr) {
                    return 0;
                }
                int left = diameter(root->left);
                int right = diameter(root->right);
                int length = left + right + 1;
                result = max(result, length);
                return max(left, right) + 1;
            }
        };
        Utils utils;
        utils.diameter(root);
        return utils.result == -1 ? 0 : utils.result - 1;
    }
};