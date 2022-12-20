// ��̬�滮
#include <iostream>
using namespace std;

class Solution {
public:
    int translateNum(int num) {

        string src = to_string(num);    // ����������ת�����ַ���

        // �ص㣺״̬ת�Ʒ��̣�dp[i] = dp[i-1] + dp[i-2]���������λ�Ϸ�ʱ��
        // Ϊ�˽�ʡ�ռ䣬��p��ʾdp[i-2], q��ʾdp[i-1], r��ʾ dp[i]
        // ��ʼ����dp[i-2]=0, dp[i-1]=0, dp[i] = dp[0] = 1;
        int p = 0, q = 0, r = 1;

        for (int i = 0; i < src.size(); ++i) {
            // i++֮����Ҫ����dp[i-2]��dp[i-1]
            p = q;  // dp[i-2] = dp[i-1];
            q = r;  // dp[i-1] = res;

            r = 0;  // dp[i]��Ϊ0�����¼���

            r = q; // ����iλ���ֵ������з��룺dp[i] = dp[i-1];

            if (i == 0) {   // ֻ��һ������ʱ������Ҫ������λ������ѭ��
                continue;
            }

            // ����Ϊ��λ�����жϹ��̣�
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {  // ������λ���Ϸ���״̬
                r += p; // dp[i] += dp[i-2], ʵ���Ϸ���״̬ת�Ʒ��� dp[i] = dp[i-1] + dp[i-2]
            }
        }
        return r;
    }
};


int main() {
    Solution solution;

    int num = 12258;
    int res = solution.translateNum(num);

    cout << res << endl;
    return 0;
}

// ʱ�临�Ӷȣ�����ת�������ַ�����ʱ�临�Ӷ���O(logn)����n��ʾ�����Ĵ�С��������ת��֮���ַ����ĳ�����O(log n) ��10Ϊ��
// �ռ临�Ӷȣ���Ȼ�������˹������飬��̬�滮���ֵĿռ������ O(1)�ģ�������������һ����ʱ����������ת�������ַ������ʽ����ռ临�Ӷ���O(logn)��
