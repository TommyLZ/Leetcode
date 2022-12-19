// ���ȼ�����
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

class MedianFinder {
public:
    // ���ȼ�����
    // Ĭ�϶���ͷ����Ԫ�����ȼ����

    //<�洢��������ͣ��洢����ĵײ�������less(����)/ greater(����>
    priority_queue<int, vector<int>, less<int>> queMin; // ��¼������λ������ (less ��ʾ������У�
    priority_queue<int, vector<int>, greater<int>> queMax;  // ��¼С����λ������ (greater ��ʾ��������)
    // ��Ԫ��push��������ȼ����л��Լ�����

    MedianFinder() {}

    void addNum(int num) {

        if (queMin.empty() || num <= queMin.top()) {    // �ն��� || С�ڵ���queMin�еĶ���ֵ�����ֵ��
            // ˵��num����que.Min, �������push
            queMin.push(num);   // ���ȼ����л��Զ��������򣬱��ֽ���

            if (queMax.size() + 1 < queMin.size()) {    // Min��Ԫ�ظ���ֻ�ܶ��MaxԪ�ظ���һ�� ������ִ��������䣩
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else {  //����, num����queMAX
            queMax.push(num);

            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {

        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }

        return (queMin.top() + queMax.top()) / 2.0;
    }
};


int main() {
    MedianFinder medianFinder;


    medianFinder.addNum(1);
    medianFinder.addNum(2);
    double res1 = medianFinder.findMedian();
    medianFinder.addNum(3);
    double res2 = medianFinder.findMedian();

    cout << "the result is: " << endl;
    cout << setiosflags(ios::fixed) << setprecision(5) << res1 << endl;
    cout << res2 << endl;
    return 0;
}

// ʱ�临�Ӷȣ�O(log n)��������
// �ռ临�Ӷȣ�O(n): ���ȼ����еĿ���
