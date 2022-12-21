// ��̬�滮 + �������
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6.0);    // ��ʼ����

        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0);   // i�����Ӷ�Ӧ�Ľ������

            for (int j = 0; j < dp.size(); j++) {   // ���ã�i-1�������ӵĸ��ʽ����Ƶ�
                for (int k = 0; k < 6; k++) {
                    tmp[j + k] += dp[j] / 6.0;  // ���׶ȵļ��㣬���һ�����Ӷ�Ӧ�ĸ���������֮һ��������Ҫ����6
                }
            }

            dp = tmp;
        }
        return dp;
    }
};


int main() {
    Solution solution;

    int n = 2;  // ���ӵĸ���

    vector<double> res = solution.dicesProbability(n);

    for (int i = 0; i< res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}

// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(n)
