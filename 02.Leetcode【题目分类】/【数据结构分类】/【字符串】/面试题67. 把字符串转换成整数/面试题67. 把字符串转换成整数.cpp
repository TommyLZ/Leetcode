#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Automaton {
    string state = "start"; // 初始状态

    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) { // 针对单个字符

        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;

        return 3; // 其他
    }
public:
    int sign = 1; // 提前预设一个值，后面再判断
    long long ans = 0;

    void get(char c) {

        state = table[state][get_col(c)]; // 从state进行状态转移

        if (state == "in_number") {

            ans = ans * 10 + c - '0';

            // 这里是进行越界处理
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
            // 逻辑：这里都按照正数来处理，最后返回结果的时候，再进行符号的添加
        }
        else if (state == "signed") // 对符号进行判定
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int strToInt(string str) {
        Automaton automaton;
        for (char c : str) // 遍历每一个字符
            automaton.get(c);

        // 所以sign应该放到公有的部分
        return automaton.sign * automaton.ans; // 符号处理
    }
};

int main() {
    Solution solution;

    string str = "4193 with words";
    int res;

    res = solution.strToInt(str);

    cout << "the result is " << res << endl;

    return 0;
}

// 时间复杂度: O(1)
// 空间复杂度：O(n)
