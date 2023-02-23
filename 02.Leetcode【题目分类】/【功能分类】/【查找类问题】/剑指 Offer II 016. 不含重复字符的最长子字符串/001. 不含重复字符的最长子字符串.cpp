#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
        unordered_set<char> occ;
        int n = s.size();

        // ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
        int rk = -1, ans = 0;

        // ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1

        for (int i = 0; i < n; ++i) {

            if (i != 0) {
                // ��ָ�������ƶ�һ���Ƴ�һ���ַ�
                occ.erase(s[i - 1]);
            }

            // û��Խ�磬�Ҳ����ظ��ַ�
            while (rk + 1 < n && !occ.count(s[rk + 1])) {

                // ���ϵ��ƶ���ָ��
                occ.insert(s[rk + 1]);
                ++rk;
            }

            // �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s =  "abcabcbb";

    int res = solution.lengthOfLongestSubstring(s);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(��)
