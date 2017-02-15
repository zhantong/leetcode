public class Solution {
    public List<String> readBinaryWatch(int num) {
        class Utils {
            void getCombination(int length, int numOnes, int base, List<Integer> pool) {
                if (numOnes == 0) {
                    pool.add(base);
                    return;
                }
                if (length == 0 || length < numOnes) {
                    return;
                }
                getCombination(length - 1, numOnes - 1, base + (1 << (length - 1)), pool);
                getCombination(length - 1, numOnes, base, pool);
            }
        }
        Utils utils = new Utils();
        List<String> result = new ArrayList<>();
        for (int onesHour = 0; onesHour <= num; onesHour++) {
            int onesMinute = num - onesHour;
            List<Integer> hours = new ArrayList<>();
            List<Integer> minutes = new ArrayList<>();
            utils.getCombination(4, onesHour, 0, hours);
            utils.getCombination(6, onesMinute, 0, minutes);
            for (int hour : hours) {
                if (hour > 11) {
                    continue;
                }
                for (int minute : minutes) {
                    if (minute > 59) {
                        continue;
                    }
                    result.add(String.format("%d:%02d", hour, minute));
                }
            }
        }
        return result;
    }
}