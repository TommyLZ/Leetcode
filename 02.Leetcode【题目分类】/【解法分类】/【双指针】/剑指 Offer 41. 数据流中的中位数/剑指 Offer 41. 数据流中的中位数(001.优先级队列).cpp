// 优先级队列
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

class MedianFinder {
public:
    // 优先级队列
    // 默认队列头部的元素优先级最高

    //<存储对象的类型，存储对象的底层容器，less(降序)/ greater(升序）>
    priority_queue<int, vector<int>, less<int>> queMin; // 记录大于中位数的数 (less 表示降序队列）
    priority_queue<int, vector<int>, greater<int>> queMax;  // 记录小于中位数的数 (greater 表示升序排列)
    // 将元素push进入后，优先级队列会自己排序

    MedianFinder() {}

    void addNum(int num) {

        if (queMin.empty() || num <= queMin.top()) {    // 空队列 || 小于等于queMin中的队首值（最大值）
            // 说明num属于que.Min, 将其进行push
            queMin.push(num);   // 优先级队列会自动进行排序，保持降序

            if (queMax.size() + 1 < queMin.size()) {    // Min的元素个数只能多出Max元素个数一个 （否则：执行下列语句）
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else {  //否则, num属于queMAX
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

// 时间复杂度：O(log n)：排序开销
// 空间复杂度：O(n): 优先级队列的开销
