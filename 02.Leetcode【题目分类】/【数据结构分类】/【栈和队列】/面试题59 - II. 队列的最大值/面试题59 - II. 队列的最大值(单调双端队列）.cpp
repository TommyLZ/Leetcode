# include <iostream>
# include <queue>
# include <vector>
using namespace std;

class MaxQueue {
    queue<int> q; // 完整的队列
    deque<int> d; // 单调队列
public:
    MaxQueue() {
    }

    int max_value() {
        if (d.empty())
            return -1;
        return d.front(); // 双端队列容器的对头元素
    }

    void push_back(int value) {

        while (!d.empty() && d.back() < value) {
            d.pop_back();  // 删除最后一个数(出队）
        }
        // 出队时间均摊在每个插入操作上，时间复杂度为O(1)

        d.push_back(value); // 入队
        q.push(value);  // 进入完整队列
    }

    int pop_front() { // 队首元素出队
        if (q.empty())
            return -1;

        int ans = q.front();

        if (ans == d.front()) { // 恰好是最大元素出队的话，单调队列中的元素也需要出栈
            d.pop_front();
        }

        q.pop();
        return ans; // 返回队首元素
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

// 时间复杂度：O(1) -> 均摊：
// 空间复杂度：O(n) ->
