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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> que;
        que.push(root);
        bool leftToRight = true;
        while (!que.empty()) {
            int size = que.size();
            vector<int> current;
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
            if (!leftToRight) {
                reverse(current.begin(), current.end());
            }
            result.push_back(current);
            leftToRight = !leftToRight;
        }
        return result;
    }
};