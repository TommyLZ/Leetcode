#include <iostream>
#include <vector>
#include <queue>

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

class Solution{ // 层次遍历（自顶向下）
public:
    TreeNode* mirrorTree(TreeNode* root){
        if(root == nullptr){ // 空树
            return nullptr;
        }

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            TreeNode* node = que.front();   // 返回队首
            que.pop();  // 出队
            swap(node->left, node->right);
            
            if(node->left != nullptr){
                que.push(node->left);
            }

            if(node->right != nullptr){
                que.push(node->right);
            }
        }

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

    cout << "ans: ";
    printBinaryTree(binaryTree);

    return 0;
}