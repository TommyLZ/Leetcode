#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {

        unordered_map<char, vector<int>> index; // <字符, 数组>

        for (int i=0; i<s.size(); ++i) {
            index[s[i]].emplace_back(i);    // 字符串元素加入哈希表, 同一个字符s[i]对应多个值(也就是一个vector)
        }

        int ans = 0;

        for (auto &&[_, arr]: index) {   // 按照字符对哈希表进行遍历[字符串元素(键), 索引(值)]

            // 单独的第一个字符和最后一个字符也应该计入总数之内,所以需要进行插值
            arr.insert(arr.begin(), -1);    // vector第一个位置(begin的位置)插入元素-1
            arr.emplace_back(s.size()); // vector最后一个位置添加字符串长度(必须是字符串的长度,不是arr数组的长度)

            for (int i=1; i<arr.size()-1; ++i) {  // 对同一字符的索引数组进行遍历(注意遍历的范围,防止越界)
                ans += (arr[i] - arr[i-1])*(arr[i+1] - arr[i]); // 同一字符不同索引之间做运算
            }
        }

        return ans;
    
    }
};

int main() {
    Solution solution;
    string s = "ABC";
    int ans = 0;
    
    ans = solution.uniqueLetterString(s);

    cout << "answer: " << ans <<endl;

    return 0;
}