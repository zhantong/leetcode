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
    vector<int> largestValues(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int currentMax = que.front()->val;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->val > currentMax) {
                    currentMax = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            result.push_back(currentMax);
        }
        return result;
    }
};