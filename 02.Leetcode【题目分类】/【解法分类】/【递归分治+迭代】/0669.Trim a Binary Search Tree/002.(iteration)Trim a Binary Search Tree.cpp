#include <iostream>
#include <vector>

using namespace std;

const int QUEUE_MAX_SIZE = 10001;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode * right) : val(x), left(left), right(right) {}
};

struct Queue{
    TreeNode* data[QUEUE_MAX_SIZE];
    int front, rear;
};

TreeNode* insertion(TreeNode* root, int num) {
    TreeNode* node = new TreeNode(num);

    if (root == nullptr){   // 当申请插值的树是空树时
        root = node;
    }
    else if (num < root->val) {
        root->left = insertion(root->left, num);
    }
    else if(num > root -> val) {
        root->right = insertion(root->right, num);
    }

    return root;
}

TreeNode* createBinaryTree(vector<int> &nums) { // 建立二叉搜索树

    TreeNode* root = new TreeNode(nums[0]); // 选定数组中第一个元素作为根结点

    for (int i=1; i<nums.size(); ++i) {
        insertion(root, nums[i]);   // 将二叉树创建和二叉树插值分开写，就能够单独调用二叉树插值这个函数，在主函数中，随时能够在二叉树中的进行插值
    }

    return root;
}

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 先对root内的值进行判断，保证一个合法的root
        while (root && (root->val < low || root->val > high)) { // 非空树，值不在区间内
            if (root->val < low) {
                root = root->right; // 使用右子树连接
            } else {
                root = root->left;  // 使用左子树连接
            }
        }
        
        if (root == nullptr) {  // root是空树|| 利用while循环检查下来，没有在区间之内的树
            return nullptr;
        }

        // 对root一直往下，从左子树开始判断
        for (auto node = root; node->left; ) {  // node初值为root, node->left不为空时进入循环， 没有累加条件，累加条件在循环体内
            if (node->left->val < low) {
                node->left = node->left->right;
            } else {
                node = node->left;  // 继续向左子树进行遍历
            }
        }
         
        // 对root一直往下，从右子树开始判断
        for (auto node = root; node->right; ) {
            if (node->right->val > high) {
                node->right = node->right->left;
            } else {
                node = node->right;
            }
        }

        return root;
    }
};

void printBinaryTree(TreeNode* root) {  // 二叉树的广度优先遍历（层次遍历）
    if (!root){ // 空树
        return ;
    }

    Queue Q;
    Q.front = Q.rear = -1;
    Q.data[++Q.rear] = root;    // 根结点入队

    cout << "[" ;

    while(Q.front != Q.rear){
        TreeNode* node = Q.data[++Q.front];
        cout << node->val << " ";

        if(node->left){ //左子树入队
            Q.data[++Q.rear] = node->left;
        }

        if(node->right){    //右子树入队
            Q.data[++Q.rear] = node->right;
        }
    }

    cout << "]" << endl;
}


int main() {
    Solution solution;
    vector<int> nums = {3, 0, 4, 2, 1};
    int low = 1, high = 3;
    TreeNode* ans;

    TreeNode* root = createBinaryTree(nums); // 建立二叉搜索树
    cout << "original: ";
    printBinaryTree(root);

    ans = solution.trimBST(root, low, high);

    cout << "answer: ";
    printBinaryTree(ans);

    return 0;
}