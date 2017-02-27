class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 0; i < result.size(); i++) {
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};