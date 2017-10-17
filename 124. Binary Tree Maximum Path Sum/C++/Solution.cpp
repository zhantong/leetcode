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
    int maxPathSum(TreeNode *root) {
        class Utils {
        public:
            int maxValue = INT_MIN;

            int pathSum(TreeNode *root) {
                if (root == nullptr) {
                    return 0;
                }
                int left = max(0, pathSum(root->left));
                int right = max(0, pathSum(root->right));
                maxValue = max(maxValue, left + right + root->val);
                return max(left, right) + root->val;
            }
        };
        Utils utils;
        utils.pathSum(root);
        return utils.maxValue;
    }
};