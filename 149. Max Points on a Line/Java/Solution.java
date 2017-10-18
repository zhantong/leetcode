/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    public int maxPoints(Point[] points) {
        class Utils {
            long transform(int a, int b) {
                int c = gcd(a, b);
                a /= c;
                b /= c;
                long result = a;
                return (result << 32) | b;
            }

            int gcd(int a, int b) {
                while (b != 0) {
                    int temp = a % b;
                    a = b;
                    b = temp;
                }
                return a;
            }
        }
        if (points.length < 3) {
            return points.length;
        }
        int result = 0;
        Utils utils = new Utils();
        for (int i = 0; i < points.length; i++) {
            Point current = points[i];
            int samePoint = 1;
            int sameVerticalLine = 0;
            Map<Long, Integer> memory = new HashMap<>();
            for (int j = i + 1; j < points.length; j++) {
                Point point = points[j];
                if (current.x == point.x && current.y == point.y) {
                    samePoint++;
                } else if (current.x == point.x) {
                    sameVerticalLine++;
                } else {
                    long key = utils.transform(point.y - current.y, point.x - current.x);
                    if (!memory.containsKey(key)) {
                        memory.put(key, 0);
                    }
                    memory.put(key, memory.get(key) + 1);
                }
            }
            result = Math.max(result, sameVerticalLine + samePoint);
            for (int item : memory.values()) {
                result = Math.max(result, item + samePoint);
            }
        }
        return result;
    }
}