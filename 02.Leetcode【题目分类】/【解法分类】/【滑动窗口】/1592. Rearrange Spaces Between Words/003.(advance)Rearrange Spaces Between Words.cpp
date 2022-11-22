#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution{
public:
    string reorderSpace(string text) {
        vector<string> vec; // 使用数组保存单词
        stringstream in(text); // 构造string流
        string word, ans;
        int cnt = 0;

        while (in >> word) { // 将word数据传递给stringstream对象(自动拆解单词)
            vec.push_back(word);
            cnt += word.size(); // 记录单词总长度
        }

        if (vec.size() == 1) {   // 如果只有一个单词，单独处理（因为后面的空格数是不可控的）
            ans = vec[0];  
        }
        else {
            string space((text.size()-cnt) / (vec.size()-1), ' '); // 生成单词之间的空格

            for (int i = 0; i<vec.size()-1; ++i) {   // 重新生成字符串，最后一个单独处理
                ans += vec[i] + space;
            }

            ans += vec.back(); // 连接最后一个单词
        }

        return ans + string(text.size() - ans.size(), ' '); // 将剩余空格补齐，返回
    }
};

int main() {
    Solution solution;
    string text = "  this   is  a sentence ";
    string ans;

    ans = solution.reorderSpace(text);

    cout << "answer: " << ans << endl;
    return 0;
}