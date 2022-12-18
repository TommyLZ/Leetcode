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
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList; // 使用队列记录每一层的数据
            int size = nodeQueue.size();

            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();

                if (isOrderLeft) {
                    levelList.push_back(node->val);
                }
                else {
                    levelList.push_front(node->val);
                }

                if (node->left) {
                    nodeQueue.push(node->left);
                }

                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }

            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});

            isOrderLeft = !isOrderLeft; // 控制方向
        }

        return ans;
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
