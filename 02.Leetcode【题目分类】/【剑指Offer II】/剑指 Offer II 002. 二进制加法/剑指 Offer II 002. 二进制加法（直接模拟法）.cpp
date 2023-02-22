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

            // 逻辑: i在a的长度范围内且a[i]值为1, carry = carry + 1;
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;

            ans.push_back((carry % 2) ? '1' : '0'); // 核实进位：产生进位（或者是两个0的情况），本位为0，没有产生，本位为1

            carry /= 2; // 这个才是对下一位的进位， 不断向前递进
        }

        if (carry) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end()); // 将答案逆转

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

// 时间复杂度：O(n)
// 空间复杂度：O(1)
