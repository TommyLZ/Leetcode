#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();

        if (n > m) {
            return false;
        }

        vector<int> cnt1(26), cnt2(26); // ͳ���ַ��ĸ���

        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a']; // ͳ��s1��Ӧ�ַ��ĸ���
            ++cnt2[s2[i] - 'a']; // ͳ��s2�д��ڶ�Ӧ�ַ��ĸ���
        }

        if (cnt1 == cnt2) { // �Ǳ�λ��
            return true;
        }


        for (int i = n; i < m; ++i) { //

            ++cnt2[s2[i] - 'a']; // ������ǰ�ƶ�

            --cnt2[s2[i - n] - 'a']; // �Ӵ����˳�һ��Ԫ��

            if (cnt1 == cnt2) {
                return true;
            }
        }

        return false;
    }
};


int main() {
    Solution solution;

    string str1 = "ab", str2 = "eiifhoanab";

    bool res = solution.checkInclusion(str1, str2);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n+m*��): ��������֮��ıȽ�ʱ�临�Ӷ�ΪO(��)
// �ռ临�Ӷ�: O(��)
