class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int i = 1;
        int j = n;
        while (i <= j) {
            if (k > 0) {
                if (k % 2 != 0) {
                    result.push_back(i);
                    i++;
                } else {
                    result.push_back(j);
                    j--;
                }
                k--;
            } else {
                result.push_back(i);
                i++;
            }
        }
        return result;
    }
};