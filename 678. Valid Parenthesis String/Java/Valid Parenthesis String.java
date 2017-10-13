class Solution {
    public boolean checkValidString(String s) {
        int minClose = 0;
        int maxClose = 0;
        for (char letter : s.toCharArray()) {
            if (letter == '(') {
                minClose++;
                maxClose++;
            } else if (letter == ')') {
                if (minClose > 0) {
                    minClose--;
                }
                maxClose--;
                if (maxClose < 0) {
                    return false;
                }
            } else {
                if (minClose > 0) {
                    minClose--;
                }
                maxClose++;
            }
        }
        return minClose == 0;
    }
}