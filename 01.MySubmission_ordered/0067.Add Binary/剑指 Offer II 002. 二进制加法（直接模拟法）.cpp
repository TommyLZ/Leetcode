#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:

    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;

        for (int i = 0; i < n; ++i) {

            // �߼�: i��a�ĳ��ȷ�Χ����a[i]ֵΪ1, carry = carry + 1;
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;

            ans.push_back((carry % 2) ? '1' : '0'); // ��ʵ��λ��������λ������������0�����������λΪ0��û�в�������λΪ1

            carry /= 2; // ������Ƕ���һλ�Ľ�λ�� ������ǰ�ݽ�
        }

        if (carry) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end()); // ������ת

        return ans;
    }

};

int main() {

    Solution solution;
    string a = "1010", b = "1011", res;

    res = solution.addBinary(a, b);

    cout << "the result is " << res << endl;
    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
