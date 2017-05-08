public class LFUCache {
    int initCapacity;
    int capacity;
    Map<Integer, Node> memoryNodes;
    Map<Integer, Node> memoryTimes;
    Node head;
    Node tail;

    class Node {
        int key;
        int value;
        int times;
        Node prev;
        Node next;

        public Node(int key, int value, int times) {
            this.key = key;
            this.value = value;
            this.times = times;
        }
    }

    public LFUCache(int capacity) {
        initCapacity = capacity;
        this.capacity = capacity;
        memoryNodes = new HashMap<>();
        memoryTimes = new HashMap<>();
        head = new Node(-1, -1, -1);
        tail = new Node(-1, -1, -1);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (!memoryNodes.containsKey(key)) {
            return -1;
        }
        int value = memoryNodes.get(key).value;
        put(key, value);
        return value;
    }

    public void put(int key, int value) {
        if (initCapacity == 0) {
            return;
        }
        if (memoryNodes.containsKey(key)) {
            Node node = memoryNodes.get(key);
            node.value = value;
            if (memoryTimes.containsKey(node.times + 1)) {
                if (memoryTimes.get(node.times) == node) {
                    if (node.next.times == node.times) {
                        memoryTimes.put(node.times, node.next);
                    } else {
                        memoryTimes.remove(node.times);
                    }
                }
                node.prev.next = node.next;
                node.next.prev = node.prev;
                node.prev = memoryTimes.get(node.times + 1).prev;
                node.next = memoryTimes.get(node.times + 1);
                node.next.prev = node;
                node.prev.next = node;
                memoryTimes.put(node.times + 1, node);
            } else {
                if (memoryTimes.get(node.times) != node) {
                    node.prev.next = node.next;
                    node.next.prev = node.prev;
                    node.prev = memoryTimes.get(node.times).prev;
                    node.next = memoryTimes.get(node.times);
                    node.next.prev = node;
                    node.prev.next = node;
                } else {
                    if (node.next.times == node.times) {
                        memoryTimes.put(node.times, node.next);
                    } else {
                        memoryTimes.remove(node.times);
                    }
                }
                memoryTimes.put(node.times + 1, node);
            }
            node.times++;
        } else {
            Node node = new Node(key, value, 1);
            memoryNodes.put(key, node);
            if (capacity == 0) {
                Node nodeToRemove = tail.prev;
                if (memoryTimes.get(nodeToRemove.times) == nodeToRemove) {
                    memoryTimes.remove(nodeToRemove.times);
                }
                nodeToRemove.prev.next = nodeToRemove.next;
                nodeToRemove.next.prev = nodeToRemove.prev;
                memoryNodes.remove(nodeToRemove.key);
                capacity++;
            }
            if (memoryTimes.containsKey(1)) {
                node.prev = memoryTimes.get(1).prev;
                node.next = memoryTimes.get(1);
            } else {
                node.prev = tail.prev;
                node.next = tail;
            }
            node.prev.next = node;
            node.next.prev = node;
            memoryTimes.put(1, node);
            capacity--;
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */