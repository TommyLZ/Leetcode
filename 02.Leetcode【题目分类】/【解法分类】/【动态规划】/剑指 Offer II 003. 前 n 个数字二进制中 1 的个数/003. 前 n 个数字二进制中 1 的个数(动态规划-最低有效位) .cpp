// 最低有效位

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);

        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i >> 1] + (i & 1); // 自动补位
        }
        // i & 1 的结果是bool型，上面隐式转换成int类型

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
