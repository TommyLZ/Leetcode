// 辅助单调栈
// 关键：二叉搜索树后续遍历逆序（根右左），根右的序列一定是一个单调升序的序列（不断入栈），然后找到左子树，通过出栈，找到左子树对应的根
// 如果以上程序能够顺利执行下去，就说明符合二叉搜索树的定义
#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> st;
        int root = INT_MAX; // 初始化单调栈时，需要设置最大值

        for (int i = postorder.size() - 1; i >= 0; i--) {    // 倒序遍历

            if (postorder[i] > root) {  // 不满足二叉搜索树后续遍历的逆序（根右左）的定义
                return false;
            }

            // 寻找父结点
            while (!st.empty() && st.top() > postorder[i]) { // 逆序遍历，出现了左子树中的结点则进入循环
                root = st.top();
                st.pop();   // 返回的是空：通过出栈寻找postorder[i]的父结点，由于是单调栈，所以栈为空时，找到父结点
            }

            st.push(postorder[i]); // 当前结点入栈
        }

        return true;
    }

};

int main() {

    Solution solution;

    vector<int> postorder = {1, 3, 2, 6, 5};

//    vector<int> postorder = {1, 6, 3, 2, 5};

    bool res = solution.verifyPostorder(postorder);

    cout << "the result is :" << res << endl;

    return 0;
}

// 时间复杂度：O(N)
// 空间复杂度：O(N)
