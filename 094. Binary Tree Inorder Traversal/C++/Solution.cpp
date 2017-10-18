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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> sta;
        vector<int> result;
        while (root != nullptr || !sta.empty()) {
            if (root != nullptr) {
                sta.push(root);
                root = root->left;
            } else {
                TreeNode *node = sta.top();
                sta.pop();
                result.push_back(node->val);
                root = node->right;
            }
        }
        return result;
    }
};