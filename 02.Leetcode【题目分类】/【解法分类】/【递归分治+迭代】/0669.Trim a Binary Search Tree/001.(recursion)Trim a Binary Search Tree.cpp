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
        if (root == nullptr) {  // 当前结点为空结点，直接返回空结点
            return nullptr;
        }

        if (root->val < low) {  // 如果结点的值小于low，那么说明该结点及它的左子树都不符合要求，我们返回对它的右结点作为修剪后的结果
            return trimBST(root->right, low, high);
        }
        else if (root->val > high) {    // 那么说明该结点及它的右子树都不符合要求，我们返回对它的左子树进行修剪后的结果
            return trimBST(root->left, low, high);
        }
        else {  // 如果结点的值位于区间[low, high]，我们将结点的左结点设为对它的左子树修剪后的结果，右结点设为对它的右子树进行修剪后的结果。
            root -> left = trimBST(root->left, low, high);
            root -> right = trimBST(root->right, low, high);
            return root;
        }
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