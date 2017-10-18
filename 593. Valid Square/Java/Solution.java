class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        class Utils {
            int distance(int[] p1, int[] p2) {
                return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
            }
        }
        Utils utils = new Utils();
        int[] distances = new int[] {utils.distance(p1, p2), utils.distance(p1, p3), utils.distance(p1, p4)
                                     , utils.distance(p2, p3), utils.distance(p2, p4), utils.distance(p3, p4)
                                    };
        Arrays.sort(distances);
        return distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3]
               && distances[3] < distances[4] && distances[4] == distances[5];
    }
}