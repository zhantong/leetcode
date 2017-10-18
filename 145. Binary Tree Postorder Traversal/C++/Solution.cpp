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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> sta;
        vector<int> result;
        TreeNode *node = root;
        while (node != nullptr || !sta.empty()) {
            if (node != nullptr) {
                sta.push(node);
                result.push_back(node->val);
                node = node->right;
            } else {
                node = sta.top();
                sta.pop();
                node = node->left;
            }
        }
        reverse(result.rbegin(), result.rend());
        return result;
    }
};