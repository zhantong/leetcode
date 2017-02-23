public class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int heaterIndex = 0;
        int result = 0;
        for (int house : houses) {
            while (heaterIndex + 1 < heaters.length && Math.abs(house - heaters[heaterIndex]) >= Math.abs(heaters[heaterIndex + 1] - house)) {
                heaterIndex++;
            }
            result = Math.max(result, Math.abs(house - heaters[heaterIndex]));
        }
        return result;
    }
}