public class Solution {
    public boolean repeatedSubstringPattern(String str) {
        for (int i = str.length() / 2; i > 0; i--) {
            if (str.length() % i == 0) {
                boolean flag = false;
                for (int offset = i; offset < str.length(); offset += i) {
                    for (int index = 0; index < i; index++) {
                        if (str.charAt(index) != str.charAt(offset + index)) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (!flag) {
                    return true;
                }
            }
        }
        return false;
    }
}