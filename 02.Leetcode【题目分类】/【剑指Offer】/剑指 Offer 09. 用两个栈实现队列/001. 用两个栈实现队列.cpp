#include <iostream>
#include <stack>
using namespace std;

class CQueue {
private:
    stack<int> inStack, outStack;

    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());   // 查询
            inStack.pop(); // 出栈
        }
    }

public:
    CQueue() {}

    void appendTail(int value) {    // 入队
        inStack.push(value);
    }

    int deleteHead() {  // 出队
        if (outStack.empty()) { // 完成从第一个栈到第二个栈的转移
            if (inStack.empty()) { 
                return -1;
            }

            in2out();
        }

        int value = outStack.top(); // 查询
        outStack.pop(); // 出队
        return value;
    }
};

int main() {
    CQueue queue;

    const int n = 10;
    
    for (int i=0; i<n; ++i) {
        queue.appendTail(i);
    }

    for (int i=0; i<n; ++i) {
        cout << queue.deleteHead() << endl;
    }

    return 0;
}

// 时间复杂度：O(1)
// 空间复杂度: O(n)