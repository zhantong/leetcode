public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        StringBuilder result = new StringBuilder();
        if ((numerator > 0) != (denominator > 0)) {
            result.append('-');
        }
        long num = Math.abs((long) numerator);
        long den = Math.abs((long) denominator);
        result.append(num / den);
        num %= den;
        if (num == 0) {
            return result.toString();
        }
        result.append('.');
        Map<Long, Integer> memory = new HashMap<>();
        memory.put(num, result.length());
        while (num != 0) {
            num *= 10;
            result.append(num / den);
            num %= den;
            if (memory.containsKey(num)) {
                int startIndex = memory.get(num);
                result.insert(startIndex, '(');
                result.append(')');
                break;
            }
            memory.put(num, result.length());
        }
        return result.toString();
    }
}