class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() % 2 != 0) {
            return false;
        }
        int countV = 0;
        int countH = 0;
        for (auto &letter : moves) {
            switch (letter) {
            case 'U':
                countV++;
                break;
            case 'D':
                countV--;
                break;
            case 'L':
                countH++;
                break;
            case 'R':
                countH--;
                break;
            }
        }
        return countV == 0 && countH == 0;
    }
};