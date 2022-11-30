#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
    int busyStudent(vector<int>& startTime, vector<int> endTime, int queryTime){
        int n = startTime.size();
        int ans = 0;

        for (int i=0; i<n; ++i){
            if (startTime[i] <= queryTime && endTime[i] >= queryTime){
                ans++;
            }
        }

        return ans;
    }

};

int main(){
    Solution solution;
    vector<int> startTime = {4};
    vector<int> endTime = {4};
    int queryTime = 4;
    int ans = 0;

    ans = solution.busyStudent(startTime, endTime, queryTime);

    cout << "ans:" << ans << endl;

    return 0;
}