class Solution {
public:
    vector<int> constructRectangle(int area) {
        int x = (int) ceil(sqrt(area));
        while (area % x != 0) {
            x++;
        }
        int y = area / x;
        return vector<int> {x, y};
    }
};