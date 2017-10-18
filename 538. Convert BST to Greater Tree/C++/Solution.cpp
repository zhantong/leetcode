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
    TreeNode *convertBST(TreeNode *root) {
        TreeNode *originRoot = root;
        stack<TreeNode *> sta;
        int current = 0;
        while (root != nullptr || !sta.empty()) {
            if (root != nullptr) {
                sta.push(root);
                root = root->right;
            } else {
                TreeNode *node = sta.top();
                sta.pop();
                current += node->val;
                node->val = current;
                root = node->left;
            }
        }
        return originRoot;
    }
};