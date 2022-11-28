#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        stringstream sstream(s); // 将s的值赋给sstream

        int n = 0;
        sstream >> n;   // 将sstream的值转换成整型n

        return n;
    }
};

int main() {
    Solution solution;

    // string s = "     459999999999999999999999999999999999999999999999999999999999999999999999999999999999999999ni gj";
    string s = "  67mj  ";
    int result = solution.myAtoi(s);

    cout << "the result is: " << result << endl;
    return 0;
}

// 时间复杂度O(n)
// 空间复杂度O(1)