#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
private:
    unordered_map<int, int> index;  //哈希表

public:
    TreeNode* myBuildTree(vector<int> & preorder, vector<int> inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if(preorder_left > preorder_right){   // 空树
            return nullptr;
        }

        // 前序遍历第一个结点就是根结点
        int preorder_root = preorder_left; // 数组下标

        // 在中序遍历中定位根结点
        int inorder_root = index[preorder[preorder_root]];  //数组下标

        // 建立根结点
        TreeNode* root = new TreeNode(preorder[preorder_root]);

        // 得到左子树的结点数目
        int size_left_subtree = inorder_root - inorder_left;

        //递归构造左子树，并连接到叶子结点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);


        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        //构建哈希映射，快速定位根结点
        for(int i=0; i<n; i++){
            index[inorder[i]] = i;
        }

        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
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
