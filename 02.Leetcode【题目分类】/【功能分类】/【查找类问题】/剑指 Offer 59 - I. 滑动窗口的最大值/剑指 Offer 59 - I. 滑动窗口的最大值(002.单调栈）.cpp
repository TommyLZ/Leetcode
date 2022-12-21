#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        deque<int> q;   // ˫�򿪿ڵ��������Կռ�

        // ��һ�����飺
        for (int i = 0; i < k; ++i) { // q�д洢��ǰ�������ֵ��Ӧ������
            while (!q.empty() && nums[i] >= nums[q.back()]) { // �����ȶ��з�������ﲻ����ִ�ж����ڵ�����
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

            while (q.front() <= i - k) { // ��ǰ���ֵ����������
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

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(k)
