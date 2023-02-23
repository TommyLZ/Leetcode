#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;

        for (char ch: s) { // ��Ҫ��ɸѡ
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }

        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
           if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
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
// �ռ临�Ӷȣ�O(|s|)
