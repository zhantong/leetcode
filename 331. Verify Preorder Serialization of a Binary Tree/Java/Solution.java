public class Solution {
    public boolean isValidSerialization(String preorder) {
        int degree = -1;
        String[] nodes = preorder.split(",");
        for (String node : nodes) {
            degree++;
            if (degree > 0) {
                return false;
            }
            if (!node.equals("#")) {
                degree -= 2;
            }
        }
        return degree == 0;
    }
}