#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;

        for (char ch: s) {

            // ���ú�������������ķ����Ƿ������ֻ�����ĸ
            if (isalnum(ch)) {
                sgood += tolower(ch); // ���д�Сдת��
            }
        }

        string sgood_rev(sgood.rbegin(), sgood.rend());

        return sgood == sgood_rev;
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
