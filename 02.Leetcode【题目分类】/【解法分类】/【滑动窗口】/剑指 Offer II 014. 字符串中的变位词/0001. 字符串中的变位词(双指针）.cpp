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
            --cnt[s1[i] - 'a'];     // ����ͳ��
        }

        int left = 0;

        // ����˼·���ڱ�֤cnt����������£�ȥ�����Ƿ����һ�����䣬�䳤��ǡ����n
        for (int right = 0; right < m; ++right) {
        // rightһֱ����ǰ�ƶ�

            int x = s2[right] - 'a'; // ��ǰ�ַ�
            ++cnt[x]; // ����ǰ�ַ�����˫ָ��ķ�Χ��

            // ���������cnt��ʲô��Ҫ��ϵ��
            // ��rightָ���Ԫ�ض�Ӧ��cntС��0����0ʱ��˵����s1���ж�Ӧ��
            // ��rightָ���Ԫ�ض�Ӧ��cnt����0ʱ��˵����s1��ȣ������˶������ĸ�����������໹�������ϣ�
            // Ҳ����˵rightָ���Ԫ�ز����ڿ��ǵķ�Χ��
            // ����right����ѭ��һֱ�ڲ��������ƶ�������Ϊ�˽�������ڷ�Χ�ڵ����ų�����
            // leftҲ��ִ��++������ͬʱ��leftָ���Ԫ�ر��ų����˷�Χ֮�⣬��Ӧ��cnt��Ҫִ��--
            while (cnt[x] > 0) { // ˵��ָ�뷶Χ��x̫����,
                --cnt[s2[left] - 'a']; // �����뿪�ַ��������cnt
                ++left; // ��ָ������
            }

            // ������left���ƶ�����cnt[x]���͵�0��ʱ�򣬼��˫ָ��֮��ľ���
            if (right - left + 1 == n) { // ˫ָ�����䳤�ȸպ�Ϊnʱ���ҵ��Ӵ�
                return true;
            }
        }

        return false;
    }
};


int main() {
    Solution solution;

    string str1 = "ab", str2 = "eiifhoanab";

    bool res = solution.checkInclusion(str1, str2);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n+m+��) --> ����cnt��ҪO(��)ʱ��
// �ռ临�Ӷ�: O(��)
