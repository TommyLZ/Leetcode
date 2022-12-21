#include <iostream>
#include <queue>
using namespace std;

class Solution {

    // ���� x ����λ֮��
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

        // ���Һ����µķ�������
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};

        // ��ʼ��
        vector<vector<int>> vis(m, vector<int>(n, 0));  // ���λ��0��ʾδ���ʹ�
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;

        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            for (int i = 0; i < 2; ++i) {   // ������ת��
                int tx = dx[i] + x;
                int ty = dy[i] + y;

                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) // �޷�����ø�
                    continue;

                Q.push(make_pair(tx, ty));  // ������ȱ���

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

// ʱ�临�Ӷȣ�O(mn)
// �ռ临�Ӷ�: O(mn)
