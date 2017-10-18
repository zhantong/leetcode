class Solution {
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        class Utils {
        public:
            int distance(vector<int> &p1, vector<int> &p2) {
                return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
            }
        };
        Utils utils;
        vector<int> distances = {utils.distance(p1, p2), utils.distance(p1, p3), utils.distance(p1, p4),
                                 utils.distance(p2, p3), utils.distance(p2, p4), utils.distance(p3, p4)
                                };
        sort(distances.begin(), distances.end());
        return distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3]
               && distances[3] < distances[4] && distances[4] == distances[5];
    }
};