/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        class Pair {
            TreeNode node;
            int id;

            public Pair(TreeNode node, int id) {
                this.node = node;
                this.id = id;
            }
        }
        int result = 0;
        LinkedList<Pair> queue = new LinkedList<>();
        if (root != null) {
            queue.add(new Pair(root, 1));
        }
        while (!queue.isEmpty()) {
            result = Math.max(result, queue.getLast().id - queue.getFirst().id + 1);
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Pair current = queue.pollFirst();
                if (current.node.left != null) {
                    queue.addLast(new Pair(current.node.left, 2 * current.id));
                }
                if (current.node.right != null) {
                    queue.addLast(new Pair(current.node.right, 2 * current.id + 1));
                }
            }
        }
        return result;
    }
}