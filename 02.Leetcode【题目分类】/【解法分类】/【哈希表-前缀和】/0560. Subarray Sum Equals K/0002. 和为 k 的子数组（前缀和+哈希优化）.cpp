#include <iostream>
#include <vector>
using namespace std;


// �Լ�дһ�����飬Ȼ���ճ�����һ��������
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // Ҳ����Ҫ������

        int count = 0, pre = 0;

        // ��Ŀ���������飬���鵱�п��ܴ��ڸ���
        for (auto& x:nums) {
            pre += x; // �ۼӺ�

            // �ҵ�����k�Ĵ洢�ڹ�ϣ���е��ۼӺ�
            if (mp.find(pre - k) != mp.end()) {

                count += mp[pre - k];
                // ���������ͳ���ظ��𣿣�������֤������ͳ���ظ���
                // ��ѧԭ��pre-k���ֵ���ֹ����ٴΣ���˵���Ӷ�Ӧλ�õ����ڵ�pre�м�������������
            }

            mp[pre]++; // ͬһ��pre�����ɶ�������ó���ͳ��pre�������ۼӹ����г��ֵĴ���
        }
        return count;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,1,1};
    int k = 2, res;

    res = solution.subarraySum(nums, k);

    cout << " the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
