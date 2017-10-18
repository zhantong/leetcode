public class Solution {
    public int[] constructRectangle(int area) {
        int x = (int) Math.ceil(Math.sqrt(area));
        while (area % x != 0) {
            x++;
        }
        int y = area / x;
        return new int[] {x, y};
    }
}