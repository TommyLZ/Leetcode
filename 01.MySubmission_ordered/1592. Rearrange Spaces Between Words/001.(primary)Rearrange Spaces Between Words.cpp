#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string_view> split(const string_view &str, char trim) {
        int n = str.size();
        vector<string_view> res;
        int pos = 0;
        while (pos < n) {
            while (pos < n && str[pos] == trim) {    // 绕开空格
                pos++;
            }
            if (pos < n) {  // 非空格的情况下
                int curr = pos; 
                while(pos < n && str[pos] != trim) { // 统计单词的长度
                    pos++;
                }
                res.emplace_back(str.substr(curr, pos - curr)); // 截取单词长度, 存入字符串数组
            }
        }
        return res;
    }

    string reorderSpaces(string text) {
        int length = text.size();
        vector<string_view> words = split(text, ' '); // 创建一个关于字符串视图的列表(只允许对字符串进行"观测",不允许对字符串进行修改)
        // 实现对单词的裁剪
        int cntSpace = length;
        int wordCount = 0;

        for (auto &word : words) { // 对单词数组进行遍历(针对每个单词)
            if (word.size() > 0) {
                cntSpace -= word.size(); // 从字符串总长度中减去单词长度
                wordCount++; // 统计单词长度
            }
        }

        string ans;

        if (words.size() == 1) {    // 只有一个单词的情况
            ans.append(words[0]); // 将该单词加入最终答案
            for (int i = 0; i < cntSpace; i++) {    // 补充空格
                ans.push_back(' ');
            }
            return ans;
        }

        int perSpace = cntSpace / (wordCount - 1);  // 应用公式(空格数)
        int restSpace = cntSpace % (wordCount - 1); // 末尾剩余空格数

        for (int i = 0; i < words.size(); i++) { // 对单词表进行遍历
            if (words[i].size() == 0) { // 单词长度为0时, 继续下一个单词
                continue;
            }

            if (ans.size() > 0) {   // 答案当中有单词时
                for (int j = 0; j < perSpace; j++) {    
                    ans.push_back(' '); // 添加空格
                }
            }

            ans.append(words[i]);   // 添加单词
        }

        for (int i = 0; i < restSpace; i++) { // 末尾添加剩余空格
            ans.push_back(' ');
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "  this   is  a sentence ";
    string ans;

    ans = solution.reorderSpaces(s);
    
    cout << "answer:" << ans << endl;

    return 0;
}