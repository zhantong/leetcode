class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        class Utils {
            String toKey(List<Integer> array) {
                StringBuilder builder = new StringBuilder();
                for (int item : array) {
                    builder.append(item);
                }
                return builder.toString();
            }

            List<Integer> toArray(String key) {
                List<Integer> array = new ArrayList<>();
                for (char letter : key.toCharArray()) {
                    array.add(letter - '0');
                }
                return array;
            }

            int trace(List<Integer> prices, List<List<Integer>> specials, String needsKey, Map<String, Integer> memory) {
                if (memory.containsKey(needsKey)) {
                    return memory.get(needsKey);
                }
                List<Integer> needsArray = toArray(needsKey);
                int result = 0;
                for (int i = 0; i < prices.size(); i++) {
                    result += prices.get(i) * needsArray.get(i);
                }
                for (List<Integer> special : specials) {
                    List<Integer> newNeedsArray = new ArrayList<>(needsArray);
                    boolean canFit = true;
                    for (int i = 0; i < needsArray.size(); i++) {
                        if (needsArray.get(i) < special.get(i)) {
                            canFit = false;
                            break;
                        }
                        newNeedsArray.set(i, newNeedsArray.get(i) - special.get(i));
                    }
                    if (canFit) {
                        result = Math.min(result, special.get(special.size() - 1) + trace(prices, specials, toKey(newNeedsArray), memory));
                    }
                }
                memory.put(needsKey, result);
                return result;
            }
        }
        Utils utils = new Utils();
        return utils.trace(price, special, utils.toKey(needs), new HashMap<>());
    }
}