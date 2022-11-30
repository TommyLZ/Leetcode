#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto & log: logs) {
            if (log == "./") {
                continue;
            } else if (log == "../") {
                if (depth > 0) {
                    depth --;
                }
            } else {
                depth ++;
            }
        }

        return depth;
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