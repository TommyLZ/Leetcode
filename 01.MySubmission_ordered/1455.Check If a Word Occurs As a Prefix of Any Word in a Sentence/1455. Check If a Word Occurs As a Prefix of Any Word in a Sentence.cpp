#include <iostream>

using namespace std;

class Solution{
public:
    bool isPrefix(string sentence, int start, int end, string searchWord) {
        for(int i=0; i<searchWord.size(); ++i){
            if(start + i >= end || searchWord[i] != sentence[start + i] ){ // 句子中的单词太短 || 不匹配
                return false;
            }
        }

        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size(), index = 1, start = 0, end = 0;
        while (start < n){

            while (end < n && sentence[end] != ' ') { // 找到每个单词的末尾, end指向空格/指向句子中的最后一个字母
                end ++;
            }

            if (isPrefix(sentence, start, end, searchWord)) {   //逐个单词进行判断
                return index;
            }

            index ++;   // 尝试下一个单词的匹配
            end ++; // end指向下一个单词的第一个字母/ 超出句子范围

            start = end;    // end指向下一个单词的第一个字母 / 超出句子范围
        }

        return -1;
    }
};

int main(){
    Solution solution;
    string sentence = "i love eating burger";
    string searchWorld = "burg";
    int ans;

    ans = solution.isPrefixOfWord(sentence, searchWorld);

    cout << "ans: " << ans << endl;

    return 0;
}