class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int result = 0;
        if (A.size() < 2) {
            return 0;
        }
        int gap = A[1] - A[0];
        int length = 2;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == gap) {
                length++;
            } else {
                if (length >= 3) {
                    result += (1 + length - 3 + 1) * (length - 3 + 1) / 2;
                }
                gap = A[i] - A[i - 1];
                length = 2;
            }
        }
        if (length >= 3) {
            result += (1 + length - 3 + 1) * (length - 3 + 1) / 2;
        }
        return result;
    }
};