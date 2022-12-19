// 有序集合 + 双指针
#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

class MedianFinder {
    multiset<int> nums; // 有序集合
    multiset<int>::iterator left, right;    // 创建有序集合对应的迭代器

public:
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num) {
        const size_t n = nums.size();  // size_t 实际上才是真正的返回值, 未插入数据之前先统计个数

        nums.insert(num);   // 将数据插入有序集合

        if (!n) {   // 未插入num之前是空
            left = right = nums.begin();    // 返回迭代器
        }
        else if (n & 1) {   // 未插入num之前集合中有奇数个元素

            if (num < *left) { // num比当前left小
                left--;
            }
            else {
                right++;
            }

        }
        else {  // 未插入num之前集合中有偶数个元素
            if (num > *left && num < *right) {
                left++;
                right--;
            }
            else if (num >= *right) {
                left++;
            }
            else {
                right--;
                left = right;
                // 该语句必须存在（如果值和*left相等，排序集合将值插入到left和right中间，后续可能left指针的指向会出现问题）
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};


int main() {
    MedianFinder medianFinder;


    medianFinder.addNum(1);
    medianFinder.addNum(0);
    double res1 = medianFinder.findMedian();
    medianFinder.addNum(3);
    double res2 = medianFinder.findMedian();

    cout << "the result is: " << endl;
    cout << setiosflags(ios::fixed) << setprecision(5) << res1 << endl;
    // cout << res2 << endl;
    return 0;
}

// 时间复杂度：O(log n)：排序开销
// 空间复杂度：O(n): 优先级队列的开销
