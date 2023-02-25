// �ݹ����
#include <iostream>
#include <vector>
using namespace std;

/*
struct TreeNode {
    int num;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int x): num(x), left(nullptr), right(nullptr) {}
};
*/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

    bool recur(vector<int> &postorder, int i, int j) {
        if (i >= j) {
            return true;
        }

        int p = i;

        while (postorder[p] < postorder[j]){ // ���һ�����һ���Ǹ����
            p++;
        }

        int m = p;  // �ҵ��������ĺ��������ķֽ�

        while (postorder[p] > postorder[j]){
            p++;
        }

        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);

        // �Ƿ����������֮����������� && �ݹ������� && �ݹ�������
    }

};

int main() {

/*
    TreeNode* root = new TreeNode (5);
    TreeNode* t11 = new TreeNode (2);
    TreeNode* t12 = new TreeNode (6);
    TreeNode* t21 = new TreeNode (1);
    TreeNode* t22 = new TreeNode (3);

    root ->left = t11;
    root -> right = t12;

    t11 -> left = t21;
    t11 -> right = t22;
*/
    Solution solution;

//    vector<int> postorder = {1, 3, 2, 6, 5};

    vector<int> postorder = {1, 6, 3, 2, 5};

    bool res = solution.verifyPostorder(postorder);

    cout << "the result is :" << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷ�: O(n)
