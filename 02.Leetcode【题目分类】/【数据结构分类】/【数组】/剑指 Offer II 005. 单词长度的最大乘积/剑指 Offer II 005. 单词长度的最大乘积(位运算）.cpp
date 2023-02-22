#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();

        vector<int> masks(length); // ������������

        for (int i = 0; i < length; i++) { // �����ַ�������
            string word = words[i];
            int wordLength = word.size();

            for (int j = 0; j < wordLength; j++) { // ��鵥���ַ���
                masks[i] |= 1 << (word[j] - 'a'); // ���ƣ�λ�����㣬����1 ���γ����룩
            }
        }

        int maxProd = 0;

        for (int i = 0; i < length; i++) {

            for (int j = i + 1; j < length; j++) {

                if ((masks[i] & masks[j]) == 0) { // û����ͬ���������£��Գ˻��ĳ��Ƚ��и���
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }

        }

        return maxProd;
    }
};


int main() {
    Solution solution;
    vector<string> words = {"abcw","baz","foo","bar","fxyz","abcdef"};

    int res = solution.maxProduct(words);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(L + n ^ 2) L�������������ַ�������֮��
// �ռ临�Ӷȣ�O(n)
