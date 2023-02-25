// 深度优先遍历
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int target) {
        if (root == nullptr) {  // 空树
            return;
        }

        path.emplace_back(root->val);

        target -= root->val;

        if (root->left == nullptr && root->right == nullptr && target == 0) {
            ret.emplace_back(path); // 记录结果
        }

        dfs(root->left, target);

        dfs(root->right, target);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ret;
    }
};


int main() {

    TreeNode* root = new TreeNode (5);
    TreeNode* t11 = new TreeNode (4);
    TreeNode* t12 = new TreeNode (8);
    TreeNode* t21 = new TreeNode (11);
    TreeNode* t22 = new TreeNode (13);
    TreeNode* t23 = new TreeNode (4);
    TreeNode* t31 = new TreeNode (7);
    TreeNode* t32 = new TreeNode (2);
    TreeNode* t33 = new TreeNode (5);
    TreeNode* t34 = new TreeNode (1);


    root ->left = t11;
    root -> right = t12;

    t11 -> left = t21;

    t12 -> left = t22;
    t12 -> right = t23;

    t21 -> left = t31;
    t21 -> right = t32;

    t23 -> left = t33;
    t23 -> right = t3pathSum4;

    Solution solution;

    int target = 22;

    vector<vector<int>> res = solution.pathSum(root, target);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// 时间复杂度：O(n^2)
// 空间复杂度: O(n)
