#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sums; // 属性：存储前缀和

    NumMatrix(vector<vector<int>>& matrix) {

        int m = matrix.size();

        if (m > 0) {
            int n = matrix[0].size();

            sums.resize(m, vector<int>(n + 1)); // 给属性分配空间

            for (int i = 0; i < m; i++) { // 建立前缀和数组
                for (int j = 0; j < n; j++) {
                    sums[i][j + 1] = sums[i][j] + matrix[i][j];
                }
            }

        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for (int i = row1; i <= row2; i++) {    // 使用差来完成
            sum += sums[i][col2 + 1] - sums[i][col1];
        }

        return sum;
    }
};

int main() {

    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};
    NumMatrix numMatrix(matrix);

    int res1 = numMatrix.sumRegion(2, 1, 4, 3);
    int res2 = numMatrix.sumRegion(1, 1, 2, 2);
    int res3 = numMatrix.sumRegion(1, 2, 2, 4);

    cout << "the result1 is " << res1 << endl;
    cout << "the result2 is " << res2 << endl;
    cout << "the result3 is " << res3 << endl;

    return 0;
}
