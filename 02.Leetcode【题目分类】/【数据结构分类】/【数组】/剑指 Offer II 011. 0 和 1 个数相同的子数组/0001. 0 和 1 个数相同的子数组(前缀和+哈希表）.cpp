#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> mp;

        int counter = 0;
        // �洢�������ǰ׺�ͣ� ������Ԫ��1ʱ��counter��ֵ��1��������Ԫ��0ʱ��counter��ֵ��1
        // ����������ʹ�ù�ϣ��洢ÿ��ǰ׺�͵�һ�γ��ֵ��±�

        mp[counter] = -1; // ��ʼ��

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            if (num == 1) {
                counter++;
            } else {
                counter--;
            }

            // �ڹ�ϣ���д��ڣ� ˵����counter֮ǰ������������˵���ٴ������͵�һ������֮��ĺ�Ϊ0--> ˵���˶�0��1�ĸ�������ȵ�
            if (mp.count(counter)) {
                int prevIndex = mp[counter]; // ȡ����һ��������counter������

                maxLength = max(maxLength, i - prevIndex); // ���г��ȱȽ�
            } else {

                mp[counter] = i; // �����һ������������
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 1};
    int k = 2, res;

    res = solution.findMaxLength(nums, k);

    cout << "the result is " << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷ�: O(n)
