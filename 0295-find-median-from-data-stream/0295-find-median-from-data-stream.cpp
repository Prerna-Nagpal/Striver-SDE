class MedianFinder {
public:
priority_queue<int>small;
priority_queue<int,vector<int>,greater<int>>large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if((small.size()-large.size())>1){
            large.push(small.top());
            small.pop();
        }
        if(!large.empty() && small.top()>large.top()){
            large.push(small.top());
            small.pop();
            if(large.size()-small.size()>1){
                small.push(large.top());
                large.pop();
            }

        }
    
    }
    
    double findMedian() {
        int sum = small.size()+large.size();
        if(sum%2){
            int mini = min(small.size(),large.size());
            if(small.size()>mini) return small.top();
            return large.top();
        }
        return (small.top()+large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */