#include <iostream>
#include <vector>

using namespace std;

const int QUEUE_MAX_SIZE = 1001;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){ }
};

struct Queue{
    TreeNode* data[QUEUE_MAX_SIZE];
    int front, rear;
};

TreeNode* creatBinaryTree(vector<int> nums, int index){

    if(index >= nums.size()){    //索引超出范围
        return nullptr;
    }

    TreeNode* node = new TreeNode(nums[index]); //创建结点

    node->left = creatBinaryTree(nums, 2 * index + 1);  //递归创建左子树
    node->right = creatBinaryTree(nums, 2 * index + 2); //递归创建右子树

    return node;
}

class Solution{ 
public:
    TreeNode* mirrorTree(TreeNode* root){ // 递归版本(自底向上)
        if(root == nullptr){ // 空树
            return nullptr;
        }

        TreeNode* left = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};

void printBinaryTree(TreeNode* root){
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
    vector<int> nums = {4,2,7,1,3,6,9};

    TreeNode* binaryTree = creatBinaryTree(nums, 0);
    cout << "original: ";
    printBinaryTree(binaryTree);

    TreeNode* ans = solution.mirrorTree(binaryTree);

    cout << "answer: ";
    printBinaryTree(binaryTree);

    return 0;
}