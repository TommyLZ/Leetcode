// ��̬�滮���⣨��ѧ���̣���ֳɾ����ܶ��3��
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution{
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }

        int quotient = n / 3;
        int remainder = n % 3;
        const int mod = 1e9 + 7;
        long long int  mul = 1; // ���������long long, ��ֹmul�ڳ���3��ʱ�򳬳�int����

        for (int i = 1; i < quotient; ++i) {
            mul = mul * 3 % mod;
        }

        if (remainder == 0) {
            return mul * 3 % mod;
        }
        else if (remainder == 1) {
            // return mul / 3 * 4 % mod; // ʹ����ģ֮��Ľ��������������ִ���
            return mul * 4 % mod;
        }
        else {
            return mul * 3 * 2 % mod;
        }   // ���������else�� ������else if������leetcode�ı������ᱨ��
    }
};

int main()
{
    Solution solution;
    int n = 127;
    int res = solution.cuttingRope(n);

    cout << "the result is: " << res << endl;
    return 0;
}

//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(1)
