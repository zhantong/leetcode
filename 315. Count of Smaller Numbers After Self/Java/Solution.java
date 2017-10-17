public class Solution {
    public List<Integer> countSmaller(int[] nums) {
        class Node {
            int value;
            int countLeft = 0;
            int countDuplicate = 1;
            Node left;
            Node right;

            public Node(int value) {
                this.value = value;
            }
        }
        class Utils {
            Node insert(Node node, int num, int[] result, int i, int count) {
                if (node == null) {
                    node = new Node(num);
                    result[i] = count;
                } else if (node.value == num) {
                    result[i] = count + node.countLeft;
                    node.countDuplicate++;
                } else if (node.value > num) {
                    node.countLeft++;
                    node.left = insert(node.left, num, result, i, count);
                } else {
                    count += node.countLeft + node.countDuplicate;
                    node.right = insert(node.right, num, result, i, count);
                }
                return node;
            }
        }
        int[] result = new int[nums.length];
        Node root = null;
        Utils utils = new Utils();
        for (int i = nums.length - 1; i >= 0; i--) {
            root = utils.insert(root, nums[i], result, i, 0);
        }
        List<Integer> resultList = new ArrayList<>();
        for (int num : result) {
            resultList.add(num);
        }
        return resultList;
    }
}