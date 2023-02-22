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

            for (int j = 0; j < wordLength; j++) { // 针对每个单词形成位掩码
                mask |= 1 << (word[j] - 'a');
            }


            if(map.count(mask)) { // 哈希表中是否有相同的掩码--> 有，更新长度

                if (wordLength > map[mask]) {
                    map[mask] = wordLength;
                }

            } else { // 没有 --> 初始化长度
                map[mask] = wordLength;
            }

        }

        int maxProd = 0;

        for (auto [mask1, _] : map) {

            int wordLength1 = map[mask1];

            for (auto [mask2, _] : map) {

                if ((mask1 & mask2) == 0) {

                    int wordLength2 = map[mask2];
                    maxProd = max(maxProd, wordLength1 * wordLength2); // 直接写长度乘积的最大值

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
