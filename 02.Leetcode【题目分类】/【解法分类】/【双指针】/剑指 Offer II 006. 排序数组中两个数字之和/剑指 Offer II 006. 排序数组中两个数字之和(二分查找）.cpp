// ʹ�ö��ֲ��ҵ�ǰ�����ź���
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        for (int i = 0; i < numbers.size(); ++i) {

            int low = i + 1, high = numbers.size() - 1; // ȷ��������Χ

            while (low <= high) {

                int mid = (high - low) / 2 + low;

                if (numbers[mid] == target - numbers[i]) {

                    return {i, mid};

                } else if (numbers[mid] > target - numbers[i]) {

                    high = mid - 1;

                } else {

                    low = mid + 1;

                }
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

// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(1)
