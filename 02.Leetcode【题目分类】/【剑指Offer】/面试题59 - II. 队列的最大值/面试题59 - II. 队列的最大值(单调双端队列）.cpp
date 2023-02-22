# include <iostream>
# include <queue>
# include <vector>
using namespace std;

class MaxQueue {
    queue<int> q; // �����Ķ���
    deque<int> d; // ��������
public:
    MaxQueue() {
    }

    int max_value() {
        if (d.empty())
            return -1;
        return d.front(); // ˫�˶��������Ķ�ͷԪ��
    }

    void push_back(int value) {

        while (!d.empty() && d.back() < value) {
            d.pop_back();  // ɾ�����һ����(���ӣ�
        }
        // ����ʱ���̯��ÿ����������ϣ�ʱ�临�Ӷ�ΪO(1)

        d.push_back(value); // ���
        q.push(value);  // ������������
    }

    int pop_front() { // ����Ԫ�س���
        if (q.empty())
            return -1;

        int ans = q.front();

        if (ans == d.front()) { // ǡ�������Ԫ�س��ӵĻ������������е�Ԫ��Ҳ��Ҫ��ջ
            d.pop_front();
        }

        q.pop();
        return ans; // ���ض���Ԫ��
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

// ʱ�临�Ӷȣ�O(1) -> ��̯��
// �ռ临�Ӷȣ�O(n) ->
