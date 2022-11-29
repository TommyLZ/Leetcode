#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> rec; // 所有的排列结果都用该数组来装
    vector<int> vis;    // 标记数组

    void backtrack(const string& s, int i, int n, string& perm) {
        if (i == n) {   // 找到了一个可行的解
            rec.push_back(perm);
            return;
        }

        for (int j = 0; j < n; j++) {   // 标记数组
            if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) { // 已经使用过该字符 或者 相邻两个字符重复
                continue;   // 避免重复
            }
            vis[j] = true;
            perm.push_back(s[j]);   
            backtrack(s, i + 1, n, perm);
            perm.pop_back();
            vis[j] = false;
        }
    }

    vector<string> permutation(string s) {
        int n = s.size();
        vis.resize(n);  // 标记数组
        sort(s.begin(), s.end()); // 按照字符升序排列
        string perm;    // 当前排列
        backtrack(s, 0, n, perm);
        return rec;
    }
};

int main() {
    Solution solution;
    
    string s = "abc";
    vector<string> rec = solution.permutation();

    for (string s: rec) {
        cout << s << endl;
    }

    return 0;
}

// 时间复杂度: O(n!)
// 空间复杂度：O(n)