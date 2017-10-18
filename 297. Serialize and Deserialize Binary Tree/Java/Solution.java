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
    private void serial(TreeNode node, StringBuilder builder) {
        if (node != null) {
            builder.append(String.valueOf(node.val)).append(' ');
            serial(node.left, builder);
            serial(node.right, builder);
        } else {
            builder.append('#').append(' ');
        }
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder builder = new StringBuilder();
        serial(root, builder);
        return builder.deleteCharAt(builder.length() - 1).toString();
    }

    private TreeNode deserial(Queue<String> que) {
        String value = que.poll();
        if (value.equals("#")) {
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(value));
        node.left = deserial(que);
        node.right = deserial(que);
        return node;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<String> que = new LinkedList<>(Arrays.asList(data.split(" ")));
        return deserial(que);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));