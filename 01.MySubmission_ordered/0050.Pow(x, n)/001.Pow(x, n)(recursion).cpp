// 递归 + 快速幂
#include <iostream>
using namespace std;
class Solution{
public:
    double quickMul(double x, long long N) {
        if (N==0){
            return 1.0;
        }
        
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N); // 需要考虑到负数幂
    }
};

int main() {
    Solution solution;
    double x = 2.10000;
    long long n = 3;
    double res = solution.myPow(x, n);

    cout << "res: " << res << endl;
    return 0;
}

// 时间复杂度： log(n)
// 空间复杂度： log(n)