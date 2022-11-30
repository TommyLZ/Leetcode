#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution{
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {    
        if (board[i][j] != s[k]) {
            return false;
        } 
        else if (k == s.length() - 1) { // 匹配结束
            return true;
        }
        
        // 相等，当时并没有匹配结束
        visited[i][j] = true;  // 当前匹配成功

        // 继续下一个方向的匹配
        vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 下， 上， 右， 左
        bool result = false;    // 最终结果设置
        for (const auto& dir: directions) { // 引用，每次循环都是一个方向
            int newi = i + dir.first, newj = j + dir.second;    // 转换方向
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {  // 在没有越界的情况下
                if (!visited[newi][newj]) { // 在对应元素没有被访问过的情况下
                    bool flag = check(board, visited, newi, newj, s, k+1);  // 进行匹配
                    if (flag) { // 匹配成功
                        result = true;
                        break;
                    }
                }
            }
        }

        visited[i][j] = false; // 恢复状态

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(); // 行数
        int w = board[0].size(); // 列数
        vector<vector<int>> visited(h, vector<int>(w)); // 标记数组
        for (int i = 0; i < h; ++i) {   // 纵向
            for (int j = 0; j < w; j++) {   // 横向
                bool flag = check(board, visited, i, j, word, 0);
                
                if (flag) {
                    return true;
                }
            }
        }

    return false;
    }

};

int main() {
    Solution solution;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    bool res = solution.exist(board, word);

    cout << res << endl;
    return 0;
}