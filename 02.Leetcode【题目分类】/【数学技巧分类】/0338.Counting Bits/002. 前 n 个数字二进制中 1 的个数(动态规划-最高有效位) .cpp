//Brian Kernighan����

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> bits(n + 1);

        int highBit = 0;

        for (int i = 1; i <= n; i++) {

            if ((i & (i - 1)) == 0) { // ˵��i��2��������
                highBit = i;
            }

            // һ������£�����̬ת�Ʒ��̣�
            bits[i] = bits[i - highBit] + 1;
        }

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
