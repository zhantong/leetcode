public class LRUCache {
    int capacity;
    Map<Integer, Node> memory;
    Node head;
    Node tail;

    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        memory = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (memory.containsKey(key)) {
            Node node = memory.get(key);
            toHead(node);
            return node.value;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (memory.containsKey(key)) {
            Node node = memory.get(key);
            node.value = value;
            toHead(node);
        } else {
            if (memory.size() == capacity) {
                memory.remove(tail.prev.key);
                remove(tail.prev);
            }
            Node node = new Node(key, value);
            memory.put(key, node);
            add(node);
        }
    }

    void toHead(Node node) {
        remove(node);
        add(node);
    }

    void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    void add(Node node) {
        node.next = head.next;
        head.next = node;
        node.prev = head;
        node.next.prev = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */