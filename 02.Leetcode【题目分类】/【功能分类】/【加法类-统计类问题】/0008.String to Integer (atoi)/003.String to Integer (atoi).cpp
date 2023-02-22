#include <iostream>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int res = 0, sign = 1, i = 0, n = s.size();
        
        while(s[i++] == ' ');    // 跳过空格

        -- i;

        if (i < n && (s[i] == '+' || s[i] == '-')) { // 判断符号
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        for (; i < n; ++i) {
            if (s[i] >='0' && s[i] <= '9') {    // 处理数字
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && (s[i] - '0' > 7)) { // 即将溢出 (INT_MAX=2147483647)
                    return (sign + 1) ? INT_MAX : INT_MIN;
                }
                res = res*10 + (s[i]-'0');  // 累加
            }
            else{   // 其他符号
                break;
            }
        }

        return res * sign;
    }
};


int main () {
    Solution solution;

    string s = "4193 with words";

    int res = solution.myAtoi(s);

    cout << "res: " << res << endl;
    return 0;
}