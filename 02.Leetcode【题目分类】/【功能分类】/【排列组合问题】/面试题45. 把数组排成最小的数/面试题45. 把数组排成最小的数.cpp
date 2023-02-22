# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs; // �ַ������͵�����

        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));

        quickSort(strs, 0, strs.size() - 1);

        string res; // ���ؽ��

        for(string s : strs)
            res.append(s);

        return res;
    }

private:
    void quickSort(vector<string>& strs, int l, int r) {
        if(l >= r)
            return;

        int i = l, j = r;

        // lΪ���������Ԫ�أ�����ѭ�����൱����lΪ��׼����������
        while(i < j) {

            while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j)
                j--;

            while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j)
                i++;

            swap(strs[i], strs[j]);
        }

        swap(strs[i], strs[l]); // ��l��Ӧ��Ԫ�طŻ�������Ӧ������������ȷ��λ��

        quickSort(strs, l, i - 1); // �Է����ظ����в���
        quickSort(strs, i + 1, r);
    }
};

int main() {

    Solution solution;
    vector<int> nums = {3, 30, 34, 5, 9};

    string res = solution.minNumber(nums);

    cout << "the result is: " << res << endl;

    return 0;
}

// ʱ�临�Ӷ�: O(nlogn)
// �ռ临�Ӷȣ�O(n)
