//Brian Kernighan方法

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countOnes(int x) {
        int ones = 0;

        while (x > 0) { // 操作的执行次数就是1的个数
            x &= (x - 1);
            ones++;
        }

        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n + 1); // 从0到n，是n+1个数

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


// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
