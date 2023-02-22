// ���ٳ�
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        // ���Ǳ�����Ϊ��Сֵ�����
        if (a == INT_MIN) {
            if (b == 1) {
                return INT_MIN;
            }
            if (b == -1) {
                return INT_MAX;
            }
        }
        // ���ǳ���Ϊ��Сֵ�����
        if (b == INT_MIN) {
            return a == INT_MIN ? 1 : 0;
        }
        // ���Ǳ�����Ϊ 0 �����
        if (a == 0) {
            return 0;
        }

        // һ�������ʹ������ֲ���
        // �����е�����ȡ�෴����������ֻ��Ҫ����һ�����
        bool rev = false;
        if (a > 0) {
            a = -a;
            rev = !rev;
        }
        if (b > 0) {
            b = -b;
            rev = !rev;
        }


        vector<int> candidates = {b};

        // ע�����
        while (candidates.back() >= a - candidates.back()) {
            candidates.push_back(candidates.back() + candidates.back());
        }

        int ans = 0;

        // ʵ�����������ڹ����̵Ķ����Ʊ�ʾ��ʽ
        // ʵ����������е��Ƕ��ֲ��ң����ϱ��left��right�ķ�Χ��
        for (int i = candidates.size() - 1; i >= 0; --i) {

            if (candidates[i] >= a) {
                ans += (1 << i); // ����2��i�η�
                a -= candidates[i];
            }

        }

        return rev ? -ans : ans;
    }
};


int main() {
    Solution solution;

    int a = 15, b = 2;

    int res = solution.divide(a, b);

    cout << "the result is: " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(logC): C��ʾ32λ�����ķ�Χ
// �ռ临�Ӷȣ�O(1)
