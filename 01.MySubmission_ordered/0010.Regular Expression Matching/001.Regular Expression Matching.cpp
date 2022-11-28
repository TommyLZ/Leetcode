// 动态规划
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&] (int i, int j) {
            if (i == 0) {
                return false;
            }

            if (p[j-1] == '.') {
                return true;
            }

            return s[i-1] = p[j-1];
        }

        vector<

    }
};

int main () {
    return 0;
}