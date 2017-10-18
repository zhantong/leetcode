class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int result = 0;
        int length = A.size();
        vector<unordered_map<int, int>> memory(length);
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < i; j++) {
                long diffInLong = (long) A[i] - A[j];
                if (diffInLong > INT_MAX || diffInLong < INT_MIN) {
                    continue;
                }
                int diff = (int) diffInLong;
                int current = 0;
                if (memory[j].find(diff) != memory[j].end()) {
                    result += memory[j][diff];
                    current += memory[j][diff];
                }
                if (memory[i].find(diff) != memory[i].end()) {
                    current += memory[i][diff];
                }
                memory[i][diff] = current + 1;
            }
        }
        return result;
    }
};