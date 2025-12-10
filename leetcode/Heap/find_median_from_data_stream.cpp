// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> smaller; // largest element first
    priority_queue<int, vector<int>, greater<int>> bigger;  // smallest element first

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smaller.empty() or num <= smaller.top()) {
            smaller.push(num);
        }
        else {
            bigger.push(num);
        }

        if (smaller.size() > bigger.size()) {
            bigger.push(smaller.top());
            smaller.pop();
        }

        if (bigger.size() > smaller.size()) {
            smaller.push(bigger.top());
            bigger.pop();
        }
    }
    
    double findMedian() {
        if (smaller.size() > bigger.size()) {
            return smaller.top();
        }
        if (smaller.size() < bigger.size()) {
            return bigger.top();
        }
        return (bigger.top() + smaller.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */