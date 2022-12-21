#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> q; // 优先级队列

        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i); // 存储格式：(nums, index), 按照降序自动排序
        }

        vector<int> ans = {q.top().first};

        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);

            while (q.top().second <= i - k) { // 当前最大元素对应的索引没有在滑动窗口内
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

// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
