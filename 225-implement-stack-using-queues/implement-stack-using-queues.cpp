class MyStack {
    queue<int> q; int n;
public:
    MyStack() {
        n=0;
    }
    
    void push(int x) {
        q.push(x); n++;
    }
    
    int pop() {
        if(n<1) return -1;
        int element;
        for(int i=0; i<n;i++){
            element=q.front();
            q.pop();
            if(i!=n-1) q.push(element);
        }   
        n--;
        return element;
    }
    
    int top() {
        if(n<1) return -1;
        int element;
        for(int i=0; i<n;i++){
            element=q.front();
            q.pop();
            q.push(element);
        }   
        return element;
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */