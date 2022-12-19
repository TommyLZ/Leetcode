#include <iostream>
#include <ctype.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int x): val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "X"; // 空树
        }

        auto left = "(" + serialize(root->left) + ")"; // 递归左子树
        auto right = "(" + serialize(root->right) + ")";    // 递归右子树
        return left + to_string(root->val) + right; // 拼接
    }



    inline TreeNode* parseSubtree(const string &data, int &ptr) {   //内联函数：减少运行开销
        ++ptr; // 跳过左括号
        auto subtree = parse(data, ptr);    // 作为根结点，继续创建
        ++ptr; // 跳过右括号
        return subtree;
    }

    inline int parseInt(const string &data, int &ptr) { // 结点赋值函数
        int x = 0, sgn = 1;

        // 防止结点出现负数值
        if (!isdigit(data[ptr])) { // 判断是十进制数字字符（ascii码）
            sgn = -1;
            ++ptr;
        }

        // 对数字的部分进行修饰
        while (isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] - '0'; //
        }

        // 还原负数值
        return x * sgn;
    }

    TreeNode* parse(const string &data, int &ptr) {
        if (data[ptr] == 'X') {
            ++ptr;
            return nullptr;
        }

        auto cur = new TreeNode(0); // 创建结点

        cur->left = parseSubtree(data, ptr);    // 创建左子树
        cur->val = parseInt(data, ptr); // 结点赋值
        cur->right = parseSubtree(data, ptr);   // 创建右子树

        return cur;
    }

    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }
};


int main() {
    TreeNode * root = new TreeNode(1);
    TreeNode * t11 = new TreeNode(2);
    TreeNode * t12 = new TreeNode(3);
    TreeNode * t21 = new TreeNode(4);
    TreeNode * t22 = new TreeNode(5);

    root -> left  = t11;
    root -> right = t12;

    t12 -> left = t21;
    t12 -> right = t22;

    Codec solution;

    cout << solution.serialize(root) << endl;

    return 0;
}
