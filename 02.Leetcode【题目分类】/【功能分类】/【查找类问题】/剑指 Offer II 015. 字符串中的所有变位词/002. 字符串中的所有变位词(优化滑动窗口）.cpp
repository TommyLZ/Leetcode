#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);

        for (int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;

        for (int j = 0; j < 26; ++j) {
            if (count[j] != 0) {
                ++differ;
            }
        }

        if (differ == 0) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {

            // ��������, ����֮ǰcntֵΪ1,˵�����ڶ���
            // ����֮�󣬼��ٲ��죬������Ҫ����diff��������
            if (count[s[i] - 'a'] == 1) {  // ��������ĸ s[i] ���������ַ��� p �е������Ӳ�ͬ�����ͬ
                --differ;
            } else if (count[s[i] - 'a'] == 0) {  // ��������ĸ s[i] ���������ַ��� p �е���������ͬ��ò�ͬ
                ++differ;
            }
            --count[s[i] - 'a']; // ��s��˵������һ�����Ǽ���


            // ��������
            // ����֮ǰΪ-1��˵�����ˣ�����֮����ٲ��죬����--diff
            if (count[s[i + pLen] - 'a'] == -1) {  // ��������ĸ s[i+pLen] ���������ַ��� p �е������Ӳ�ͬ�����ͬ
                --differ;
            } else if (count[s[i + pLen] - 'a'] == 0) {  // ��������ĸ s[i+pLen] ���������ַ��� p �е���������ͬ��ò�ͬ
                ++differ;
            }

            ++count[s[i + pLen] - 'a'];

            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};


int main() {
    Solution solution;
    string s = "cbaebabacd", p = "abc";

    vector<int> res = solution.findAnagrams(s, p);

    for (int i: res) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n+m+��)-->��������ıȽ���Ҫ�á�ʱ��
// �ռ临�Ӷȣ�O(��)
