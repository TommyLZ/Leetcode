#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minOperations(vector<string>& logs) {
        bool main = true;
        int ans = 0;

        for (int i=0; i<logs.size(); ++i) {
            if (logs[i] == "../" && !main && ans) {    // 向父文件夹回退, 并且不在主文件夹
                ans --;
            }
            else if (logs[i] == "./" || logs[i] == "../") { //停留在当前文件夹 || 在主文件夹无法回退
                continue;
            }
            else {  // 进入子文件夹
                ans ++;
                main = false;
            }

            if (ans == 0) { // 防止过度回退
                main = true;
            }
        }

        return ans;
    }   
};

int main() {
    Solution solution;
    vector<string> logs = {"d1/","../","../","../"};
    int ans;

    ans = solution.minOperations(logs);

    cout << "answer: " << ans << endl;

    return 0;
}