#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();

        vector<int> masks(length); // 定义掩码数组

        for (int i = 0; i < length; i++) { // 遍历字符串数组
            string word = words[i];
            int wordLength = word.size();

            for (int j = 0; j < wordLength; j++) { // 检查单个字符串
                masks[i] |= 1 << (word[j] - 'a'); // 右移：位或运算，保留1 （形成掩码）
            }
        }

        int maxProd = 0;

        for (int i = 0; i < length; i++) {

            for (int j = i + 1; j < length; j++) {

                if ((masks[i] & masks[j]) == 0) { // 没有相同掩码的情况下，对乘积的长度进行更新
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

// 时间复杂度：O(L + n ^ 2) L是数组中所有字符串长度之和
// 空间复杂度：O(n)
