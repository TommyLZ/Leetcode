//Brian Kernighan����

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countOnes(int x) {
        int ones = 0;

        while (x > 0) { // ������ִ�д�������1�ĸ���
            x &= (x - 1);
            ones++;
        }

        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n + 1); // ��0��n����n+1����

        for (int i = 0; i <= n; i++) {
            bits[i] = countOnes(i);
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


// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(1)
