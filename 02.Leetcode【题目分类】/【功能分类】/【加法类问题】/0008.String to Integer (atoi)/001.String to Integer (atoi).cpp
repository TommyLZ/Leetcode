// 官方解法： 自动机
#include <iostream>
#include <vector>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;
class Automaton {
    string state = "start"; // 第一个状态是开始状态

    // 自动机
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    
    int get_col(char c) {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }
public:
    int sign = 1; // 默认数字是正数，用1表示
    long long ans = 0;
    // 这些变量在类之外都能够进行访问，所以，设置成公有成员变量

    void get (char c) {
        state = table[state][get_col(c)];   // 从start状态开始，根据读到的字符，转移到下一个状态

        if (state == "in_number") {
            ans = ans * 10 + c - '0';   // 数字组装
            ans = sign == 1 ? min(ans, (long long) INT_MAX) : min(ans, -(long long) INT_MIN);   // 注意：强制数字类型转换
            // 正数：ans和最大值中选小的, 防止越界；

            // 注意到在Solution类中，正负号都是在最后返回结果时添加的，所以，这里对于负号，就需要反过来
            // 负数：ans和最小值的绝对值中选小的，防止越界
        }
        else if (state == "signed") {
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;

        for (char c : str) {    // 遍历字符串
            automaton.get(c);
        }

        return automaton.sign * automaton.ans; 
    }
};

int main () {
    Solution solution;

    string s = "4193 with words";

    int res = solution.myAtoi(s);

    cout << "res: " << res << endl;
    return 0;
}

// 时间复杂度O(n)
// 空间复杂度O(1)