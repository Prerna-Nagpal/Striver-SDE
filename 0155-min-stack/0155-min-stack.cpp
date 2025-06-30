class MinStack {
public:
stack<long long>st;
long long mini=INT_MAX,el;
    MinStack() {
        
    }
    
    void push(int val) {
       if(st.empty()) {st.push(val);
       mini=val;}
       else{
        if(val>mini) st.push(val);
        else{
            st.push(val-mini+val);
            mini=val;
        }
       }
    }
    
    void pop() {
       if(st.empty()) return;
       long long ele = st.top();
       st.pop();
       if(ele<mini) mini = (2*mini)-ele;
    }
    
    int top() {
       if(st.empty()) return INT_MAX;
       long long ele=st.top();
       if(ele>mini) return ele;
       return mini;
        
    }
    
    int getMin() {
      return mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */