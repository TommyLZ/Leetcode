// 递归分治
#include <iostream>
#include <vector>
using namespace std;

/*
struct TreeNode {
    int num;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int x): num(x), left(nullptr), right(nullptr) {}
};
*/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

    bool recur(vector<int> &postorder, int i, int j) {
        if (i >= j) {
            return true;
        }

        int p = i;

        while (postorder[p] < postorder[j]){ // 最后一个结点一定是根结点
            p++;
        }

        int m = p;  // 找到左子树的和右子树的分界

        while (postorder[p] > postorder[j]){
            p++;
        }

        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);

        // 是否右子树完成之后就是左子树 && 递归左子树 && 递归右子树
    }

};

int main() {

/*
    TreeNode* root = new TreeNode (5);
    TreeNode* t11 = new TreeNode (2);
    TreeNode* t12 = new TreeNode (6);
    TreeNode* t21 = new TreeNode (1);
    TreeNode* t22 = new TreeNode (3);

    root ->left = t11;
    root -> right = t12;

    t11 -> left = t21;
    t11 -> right = t22;
*/
    Solution solution;

//    vector<int> postorder = {1, 3, 2, 6, 5};

    vector<int> postorder = {1, 6, 3, 2, 5};

    bool res = solution.verifyPostorder(postorder);

    cout << "the result is :" << res << endl;

    return 0;
}

// 时间复杂度：O(n^2)
// 空间复杂度: O(n)
