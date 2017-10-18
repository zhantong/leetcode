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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<TreeNode *> que;
        vector<vector<int>> result;
        que.push(root);
        while (!que.empty()) {
            vector<int> current;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                current.push_back(node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            result.push_back(current);
        }
        return result;
    }
};