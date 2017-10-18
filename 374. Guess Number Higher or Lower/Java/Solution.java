/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        long low = 1;
        long high = n;
        while (low <= high) {
            int mid = (int)((low + high) / 2);
            int guessResult = guess(mid);
            if (guessResult == 0) {
                return mid;
            }
            if (guessResult == 1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return 0;
    }
}