public class Solution {
    public String complexNumberMultiply(String a, String b) {
        int plusIndex = a.indexOf("+");
        int aReal = Integer.parseInt(a.substring(0, plusIndex));
        int aImage = Integer.parseInt(a.substring(plusIndex + 1, a.length() - 1));
        plusIndex = b.indexOf("+");
        int bReal = Integer.parseInt(b.substring(0, plusIndex));
        int bImage = Integer.parseInt(b.substring(plusIndex + 1, b.length() - 1));
        int real = aReal * bReal - aImage * bImage;
        int image = bReal * aImage + aReal * bImage;
        return real + "+" + image + "i";
    }
}