// 题解很精彩

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return vector<int>{i+1, j+1};
            }

        }

        return vector<int>{-1, -1};
    }
};

int main() {
    Solution solution;
    int target = 8;
    vector<int> numbers = {1,2,4,6,10}, res;

    res = solution.twoSum(numbers, target);

    for (int i: res) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度: O(1)

