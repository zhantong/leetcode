class Solution {
    public String solveEquation(String equation) {
        int sign = 1;
        int countX = 0;
        int con = 0;
        int isReverse = 1;
        int current = 0;
        char[] equations = equation.toCharArray();
        for (int i = 0; i < equations.length; i++) {
            char letter = equations[i];
            if (letter >= '0' && letter <= '9') {
                current = current * 10 + letter - '0';
            } else if (letter == 'x') {
                if (current == 0 && (i == 0 || (equations[i - 1] == '+' || equations[i - 1] == '-' || equations[i - 1] == '='))) {
                    current = 1;
                }
                countX += current * sign * isReverse;
                current = 0;
            } else {
                con += current * sign * isReverse * -1;
                current = 0;
                if (letter == '=') {
                    isReverse = -1;
                    sign = 1;
                } else {
                    sign = letter == '+' ? 1 : -1;
                }
            }
        }
        con += current * sign * isReverse * -1;
        if (countX == 0 && con == 0) {
            return "Infinite solutions";
        } else if (countX == 0) {
            return "No solution";
        } else {
            return "x=" + con / countX;
        }
    }
}