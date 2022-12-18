#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int length = a.size();
        vector<int> answer(length);
        if (length < 1){
            return answer;
        }

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = a[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= a[i];
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> a = {1, 2, 3, 4, 5, 6};

    vector<int> res = solution.constructArr(a);

    for (int i = 0; i < a.size(); i++)
    {
       cout << res[i] <<" ";
    }

    return 0;
}

// 时间复杂度: O(n)
// 空间复杂度：O(1)
