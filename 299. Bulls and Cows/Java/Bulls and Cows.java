public class Solution {
    public String getHint(String secret, String guess) {
        int[] counts = new int[10];
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                bulls++;
            } else {
                if (counts[secret.charAt(i) - '0'] < 0) {
                    cows++;
                }
                counts[secret.charAt(i) - '0']++;
                if (counts[guess.charAt(i) - '0'] > 0) {
                    cows++;
                }
                counts[guess.charAt(i) - '0']--;
            }
        }
        return String.format("%dA%dB", bulls, cows);
    }
}