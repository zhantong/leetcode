class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0;
        int d = 0;
        int current = 0;
        int length = senate.length();
        for (char s : senate) {
            if (s == 'R') {
                r++;
            } else {
                d++;
            }
        }
        while (r > 0 && d > 0) {
            while (senate[current] == ' ') {
                current = (current + 1) % length;
            }
            char toBan;
            if (senate[current] == 'R') {
                toBan = 'D';
                d--;
            } else {
                toBan = 'R';
                r--;
            }
            int temp = current;
            while (senate[temp] != toBan) {
                temp = (temp + 1) % length;
            }
            senate[temp] = ' ';
            current = (current + 1) % length;
        }
        return d == 0 ? "Radiant" : "Dire";
    }
};