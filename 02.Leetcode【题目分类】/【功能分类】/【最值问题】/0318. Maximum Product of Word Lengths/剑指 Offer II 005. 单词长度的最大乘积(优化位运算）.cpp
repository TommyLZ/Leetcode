#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {

        unordered_map<int,int> map;

        int length = words.size();

        for (int i = 0; i < length; i++) {

            int mask = 0;
            string word = words[i];
            int wordLength = word.size();

            for (int j = 0; j < wordLength; j++) { // ���ÿ�������γ�λ����
                mask |= 1 << (word[j] - 'a');
            }


            if(map.count(mask)) { // ��ϣ�����Ƿ�����ͬ������--> �У����³���

                if (wordLength > map[mask]) {
                    map[mask] = wordLength;
                }

            } else { // û�� --> ��ʼ������
                map[mask] = wordLength;
            }

        }

        int maxProd = 0;

        for (auto [mask1, _] : map) {

            int wordLength1 = map[mask1];

            for (auto [mask2, _] : map) {

                if ((mask1 & mask2) == 0) {

                    int wordLength2 = map[mask2];
                    maxProd = max(maxProd, wordLength1 * wordLength2); // ֱ��д���ȳ˻������ֵ

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
