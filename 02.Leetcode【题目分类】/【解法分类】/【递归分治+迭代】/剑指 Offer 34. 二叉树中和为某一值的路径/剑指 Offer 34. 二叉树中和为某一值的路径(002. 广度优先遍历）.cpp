// ������ȱ���
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> ret;    // ���մ�
    unordered_map<TreeNode*, TreeNode*> parent; // ʹ�ù�ϣ���¼����ÿ�����ĸ����

    void getPath(TreeNode* node) {
        vector<int> tmp;

        while (node != nullptr) {
            tmp.emplace_back(node->val);
            node = parent[node];    // ��node��ʼ������Ѱ�Ҹ����
        }

        reverse(tmp.begin(), tmp.end());    // ��·����˳���������

        ret.emplace_back(tmp);  // ��·����¼����
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root == nullptr) {  // ����
            return ret;
        }

        queue<TreeNode*> que_node;
        queue<int> que_sum;

        que_node.emplace(root); // �洢���Ķ���
        que_sum.emplace(0);

        while (!que_node.empty()) {
            TreeNode* node = que_node.front();
            que_node.pop();

            int rec = que_sum.front() + node->val; // ��ֵ�����ۼ�
            que_sum.pop();

            if (node->left == nullptr && node->right == nullptr) {  // Ҷ�ӽ��
                if (rec == target) {    // �ۼƴﵽ��Ŀ��
                    getPath(node);
                }
            }
            else {

                if (node->left != nullptr) {    // ��������
                    parent[node->left] = node;  // ��¼�����

                    que_node.emplace(node->left);   // ���

                    que_sum.emplace(rec);   // �洢��ǰ�ۼ�ֵ
                }

                if (node->right != nullptr) {   // ��������
                    parent[node->right] = node;

                    que_node.emplace(node->right);

                    que_sum.emplace(rec);
                }
            }
        }

        return ret;
    }
};

int main() {

    TreeNode* root = new TreeNode (5);
    TreeNode* t11 = new TreeNode (4);
    TreeNode* t12 = new TreeNode (8);
    TreeNode* t21 = new TreeNode (11);
    TreeNode* t22 = new TreeNode (13);
    TreeNode* t23 = new TreeNode (4);
    TreeNode* t31 = new TreeNode (7);
    TreeNode* t32 = new TreeNode (2);
    TreeNode* t33 = new TreeNode (5);
    TreeNode* t34 = new TreeNode (1);


    root ->left = t11;
    root -> right = t12;

    t11 -> left = t21;

    t12 -> left = t22;
    t12 -> right = t23;

    t21 -> left = t31;
    t21 -> right = t32;

    t23 -> left = t33;
    t23 -> right = t34;

    Solution solution;

    int target = 22;

    vector<vector<int>> res = solution.pathSum(root, target);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷ�: O(n)
