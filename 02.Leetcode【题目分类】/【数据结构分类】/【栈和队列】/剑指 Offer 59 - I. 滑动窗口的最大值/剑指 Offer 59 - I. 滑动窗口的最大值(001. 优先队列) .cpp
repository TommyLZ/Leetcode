#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> q; // ���ȼ�����

        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i); // �洢��ʽ��(nums, index), ���ս����Զ�����
        }

        vector<int> ans = {q.top().first};

        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);

            while (q.top().second <= i - k) { // ��ǰ���Ԫ�ض�Ӧ������û���ڻ���������
                q.pop();
            }

            ans.push_back(q.top().first);
        }

        return ans;
    }
};


int main() {
    int k = 3;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};

    Solution solution;

    vector<int> res = solution.maxSlidingWindow(nums, k);

    for (int i = 0; i< res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}

// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
