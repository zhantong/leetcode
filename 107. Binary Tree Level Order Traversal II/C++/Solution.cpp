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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> que;
        vector<vector<int>> result;
        que.push(root);
        while (!que.empty()) {
            vector<int> currentList;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node != nullptr) {
                    currentList.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if (!currentList.empty()) {
                result.insert(result.begin(), currentList);
            }
        }
        return result;
    }
};