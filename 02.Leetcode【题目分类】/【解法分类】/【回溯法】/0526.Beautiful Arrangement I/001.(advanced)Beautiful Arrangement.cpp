#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int countArrangement(int n) {
        // 每个数的选与不选对应1和0两种状态,可以用n位的二进制表示
        // 最终,输出的所有符合情况的数组都对应状态1111

        vector<int> f(1 << n); // 使用一维数组(16个存储空间)作为表

        f[0] = 1;   // 任何一个数字都能单独放在第一位,只有一种放法

        for (int mask = 1; mask < (1 << n); mask++) {   // 对每一个状态都进行讨论

            int num = __builtin_popcount(mask); 
            // 该函数返回二进制状态中1的个数, 也表示当前数组中确定的元素的个数.(num=2, n个元素中,前两个元素在数组中被确定了)

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i) && (num % (i + 1) == 0 || (i + 1) % num == 0)) {
                // 与运算 mask & (1 << i) 表示取mask二进制表示的第i位, 第i位索引位置对应的数字为(i+1)
                // 这个与操作相当于过滤
                // 在内循环中不断增加, 如果mask对应的第i位为0,程序执行就不会进入这个if语句
                // 第i位为0,在下面的转移方程中,执行异或的时候就是0和1异或,结果为1, 但是当前mask的结果f[mask]是不可能通过这样的状态转移过来的

                    f[mask] += f[mask ^ (1 << i)]; // 移位的所有可能情况(1000, 0100, 0010, 0001)
                // mask ^ (1 << i)是将mask的第i位进行取反,第i位为0
                // f(0111)可以从f(0011),f(0101),f(0110)这三个状态转移过来,将它们的方案数进行累加
                }
            
            }

        }
        return f[(1 << n) - 1];
    }
};


int main() {
    Solution solution;
    int n = 2;
    int ans = 0;

    ans = solution.countArrangement(n);
 
    cout << "answer: " << ans << endl;

    return 0;
}