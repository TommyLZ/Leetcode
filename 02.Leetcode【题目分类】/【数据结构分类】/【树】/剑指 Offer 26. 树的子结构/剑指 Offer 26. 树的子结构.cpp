// 此代码完整结构有待补充
#include <iostream>
using namespace std;

class Solution{
    bool iscontain(TreeNode *A, TreeNode *B) {
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;

        if (A->val == B->val)
            return iscontain(A->left, B->left) && iscontain(A->left, B->right);
        else
            return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B)
            return false;   // B为真A为空的时候，返回false

        if (A->val == B->val && iscontain(A, B)) // 碰到相等的结点时
            return true;
        else 
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);   // 调整和A中匹配的位置
    }
};

int main() {
    
    return 0;
}