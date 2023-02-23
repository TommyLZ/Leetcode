#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {

        // ���ַ�����������б���
        for (const auto &p: ori) {

            // ��ǰ�ڳ��ַ����ϵı�����Χ�������鲢������ori�е�ͳ������
            if (cnt[p.first] < p.second) {
                return false;
            }

        }
        return true;
    }

    string minWindow(string s, string t) {

        for (const auto &c: t) {
            ++ori[c]; // ͳ�ƶ�Ӧ�ַ�����
        }

        int l = 0, r = -1;

        int len = INT_MAX, ansL = -1;

        // ע�⣺s.size()�ķ���ֵsize_t���޷��ŵ�����
        // r�ĳ�ֵΪ-1, ��߷���λΪ1
        // �з��������޷������Ƚϴ�С���Ὣ�з�����ֱ�ӵ����޷��������бȽ�

        // ���ԣ�Ϊ���ܹ����������ıȽϣ����뽫�޷�����ת�����з�����

        // Ϊ�˱������bug
        // ���ô�д����while (r < int(s.size())) {
        int n = s.size();
        while (r < n){

            // �ҵ�ƥ����ַ�
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]]; // ͳ�Ƹ���
            }

            while (l <= r && check()) {
            // ������ַ�������������Ҫ��
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l; //
                }

            // �ƶ���ָ�룬��ʼ����Χ����
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }

                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};


int main() {
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC", res ;

    res = solution.minWindow(s, t);

    cout << "the result is " << res << endl;
    return 0;
}
