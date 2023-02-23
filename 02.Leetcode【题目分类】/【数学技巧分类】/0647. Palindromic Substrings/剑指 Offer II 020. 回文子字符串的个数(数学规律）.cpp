#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        // ��ѧ����
        // ����Ϊn���ַ���������2n-1���������
        for (int i = 0; i < 2 * n - 1; ++i) { // i��ʾ���Ǳ��

            int l = i / 2, r = i / 2 + i % 2;

            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
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

// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
