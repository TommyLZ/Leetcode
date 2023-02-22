# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs; // 字符串类型的数组

        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));

        quickSort(strs, 0, strs.size() - 1);

        string res; // 返回结果

        for(string s : strs)
            res.append(s);

        return res;
    }

private:
    void quickSort(vector<string>& strs, int l, int r) {
        if(l >= r)
            return;

        int i = l, j = r;

        // l为数组最左端元素，以下循环是相当于以l为基准，进行排序
        while(i < j) {

            while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j)
                j--;

            while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j)
                i++;

            swap(strs[i], strs[j]);
        }

        swap(strs[i], strs[l]); // 将l对应的元素放回排序中应该属于它的正确的位置

        quickSort(strs, l, i - 1); // 对分区重复进行操作
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

// 时间复杂度: O(nlogn)
// 空间复杂度：O(n)
