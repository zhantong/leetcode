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
    unordered_map<TreeNode *, int> memory;

    int rob(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (memory.find(root) != memory.end()) {
            return memory[root];
        }
        int subSum = 0;
        if (root->left != nullptr) {
            subSum += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            subSum += rob(root->right->left) + rob(root->right->right);
        }
        int result = max(root->val + subSum, rob(root->left) + rob(root->right));
        memory[root] = result;
        return result;
    }
};