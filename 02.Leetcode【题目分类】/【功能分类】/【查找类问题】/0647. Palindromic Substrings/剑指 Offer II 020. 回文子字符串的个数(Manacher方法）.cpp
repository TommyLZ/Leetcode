#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";

        // ͳһ��ż������� ʹ��#�������е���ĸ��ͬʱ��λ���#
        for (const char &c: s) {
            t += c;
            t += '#';
        }

        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0; // ��ָ�룬��ָ��

        // ��Ͻ�������ͼ�������
        // �������޸ĵ��ַ���
        for (int i = 1; i < n; ++i) {

            // ��ʼ�� f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;

            // ������չ �������������߽�����չ��
            while (t[i + f[i]] == t[i - f[i]])
                ++f[i];

            // ��̬ά�� iMax �� rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }

            // ͳ�ƴ�, ��ǰ����Ϊ (f[i] - 1) / 2 ��ȡ��
            ans += (f[i] / 2);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "abc";

    int res = solution.countSubstrings(s);

    cout << "the result is " << res << endl;

    return 0;
}


// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
