#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();

        if (n > m) {
            return false;
        }

        vector<int> cnt(26);

        for (int i = 0; i < n; ++i) {
            --cnt[s1[i] - 'a'];
            ++cnt[s2[i] - 'a'];
        }

        int diff = 0; // ʹ��diff����¼cnt1��cnt2�Ĳ�ֵͬ�ĸ���
        // ת����Ϊ�˱���ÿ�ν��������������бȽϣ�ת�������ж�diff�Ƿ�Ϊ0

        for (int c: cnt) {
            if (c != 0) {
                ++diff; // ͳ�Ʋ�ͬ�ַ��ĸ���
            }
        }

        if (diff == 0) {
            return true;
        }

        for (int i = n; i < m; ++i) {

            int x = s2[i] - 'a', y = s2[i - n] - 'a'; // ����֮��պø���n��

            // x�Ǵ���׼��������ģ�y�Ǵ���׼����������

            if (x == y) {   // ��ȵĻ�����cnt�ļ��㲢������ʲôӰ��
                continue;
            }

            // ������x֮ǰ��cnt[x]ֵΪ0��˵��s1����s2�Ĵ����У�x��ֵ����ȵ�
            // ���ڴ�����������x��������y, ͬʱ�������ܹ�ִ�е���һ����˵��x ������ y
            // ���ԣ����ڴ��ڱ�s1����1��x, ��Ҫִ��diff++
            if (cnt[x] == 0) {
                ++diff;
            }

            ++cnt[x]; // ������ʽ��x ���봰��

            // ��x��ʽ���봰��֮�󣬴��ں�s1��x�ﵽƽ��
            // ˵�����ں�s1�Ĳ����С�����ִ��diff--
            if (cnt[x] == 0) {
                --diff;
            }

            // ͬ��������y֮ǰ��ƽ���
            // ������ʽ������y, ˵�����ڱ�s1����һ��y, ����������
            if (cnt[y] == 0) {
                ++diff;
            }

            --cnt[y]; // ������ʽ�Ӵ�������y


            // ��ʽ����y֮�󣬴ﵽ��ƽ�⣬�����С
            if (cnt[y] == 0) {
                --diff;
            }


            // ÿ�δ����ƶ�������Ҫ�ж�
            if (diff == 0) {
                return true;
            }
        }

        return false; // ����s2�������������̶�û��return ture, ��˵�����ǣ�ֱ�ӷ���
    }
};


int main() {
    Solution solution;

    string str1 = "ab", str2 = "eiifhoanab";

    bool res = solution.checkInclusion(str1, str2);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n+m+��)
// �ռ临�Ӷ�: O(��)
