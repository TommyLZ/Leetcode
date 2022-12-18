// ��̬�滮���⣨��ѧ���̣���ֳɾ����ܶ��3, ���������ࣩ
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

        int quotient = n / 3 - 1; // Ϊ�˱���������Ϊ1��ʱ��ʹ�ó���
        int remainder = n % 3;
        const int mod = 1e9 + 7;
        long long mul = 1;
        long long x = 3;

        while (quotient) {
            if (quotient & 1) {
                mul = mul * x % mod;
            }

            x = x * x % mod;

            quotient >>= 1;
        }

        if (remainder == 0) {
            return mul * 3;
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

//ʱ�临�Ӷȣ�O(logn)
//�ռ临�Ӷȣ�O(1)
