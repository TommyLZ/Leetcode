#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();

        for (int i = 0, j = 0; i < n; ++i) {
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution solution;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> poped = {4, 5, 3, 2, 1};

    bool res = solution.validateStackSequences(pushed, poped);

    cout << "the result is : " << res << endl;

    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度：O(n)