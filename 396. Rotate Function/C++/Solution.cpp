class Solution {
public:
    int maxRotateFunction(vector<int> &A) {
        int sum = 0;
        int F = 0;
        int length = A.size();
        for (int i = 0; i < length; i++) {
            sum += A[i];
            F += i * A[i];
        }
        int theMax = F;
        for (int i = 1; i < length; i++) {
            F += sum - length * A[length - i];
            theMax = max(theMax, F);
        }
        return theMax;
    }
};