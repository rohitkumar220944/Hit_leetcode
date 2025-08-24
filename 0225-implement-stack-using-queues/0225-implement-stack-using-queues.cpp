class MyStack {
public:
    queue<int>q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
       for(int i=0;i<q.size()-1;i++)
       {
        int front=q.front();
        q.pop();
        q.push(front);
       }
       
    }
    
    int pop() {

        int top=q.front();
        q.pop();
        return top;
        
    }
    
    int top() {
        int top=q.front();
        return top;
        
    }
    
    bool empty() {
        return q.empty();
    }
};

// class MyStack {
// public:
//     queue<int>q1;
//     queue<int>q2;

//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()) 
//         {
//             q2.push(q1.front());
//             q1.pop();
//          }
         
//          while(!q2.empty()) 
//         {
//             q1.push(q2.front());
//             q2.pop();
//          }
       
//     }
    
//     int pop() {

//         int top=q1.front();
//         q1.pop();
//         return top;
        
//     }
    
//     int top() {
//         int top=q1.front();
//         return top;
        
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */