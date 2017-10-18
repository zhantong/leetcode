/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serial(TreeNode *node, string &builder) {
        if (node != nullptr) {
            builder += to_string(node->val);
            builder += " ";
            serial(node->left, builder);
            serial(node->right, builder);
        } else {
            builder += "#";
            builder += " ";
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string builder = "";
        serial(root, builder);
        builder.pop_back();
        return builder;
    }

    TreeNode *deserial(queue<string> &que) {
        string &value = que.front();
        que.pop();
        if (value == "#") {
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(value));
        node->left = deserial(que);
        node->right = deserial(que);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        string buf;
        stringstream ss(data);
        queue<string> que;
        while (ss >> buf) {
            que.push(buf);
        }
        return deserial(que);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));