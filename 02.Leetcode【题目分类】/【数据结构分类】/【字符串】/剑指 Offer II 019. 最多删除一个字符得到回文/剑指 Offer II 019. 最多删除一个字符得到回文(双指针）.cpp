#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {

        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;

        while (low < high) {
            char c1 = s[low], c2 = s[high];

            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};


int main() {

    Solution solution;

    string s = "abca";

    bool res = solution.validPalindrome(s);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
