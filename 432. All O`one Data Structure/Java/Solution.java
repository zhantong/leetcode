public class AllOne {
    Map<String, Integer> keys;
    Map<Integer, Node> times;
    Node head;
    Node tail;

    class Node {
        Node prev;
        Node next;
        Set<String> keys;

        public Node() {
            keys = new HashSet<>();
        }
    }

    /**
     * Initialize your data structure here.
     */
    public AllOne() {
        keys = new HashMap<>();
        times = new HashMap<>();
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
    }

    /**
     * Inserts a new key <Key> with value 1. Or increments an existing key by 1.
     */
    public void inc(String key) {
        if (keys.containsKey(key)) {
            int time = keys.get(key);
            times.get(time).keys.remove(key);
            int newTime = time + 1;
            if (!times.containsKey(newTime)) {
                Node node = new Node();
                node.prev = times.get(time).prev;
                node.next = times.get(time);
                node.prev.next = node;
                node.next.prev = node;
                times.put(newTime, node);
            }
            times.get(newTime).keys.add(key);
            keys.put(key, newTime);
            if (times.get(time).keys.isEmpty()) {
                Node node = times.get(time);
                node.prev.next = node.next;
                node.next.prev = node.prev;
                times.remove(time);
            }
        } else {
            if (!times.containsKey(1)) {
                Node node = new Node();
                node.prev = tail.prev;
                node.next = tail;
                node.prev.next = node;
                node.next.prev = node;
                times.put(1, node);
            }
            times.get(1).keys.add(key);
            keys.put(key, 1);
        }
    }

    /**
     * Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
     */
    public void dec(String key) {
        if (!keys.containsKey(key)) {
            return;
        }
        int time = keys.get(key);
        times.get(time).keys.remove(key);
        int newTime = time - 1;
        if (newTime > 0) {
            if (!times.containsKey(newTime)) {
                Node node = new Node();
                node.prev = times.get(time);
                node.next = times.get(time).next;
                node.prev.next = node;
                node.next.prev = node;
                times.put(newTime, node);
            }
            times.get(newTime).keys.add(key);
            keys.put(key, newTime);
        } else {
            keys.remove(key);
        }
        if (times.get(time).keys.isEmpty()) {
            Node node = times.get(time);
            node.prev.next = node.next;
            node.next.prev = node.prev;
            times.remove(time);
        }
    }

    /**
     * Returns one of the keys with maximal value.
     */
    public String getMaxKey() {
        if (head.next == tail) {
            return "";
        }
        return head.next.keys.iterator().next();
    }

    /**
     * Returns one of the keys with Minimal value.
     */
    public String getMinKey() {
        if (tail.prev == head) {
            return "";
        }
        return tail.prev.keys.iterator().next();
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */