/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder builder = new StringBuilder();
        Stack<TreeNode> stack = new Stack<>();
        while (root != null || !stack.empty()) {
            if (root != null) {
                builder.append(String.valueOf(root.val));
                builder.append(" ");
                stack.push(root);
                root = root.left;
            } else {
                root = stack.pop().right;
            }
        }
        return builder.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.length() == 0) {
            return null;
        }
        class Utils {
            TreeNode construct(int[] data, int i, int j) {
                if (i == j) {
                    return null;
                }
                TreeNode node = new TreeNode(data[i]);
                int splitIndex = i + 1;
                while (splitIndex < j && data[splitIndex] < data[i]) {
                    splitIndex++;
                }
                node.left = construct(data, i + 1, splitIndex);
                node.right = construct(data, splitIndex, j);
                return node;
            }
        }
        String[] dataInString = data.split(" ");
        int[] dataInInt = new int[dataInString.length];
        for (int i = 0; i < dataInInt.length; i++) {
            dataInInt[i] = Integer.parseInt(dataInString[i]);
        }
        Utils utils = new Utils();
        return utils.construct(dataInInt, 0, dataInInt.length);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));