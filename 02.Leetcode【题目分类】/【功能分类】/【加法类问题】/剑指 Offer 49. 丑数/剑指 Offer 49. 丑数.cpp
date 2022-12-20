// ��̬�滮
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);

        dp[1] = 1;


        int p2 = 1, p3 = 1, p5 = 1;
        // p2, ָ��1, 2, 3, 4, 5, 6�У���ûʹ�ó�2����ĳ�����λ�á���ָ���ǰһλ�Ѿ�ʹ�����˳���2�Ļ��ᡣ
        // p3, ָ��1, 2, 3, 4, 5, 6�У���ûʹ�ó�3����ĳ�����λ�á���ָ���ǰһλ�Ѿ�ʹ�����˳���3�Ļ��ᡣ
        // p5, ָ��1, 2, 3, 4, 5, 6�У���ûʹ�ó�5����ĳ�����λ�á���ָ���ǰһλ�Ѿ�ʹ�����˳���5�Ļ��ᡣ

        // ״̬ת�Ʒ��̣�dp[i] = min(dp[p2]*2, dp[p3]*3, dp[p5]*5)

        for (int i = 2; i <= n; i++) {

            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;

            dp[i] = min(min(num2, num3), num5); // minֻ���������������Բ�������minʵ��

            // ��Ҫ����ÿ�ν��бȽϣ�ȥ��
            if (dp[i] == num2) {
                p2++;
            }

            if (dp[i] == num3) {
                p3++;
            }

            if (dp[i] == num5) {
                p5++;
            }
        }

        return dp[n];
    }
};


int main() {
    Solution solution;
    int n = 10;

    int res = solution.nthUglyNumber(n);

    cout << "the result is :" << res << endl;
    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
