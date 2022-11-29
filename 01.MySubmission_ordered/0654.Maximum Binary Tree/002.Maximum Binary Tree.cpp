#include <iostream>
#include <vector>
#include <stack>

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
        int n = nums.size();
        vector<int> stk;
        vector<TreeNode*> tree(n);

        for (int i = 0; i < n; ++i) {   // 从左到右遍历数组
            tree[i] = new TreeNode(nums[i]);    // 为每个新值建立树结点

            while (!stk.empty() && nums[i] > nums[stk.back()]) {    // 当前值为大值
                tree[i]->left = tree[stk.back()]; // 之前的树将为左子树
                stk.pop_back(); // 出栈
            }

            if (!stk.empty()) {
                tree[stk.back()]->right = tree[i];
            }

            stk.push_back(i);   // 序号入栈
        }

        return tree[stk[0]];    // 这里是什么意思？
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