class Solution {
public:
    int kEmptySlots(vector<int> &flowers, int k) {
        vector<int> positions(flowers.size() + 1);
        for (int i = 0; i < flowers.size(); i++) {
            positions[flowers[i]] = i + 1;
        }
        int start = 1;
        int end = start + k + 1;
        if (end >= positions.size()) {
            return -1;
        }
        int result = INT_MAX;
        for (int position = 1; position < positions.size(); position++) {
            int day = positions[position];
            if (positions[start] > day || positions[end] >= day) {
                if (position == end) {
                    result = min(result, max(positions[start], positions[end]));
                }
                start = position;
                end = start + k + 1;
                if (end >= positions.size()) {
                    break;
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};