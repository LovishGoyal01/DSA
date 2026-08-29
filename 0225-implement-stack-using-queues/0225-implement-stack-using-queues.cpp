class MyStack {
public:
    queue<int>q;
    int i;
    MyStack() {
        i=0;
    }
    
    void push(int x) {
        q.push(x);
        int k=i;
        while(k>0){
            q.push(q.front());
            q.pop();
          k--;
        }
        i++;
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        i--;
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return i==0;
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