#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int ans = INT_MAX;

        vector<int> sums(n + 1, 0);
        // Ϊ�˷�����㣬�� size = n + 1
        // sums[0] = 0 ��ζ��ǰ 0 ��Ԫ�ص�ǰ׺��Ϊ 0 ��Ĭ�ϴ洢�ľ���0��
        // sums[1] = A[0] ǰ 1 ��Ԫ�ص�ǰ׺��Ϊ A[0]
        // �Դ�����

        for (int i = 1; i <= n; i++) { // ����sum����
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {

            // ��һ���ֿ�����˵��
            int target = sums[i - 1] + s; // ����target, ������target - sum[i-1] >= s

            // �� sum ���ҵ���С��target�ĵ�һ��Ԫ��
            auto bound = lower_bound(sums.begin(), sums.end(), target);

            // ���bound�۲����ֵ�ķ���
            // vector<int>::iterator iter = bound; ������ʵ�����Ǹ�ָ�룩
            // cout << "bound = " << *iter << endl;

            // vector.end��ָ�����һ��Ԫ�ص���һ��λ�ã���ʾbound������

            // ���ȷʵ���ڸ�Ԫ�أ�
            if (bound != sums.end()) {

            // static_cast��ǿ������ת������Ҫ��ָ��Ĳ�ת��������

                // ΪʲôҪ�� i-1 �� ��ĿҪ���ǳ���
                // Ϊʲô����Сֵ�� ��ĿҪ������С����
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};


int main() {

    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int s = 7;

    int res = solution.minSubArrayLen(s, nums);

    cout << " the result is " << res << endl;
    return 0;
}

// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
