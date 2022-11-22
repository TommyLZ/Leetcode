#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
        vector<vector<int>> match;  // 二维数组
        vector<int> vis;    // 标记哪些数被使用过
        int num;    // 最终需要返回的统计结果

        void backtrack(int index, int n) {
            if (index == n+1){  // 如果,数组的空位都被数字填满
                num ++; // 统计结果加一
            }

            for (auto &x: match[index]) {   // 开始对index位置的符合条件的取值进行尝试
                if (!vis[x]) {  // x没有被使用过(vis数组在初始化的时候应该默认为0)
                    vis[x] = true;  // 使用过(表示index防止数x)
                    backtrack(index + 1, n);    // 开始考虑index + 1位置能够进行存储的数据
                    vis[x] = false; // 将该取值恢复至未使用,尝试在index位置进行下一符合条件的取值
                }
            }
        }

        int countArrangement(int n) {
            vis.resize(n + 1);  // 直接进行空间的分配, 避免了索引和i之间需要加一的关系
            match.resize(n + 1);

            for (int i=1; i<=n; i++) {  // 用i表示一维数组的索引

                for (int j=1; j<=n; j++) {  
                    if (i % j == 0 || j % i == 0) { // 将能够被索引整除,或者能够整数索引的数存入索引i对应的行
                        match[i].push_back(j);  
                    }
                }

            }

            backtrack(1, n);    // backtrack(index, n), 表示尝试向位置index放入数, n表示排列的长度
            return num;
        }
};

int main() {
    Solution solution;
    int n = 2;
    int ans = 0;

    ans = solution.countArrangement(n);
 
    cout << "answer: " << ans << endl;

    return 0;
}