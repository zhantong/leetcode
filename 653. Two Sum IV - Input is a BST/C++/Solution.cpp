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
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> candidates;
        stack<TreeNode *> sta;
        while (!sta.empty() || root != nullptr) {
            if (root != nullptr) {
                int val = root->val;
                if (candidates.find(val) != candidates.end()) {
                    return true;
                } else {
                    candidates.insert(k - val);
                }
                sta.push(root);
                root = root->left;
            } else {
                TreeNode *node = sta.top();
                sta.pop();
                root = node->right;
            }
        }
        return false;
    }
};