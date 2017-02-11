class Solution {
public:
    int findComplement(int num) {
        long allOnes = 1;
        while (allOnes <= num) {
            allOnes <<= 1;
        }
        allOnes -= 1;
        return (int) allOnes ^ num;
    }
};