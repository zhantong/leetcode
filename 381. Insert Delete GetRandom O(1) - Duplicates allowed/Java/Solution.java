public class RandomizedCollection {
    List<Integer> nums;
    Map<Integer, Set<Integer>> memory;
    Random random;

    /**
     * Initialize your data structure here.
     */
    public RandomizedCollection() {
        nums = new ArrayList<>();
        memory = new HashMap<>();
        random = new Random();
    }

    /**
     * Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
     */
    public boolean insert(int val) {
        boolean isAlreadyIn = true;
        if (!memory.containsKey(val)) {
            isAlreadyIn = false;
            memory.put(val, new HashSet<>());
        }
        memory.get(val).add(nums.size());
        nums.add(val);
        return !isAlreadyIn;
    }

    /**
     * Removes a value from the collection. Returns true if the collection contained the specified element.
     */
    public boolean remove(int val) {
        if (!memory.containsKey(val)) {
            return false;
        }
        int lastIndex = nums.size() - 1;
        if (!memory.get(val).contains(lastIndex)) {
            int currentIndex = memory.get(val).iterator().next();
            int lastValue = nums.get(nums.size() - 1);
            memory.get(lastValue).remove(lastIndex);
            memory.get(lastValue).add(currentIndex);
            memory.get(val).remove(currentIndex);
            nums.set(currentIndex, lastValue);
        } else {
            memory.get(val).remove(lastIndex);
        }
        if (memory.get(val).isEmpty()) {
            memory.remove(val);
        }
        nums.remove(nums.size() - 1);
        return true;
    }

    /**
     * Get a random element from the collection.
     */
    public int getRandom() {
        return nums.get(random.nextInt(nums.size()));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */