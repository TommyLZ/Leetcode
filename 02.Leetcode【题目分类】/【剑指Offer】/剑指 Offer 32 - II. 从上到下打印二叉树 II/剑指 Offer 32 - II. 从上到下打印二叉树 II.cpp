#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode (int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {    // 空树
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int currentLevelSize = q.size(); // 层对应的结点数

            ret.push_back(vector <int> ()); // 针对新的一层，都添加一行数组

            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front();
                q.pop();

                ret.back().push_back(node->val); // 存入到当前层对应的最后一行
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ret;
    }
};

int main() {
    TreeNode * root = new TreeNode(3);
    TreeNode * t11= new TreeNode(9);
    TreeNode * t12 = new TreeNode(20);
    TreeNode * t21 = new TreeNode(15);
    TreeNode * t22 = new TreeNode(7);

    root -> left = t11;
    root -> right = t12;

    t12 -> left = t21;
    t12 -> right = t22;

    Solution solution;

    vector<vector <int>> res = solution.levelOrder(root);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
