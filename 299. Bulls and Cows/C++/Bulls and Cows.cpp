class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> counts(10);
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                if (counts[secret[i] - '0'] < 0) {
                    cows++;
                }
                counts[secret[i] - '0']++;
                if (counts[guess[i] - '0'] > 0) {
                    cows++;
                }
                counts[guess[i] - '0']--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};