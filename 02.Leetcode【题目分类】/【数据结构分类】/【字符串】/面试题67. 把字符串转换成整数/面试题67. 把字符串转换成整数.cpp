#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Automaton {
    string state = "start"; // ��ʼ״̬

    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) { // ��Ե����ַ�

        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;

        return 3; // ����
    }
public:
    int sign = 1; // ��ǰԤ��һ��ֵ���������ж�
    long long ans = 0;

    void get(char c) {

        state = table[state][get_col(c)]; // ��state����״̬ת��

        if (state == "in_number") {

            ans = ans * 10 + c - '0';

            // �����ǽ���Խ�紦��
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
            // �߼������ﶼ����������������󷵻ؽ����ʱ���ٽ��з��ŵ����
        }
        else if (state == "signed") // �Է��Ž����ж�
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int strToInt(string str) {
        Automaton automaton;
        for (char c : str) // ����ÿһ���ַ�
            automaton.get(c);

        // ����signӦ�÷ŵ����еĲ���
        return automaton.sign * automaton.ans; // ���Ŵ���
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

// ʱ�临�Ӷ�: O(1)
// �ռ临�Ӷȣ�O(n)
