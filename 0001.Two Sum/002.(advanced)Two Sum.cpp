#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){

        unordered_map<int, int> record; // 创建哈希表<键，值>

        for(int i=0; i!=nums.size(); ++i){
            auto found = record.find(target - nums[i]); // auto自动匹配返回值类型, .find(键)返回一个指向该键值对的正向迭代器
            if (found != record.end())  // .end()返回容器中最后一个键值对之后位置的正向迭代器
                return {found->second, i};  // {先出现的元素的索引（值，就是second)，当前元素的索引}
            record.emplace(nums[i], i);  //没有找到，存储当前元素值和索引
        }

        return {-1, -1};    // 处理不符合题意的情况
    }
};

int main(){
    Solution solution;
    vector<int> nums = {4, 2, 3};
    vector<int> ans;
    int target = 6;

    ans = solution.twoSum(nums, target);

    cout << "ans: [";

    for (int i=0; i<ans.size(); ++i){
        if (i == ans.size() - 1){
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    
    cout << "]";

    return 0;
}