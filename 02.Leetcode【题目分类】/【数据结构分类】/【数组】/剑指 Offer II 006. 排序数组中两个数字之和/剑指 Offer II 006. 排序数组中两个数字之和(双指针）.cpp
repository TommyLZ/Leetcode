// 前提是排好序
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;

        while (low < high) {

            int sum = numbers[low] + numbers[high];

            if (sum == target) {
                return {low, high};
            } else if (sum < target) {

                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
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

