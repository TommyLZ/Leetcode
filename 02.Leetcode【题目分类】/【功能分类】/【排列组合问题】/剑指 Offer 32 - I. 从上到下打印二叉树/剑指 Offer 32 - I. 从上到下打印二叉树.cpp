#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
private:
    vector<int> nums;
    queue<TreeNode *> q;
public:
    vector<int> levelOrder(TreeNode* root) {

        if (root) {
            q.push(root);
        }

        while (q.size()) {
            nums.push_back(q.front()->val);

            if (q.front()->left) {
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                q.push(q.front()->right);
            }

            q.pop();
        }

        return nums;
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

    vector<int> nums = solution.levelOrder(root);

    for (int num: nums) {
        cout << num << " ";
    }

    return 0;
}
