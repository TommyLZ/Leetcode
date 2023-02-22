#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int length = a.size();

        vector<int> L(length,0), R(length, 0);
        vector<int> answer(length);
        if (length < 1) {   // 需要加入判断，不然会超时
            return answer;
        }

        L[0] = 1;

        for (int i = 1; i < length; i++) {
            L[i] = a[i - 1] * L[i - 1]; // 新值*累乘结果
        }

        // R[i] 为索引 i 右侧所有元素的乘积
        // 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            R[i] = a[i + 1] * R[i + 1];
        }

        // 对于索引 i，除 a[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
        for (int i = 0; i < length; i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> a = {1, 2, 3, 4, 5, 6};

    vector res = solution.constructArr(a);

    for (int i = 0; i < a.size(); i++)
    {
       cout << res[i] <<" ";
    }
    
    return 0;
}

// 空间复杂度： O(n)
// 时间复杂度： O(n)