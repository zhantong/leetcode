class Solution {
    public String predictPartyVictory(String senate) {
        int r = 0;
        int d = 0;
        int current = 0;
        char[] senates = senate.toCharArray();
        int length = senates.length;
        for (char s : senates) {
            if (s == 'R') {
                r++;
            } else {
                d++;
            }
        }
        while (r > 0 && d > 0) {
            while (senates[current] == ' ') {
                current = (current + 1) % length;
            }
            char toBan;
            if (senates[current] == 'R') {
                toBan = 'D';
                d--;
            } else {
                toBan = 'R';
                r--;
            }
            int temp = current;
            while (senates[temp] != toBan) {
                temp = (temp + 1) % length;
            }
            senates[temp] = ' ';
            current = (current + 1) % length;
        }
        return d == 0 ? "Radiant" : "Dire";
    }
}