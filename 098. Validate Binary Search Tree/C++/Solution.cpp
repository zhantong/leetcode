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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> sta;
        TreeNode *prev = nullptr;
        while (root != nullptr || !sta.empty()) {
            while (root != nullptr) {
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            sta.pop();
            if (prev != nullptr && prev->val >= root->val) {
                return false;
            }
            prev = root;
            root = root->right;
        }
        return true;
    }
};