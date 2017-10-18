class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int heaterIndex = 0;
        int result = 0;
        for (int house : houses) {
            while (heaterIndex + 1 < heaters.size() &&
                   abs(house - heaters[heaterIndex]) >= abs(heaters[heaterIndex + 1] - house)) {
                heaterIndex++;
            }
            result = max(result, abs(house - heaters[heaterIndex]));
        }
        return result;
    }
};