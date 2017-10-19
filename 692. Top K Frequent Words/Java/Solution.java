class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        class Item implements Comparable<Item> {
            String word;
            int count;

            Item(String word, int count) {
                this.word = word;
                this.count = count;
            }

            @Override
            public int compareTo(Item o) {
                if (count == o.count) {
                    return o.word.compareTo(word);
                }
                return count - o.count;
            }
        }
        Map<String, Integer> counts = new HashMap<>();
        for (String word : words) {
            if (!counts.containsKey(word)) {
                counts.put(word, 0);
            }
            counts.put(word, counts.get(word) + 1);
        }
        PriorityQueue<Item> heap = new PriorityQueue<>();
        for (Map.Entry<String, Integer> entry : counts.entrySet()) {
            heap.add(new Item(entry.getKey(), entry.getValue()));
            if (heap.size() > k) {
                heap.poll();
            }
        }
        List<String> result = new ArrayList<>();
        while (!heap.isEmpty()) {
            result.add(heap.poll().word);
        }
        Collections.reverse(result);
        return result;
    }
}