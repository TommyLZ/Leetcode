# include <iostream>
# include <vector>
using namespace std;

class MaxQueue {
    int q[20000]; // 数组
    int begin = 0, end = 0; // 队头，队尾

public:
    MaxQueue() {
    }

    int max_value() {
        int ans = -1;
        for (int i = begin; i != end; ++i)
            ans = max(ans, q[i]); // 直接使用max函数
        return ans;
    }

    void push_back(int value) {
        q[end++] = value;
    }

    int pop_front() {
        if (begin == end)
            return -1;
        return q[begin++]; // 出队，对头指标改变
    }
};

int main() {
    MaxQueue maxqueue;
    vector<int> res;

    res.push_back(maxqueue.max_value());
    maxqueue.push_back(1);
    maxqueue.push_back(2);
    res.push_back(maxqueue.max_value());
    res.push_back(maxqueue.pop_front());
    res.push_back(maxqueue.max_value());

    for (int i: res) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}
