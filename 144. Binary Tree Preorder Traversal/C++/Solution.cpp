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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> sta;
        vector<int> result;
        while (root != nullptr || !sta.empty()) {
            if (root != nullptr) {
                result.push_back(root->val);
                sta.push(root);
                root = root->left;
            } else {
                root = sta.top()->right;
                sta.pop();
            }
        }
        return result;
    }
};