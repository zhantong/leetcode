class MedianFinder {
public:
    priority_queue<int> minHeap;
    priority_queue<int> maxHeap;

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        maxHeap.push(-num);
        minHeap.push(-maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(-minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (minHeap.top() - maxHeap.top()) / 2.0;
        }
        return -maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */