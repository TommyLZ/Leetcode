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
            return "X"; // ����
        }

        auto left = "(" + serialize(root->left) + ")"; // �ݹ�������
        auto right = "(" + serialize(root->right) + ")";    // �ݹ�������
        return left + to_string(root->val) + right; // ƴ��
    }



    inline TreeNode* parseSubtree(const string &data, int &ptr) {   //�����������������п���
        ++ptr; // ����������
        auto subtree = parse(data, ptr);    // ��Ϊ����㣬��������
        ++ptr; // ����������
        return subtree;
    }

    inline int parseInt(const string &data, int &ptr) { // ��㸳ֵ����
        int x = 0, sgn = 1;

        // ��ֹ�����ָ���ֵ
        if (!isdigit(data[ptr])) { // �ж���ʮ���������ַ���ascii�룩
            sgn = -1;
            ++ptr;
        }

        // �����ֵĲ��ֽ�������
        while (isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] - '0'; //
        }

        // ��ԭ����ֵ
        return x * sgn;
    }

    TreeNode* parse(const string &data, int &ptr) {
        if (data[ptr] == 'X') {
            ++ptr;
            return nullptr;
        }

        auto cur = new TreeNode(0); // �������

        cur->left = parseSubtree(data, ptr);    // ����������
        cur->val = parseInt(data, ptr); // ��㸳ֵ
        cur->right = parseSubtree(data, ptr);   // ����������

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
