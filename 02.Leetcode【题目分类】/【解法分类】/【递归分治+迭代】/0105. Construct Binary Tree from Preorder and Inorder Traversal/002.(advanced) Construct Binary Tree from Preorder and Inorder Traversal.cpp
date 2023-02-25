#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode* buildTree(vector<int> & preorder, vector<int> inorder) {
        if(!preorder.size()){   // 空树
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;

        stk.push(root);

        int inorderIndex = 0;

        for (int i=1; i<preorder.size(); ++i){
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();

            if (node->val != inorder[inorderIndex]){
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }else{
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex]){
                    TreeNode* node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }

                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }

        return root;
    }

};

void printBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return ;
    }

    queue<TreeNode*> que;
    que.push(root);

    cout << "[";

    while(!que.empty()){
        TreeNode* node = que.front();
        que.pop();
        cout << node->val << " ";

        if(node->left){
            que.push(node->left);
        }

        if(node->right){
            que.push(node->right);
        }
    }

    cout << "]" << endl;
}


int main(){
    Solution solution;
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    TreeNode* ans;

    ans = solution.buildTree(preorder, inorder);

    printBinaryTree(ans);

    return 0;
}