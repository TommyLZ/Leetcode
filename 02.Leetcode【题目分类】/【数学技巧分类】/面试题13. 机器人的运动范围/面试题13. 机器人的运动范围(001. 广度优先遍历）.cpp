#include <iostream>
#include <queue>
using namespace std;

class Solution {

    // 计算 x 的数位之和
    int get(int x) {
        int res=0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }

public:
    int movingCount(int m, int n, int k) {
        if (!k)
            return 1;

        queue<pair<int,int> > Q;    //

        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};

        // 初始化
        vector<vector<int>> vis(m, vector<int>(n, 0));  // 标记位，0表示未访问过
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;

        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            for (int i = 0; i < 2; ++i) {   // 做方向转换
                int tx = dx[i] + x;
                int ty = dy[i] + y;

                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) // 无法到达该格
                    continue;

                Q.push(make_pair(tx, ty));  // 广度优先遍历

                vis[tx][ty] = 1;
                ans++;
            }

        }
        return ans;
    }
};

int main() {
    Solution solution;
    int m = 2, n = 3, k = 1;
    int res = solution.movingCount(m , n, k);
    cout << "the result is: " << res << endl;
    return 0;
}

// 时间复杂度：O(mn)
// 空间复杂度: O(mn)
