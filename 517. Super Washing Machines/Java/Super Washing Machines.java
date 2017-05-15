public class Solution {
    public int findMinMoves(int[] machines) {
        int sumUp = 0;
        for (int machine : machines) {
            sumUp += machine;
        }
        if (sumUp % machines.length != 0) {
            return -1;
        }
        int average = sumUp / machines.length;
        int endingHere = 0;
        int result = 0;
        for (int machine : machines) {
            int current = machine - average;
            endingHere += current;
            result = Math.max(Math.max(result, Math.abs(endingHere)), current);
        }
        return result;
    }
}