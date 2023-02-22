//Brian Kernighan方法

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> bits(n + 1);

        int highBit = 0;

        for (int i = 1; i <= n; i++) {

            if ((i & (i - 1)) == 0) { // 说明i是2的整数幂
                highBit = i;
            }

            // 一般情况下：（动态转移方程）
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

// 时间复杂度：O(n)
// 空间复杂度：O(1)
