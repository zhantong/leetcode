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
    int getMinimumDifference(TreeNode *root) {
        int result = INT_MAX;
        stack<TreeNode *> sta;
        int prev = 0;
        bool hasPrev = false;
        while (root != nullptr || !sta.empty()) {
            if (root != nullptr) {
                sta.push(root);
                root = root->left;
            } else {
                TreeNode *node = sta.top();
                sta.pop();
                if (hasPrev) {
                    result = min(result, node->val - prev);
                }
                prev = node->val;
                hasPrev = true;
                root = node->right;
            }
        }
        return result;
    }
};