// ���򼯺� + ˫ָ��
#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

class MedianFinder {
    multiset<int> nums; // ���򼯺�
    multiset<int>::iterator left, right;    // �������򼯺϶�Ӧ�ĵ�����

public:
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num) {
        const size_t n = nums.size();  // size_t ʵ���ϲ��������ķ���ֵ, δ��������֮ǰ��ͳ�Ƹ���

        nums.insert(num);   // �����ݲ������򼯺�

        if (!n) {   // δ����num֮ǰ�ǿ�
            left = right = nums.begin();    // ���ص�����
        }
        else if (n & 1) {   // δ����num֮ǰ��������������Ԫ��

            if (num < *left) { // num�ȵ�ǰleftС
                left--;
            }
            else {
                right++;
            }

        }
        else {  // δ����num֮ǰ��������ż����Ԫ��
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
                // ����������ڣ����ֵ��*left��ȣ����򼯺Ͻ�ֵ���뵽left��right�м䣬��������leftָ���ָ���������⣩
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

// ʱ�临�Ӷȣ�O(log n)��������
// �ռ临�Ӷȣ�O(n): ���ȼ����еĿ���
