#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
     vector<int> constructArray(int n, int k) {
        vector<int> ans;
        
        for (int i=1; i<n-k; ++i) { // 重复的部分差值为1
            ans.push_back(i);
        }

        for (int i=n-k, j=n; i<=j; ++i,--j) { // 从两边向中间缩进
            ans.push_back(i);
            
            if (i != j) {
                ans.push_back(j);
            }
        }

        return ans;
     }
};

int main() {
    Solution solution;
    int n= 3, k = 1;
    vector<int> ans;
    
    ans = solution.constructArray(n, k);

    cout << "[" ;
    for (int i=0; i<ans.size(); ++i) {
        if (i == ans.size() - 1){
            cout << ans[i];
            break;
        }
        cout << ans[i] << " ";
    }
    cout << "]";

    return 0;
}