/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        class Utils {
        public:
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
        };
        if (points.size() < 3) {
            return points.size();
        }
        int result = 0;
        Utils utils;
        for (int i = 0; i < points.size(); i++) {
            Point current = points[i];
            int samePoint = 1;
            int sameVerticalLine = 0;
            unordered_map<long, int> memory;
            for (int j = i + 1; j < points.size(); j++) {
                Point point = points[j];
                if (current.x == point.x && current.y == point.y) {
                    samePoint++;
                } else if (current.x == point.x) {
                    sameVerticalLine++;
                } else {
                    long key = utils.transform(point.y - current.y, point.x - current.x);
                    if (memory.find(key) == memory.end()) {
                        memory[key] = 0;
                    }
                    memory[key]++;
                }
            }
            result = max(result, sameVerticalLine + samePoint);
            for (auto &item : memory) {
                result = max(result, item.second + samePoint);
            }
        }
        return result;
    }
};