class Solution {
    public boolean judgePoint24(int[] nums) {
        class Utils {
            double EPS = 0.001;

            boolean backTrace(List<Double> nums) {
                if (nums.size() == 1) {
                    return Math.abs(nums.get(0) - 24) < EPS;
                }
                for (int i = 0; i < nums.size(); i++) {
                    double a = nums.get(i);
                    for (int j = 0; j < i; j++) {
                        double b = nums.get(j);
                        List<Double> candidates = new ArrayList<>();
                        candidates.add(a + b);
                        candidates.add(a - b);
                        candidates.add(b - a);
                        candidates.add(a * b);
                        if (Math.abs(a) > EPS) {
                            candidates.add(b / a);
                        }
                        if (Math.abs(b) > EPS) {
                            candidates.add(a / b);
                        }
                        nums.remove(i);
                        nums.remove(j);
                        for (double candidate : candidates) {
                            nums.add(candidate);
                            if (backTrace(nums)) {
                                return true;
                            }
                            nums.remove(nums.size() - 1);
                        }
                        nums.add(j, b);
                        nums.add(i, a);
                    }
                }
                return false;
            }
        }
        Utils utils = new Utils();
        List<Double> temp = new ArrayList<>();
        for (int num : nums) {
            temp.add((double)num);
        }
        return utils.backTrace(temp);
    }
}