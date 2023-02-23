#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < right) {
            // ɸѡ
            while (left < right && !isalnum(s[left])) {
                ++left;
            }

            while (left < right && !isalnum(s[right])) {
                --right;
            }

            // ɸѡ���֮��
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string  s =  "A man, a plan, a canal: Panama";

    bool res = solution.isPalindrome(s);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(|s|)
// �ռ临�Ӷȣ�O(1)
