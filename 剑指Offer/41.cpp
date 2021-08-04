/**
 * 41. 数据流中的中位数
 * https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
 */

#include<queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> pq_greater; // 小根堆
    priority_queue<int, vector<int>, less<int>> pq_less; // 大根堆
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(pq_greater.size() == pq_less.size()){
            pq_greater.emplace(num);
            pq_less.emplace(pq_greater.top());
            pq_greater.pop();
        }else{
            pq_less.emplace(num);
            pq_greater.emplace(pq_less.top());
            pq_less.pop();
        }
    }
    
    double findMedian() {
        return pq_greater.size() == pq_less.size() ? (pq_greater.top() + pq_less.top()) / 2.0 : pq_less.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */