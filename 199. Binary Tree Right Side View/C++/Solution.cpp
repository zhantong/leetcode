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
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return vector<int>();
        }
        queue<TreeNode *> que;
        vector<int> result;
        que.push(root);
        while (!que.empty()) {
            result.push_back(que.front()->val);
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->right != nullptr) {
                    que.push(node->right);
                }
                if (node->left != nullptr) {
                    que.push(node->left);
                }
            }
        }
        return result;
    }
};