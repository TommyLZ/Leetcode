#include <iostream>
#include <queue>
using namespace std;

class Solution {
    int get(int x) {
        int res=0;
        for (; x; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if (!k)
            return 1;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans = 1;
        vis[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if ((i == 0 && j == 0) || get(i) + get(j) > k)
                    continue;

                // 边界判断
                if (i - 1 >= 0)
                    vis[i][j] |= vis[i - 1][j];

                if (j - 1 >= 0)
                    vis[i][j] |= vis[i][j - 1];

                ans += vis[i][j];
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
