class Solution {
    public boolean judgeCircle(String moves) {
        if (moves.length() % 2 != 0) {
            return false;
        }
        int countV = 0;
        int countH = 0;
        for (char letter : moves.toCharArray()) {
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
}