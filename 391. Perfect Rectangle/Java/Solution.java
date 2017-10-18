public class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        int x1 = Integer.MAX_VALUE;
        int y1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE;
        int y2 = Integer.MIN_VALUE;
        Set<String> got = new HashSet<>();
        int sumUp = 0;
        for (int[] rectangle : rectangles) {
            int a1 = rectangle[0];
            int b1 = rectangle[1];
            int a2 = rectangle[2];
            int b2 = rectangle[3];
            x1 = Math.min(x1, a1);
            y1 = Math.min(y1, b1);
            x2 = Math.max(x2, a2);
            y2 = Math.max(y2, b2);
            sumUp += (a2 - a1) * (b2 - b1);
            for (int i = 0; i < 3; i += 2) {
                for (int j = 1; j < 4; j += 2) {
                    String key = rectangle[i] + " " + rectangle[j];
                    if (got.contains(key)) {
                        got.remove(key);
                    } else {
                        got.add(key);
                    }
                }
            }
        }
        return got.size() == 4
               && got.contains(x1 + " " + y1)
               && got.contains(x1 + " " + y2)
               && got.contains(x2 + " " + y1)
               && got.contains(x2 + " " + y2)
               && sumUp == (x2 - x1) * (y2 - y1);
    }
}