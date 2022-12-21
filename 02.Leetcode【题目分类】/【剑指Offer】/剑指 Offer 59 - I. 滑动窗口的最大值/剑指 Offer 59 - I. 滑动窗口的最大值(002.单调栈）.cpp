#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        deque<int> q;   // 双向开口的连续线性空间

        // 第一个分组：
        for (int i = 0; i < k; ++i) { // q中存储当前分组最大值对应的索引
            while (!q.empty() && nums[i] >= nums[q.back()]) { // 和优先队列法相比这里不用再执行队列内的排序
                q.pop_back();
            }

            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};

        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);

            while (q.front() <= i - k) { // 当前最大值不在数组中
                q.pop_front();
            }

            ans.push_back(nums[q.front()]);
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

// 时间复杂度：O(n)
// 空间复杂度：O(k)
