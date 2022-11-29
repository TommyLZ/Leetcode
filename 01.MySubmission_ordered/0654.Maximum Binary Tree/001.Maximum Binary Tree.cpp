#include <iostream>
#include <vector>

using namespace std;

const int QUEUE_MAX_SIZE = 1001;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Queue{
    TreeNode* data[QUEUE_MAX_SIZE];
    int front;
    int rear;
};

class Solution{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        return construct(nums, 0, nums.size() - 1);
    }

    TreeNode* construct(const vector<int>& nums, int left, int right){
        if (left > right){  //叶子结点返回空
            return nullptr;
        }

        int best = left;    //每次以最左边为best

        for (int i=left+1; i<=right; ++i){  //从左向右找最大值
            if(nums[i] > nums[best]){
                best = i;
            }
        }   // best存放最大值对应序号

        TreeNode* node = new TreeNode(nums[best]);
        node -> left = construct(nums, left, best - 1); //建立左子树
        node -> right = construct(nums, best + 1, right);   //建立右子树

        return node;
    }
};

void printBinaryTree(TreeNode* root){
    if(!root){ // 空树
        return ;
    }

    Queue Q;  // 创建队列，元素为树结点
    Q.front = Q.rear = -1;  
    Q.data[++Q.rear] = root;    // 根结点入队
    while(Q.rear != Q.front){

        TreeNode* node = Q.data[++Q.front]; //出队
        cout << node->val << ", ";

        if(node -> left){   // 左子树入队
            Q.data[++Q.rear] = node -> left;
        }

        if(node -> right){  // 右子树入队
            Q.data[++Q.rear] = node -> right;
        }
    }
}

int main(){
    Solution solution;
    vector<int> nums {3,2,1,6,0,5};

    TreeNode* ans = solution.constructMaximumBinaryTree(nums);

    cout << "ans: [";
    
    printBinaryTree(ans);

    cout << "]" << endl;

    return 0;
}