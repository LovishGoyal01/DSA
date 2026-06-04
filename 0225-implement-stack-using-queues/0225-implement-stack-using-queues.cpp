class MyStack {
public:
    queue<int>q;
    int size=0;
    MyStack() {
        
    }
    
    void push(int x) {
       q.push(x);
       int i=1;
       while(i<=size){
        q.push(q.front());
        q.pop();
        i++;
       }
       size++;
    }
    
    int pop() {
      if(size==0) return -1;
      int val=q.front();
      q.pop();  
      size--; 
      return val;
    }
    
    int top() {
       return q.front();
    }
    
    bool empty() {
        return size==0;
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