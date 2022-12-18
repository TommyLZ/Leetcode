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
        if (remainder == 0) {
            return (int)pow(3, quotient);
        }
        else if (remainder == 1) {
            return (int)pow(3, quotient-1) * 4;
        }
        else if (remainder == 2) {
            return (int)pow(3, quotient) * 2;
        }
    }
};

int main()
{
    Solution solution;
    int n = 10;
    int res = solution.cuttingRope(n);

    cout << "the result is: " << res << endl;
    return 0;
}

//ʱ�临�Ӷȣ�O(1)
//�ռ临�Ӷȣ�O(1)
