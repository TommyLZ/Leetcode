// �����Чλ

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);

        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i >> 1] + (i & 1); // �Զ���λ
        }
        // i & 1 �Ľ����bool�ͣ�������ʽת����int����

        return bits;
    }
};

int main() {
    Solution solution;
    int n = 2;
    vector<int> res;
    res = solution.countBits(n);

    for (int i: res) {
        cout << res[i] << " ";
    }

    cout << endl;
    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
