class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int sumUp = 0;
        for (auto machine : machines) {
            sumUp += machine;
        }
        if (sumUp % machines.size() != 0) {
            return -1;
        }
        int average = sumUp / machines.size();
        int endingHere = 0;
        int result = 0;
        for (auto machine : machines) {
            int current = machine - average;
            endingHere += current;
            result = max(max(result, abs(endingHere)), current);
        }
        return result;
    }
};