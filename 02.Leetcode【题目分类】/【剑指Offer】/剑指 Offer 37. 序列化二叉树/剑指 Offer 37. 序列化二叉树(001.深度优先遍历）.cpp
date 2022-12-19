// �����������
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void reserialize (TreeNode* root, string& str) {    // ���ô�ֵ�����Բ��÷���
        if (!root) {
            str += "None,";
        }
        else{
            str += to_string(root->val) + ",";
            reserialize(root -> left, str);
            reserialize(root ->right, str);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        reserialize(root, ret);
        return ret;
    }

    TreeNode* redeserialize (list<string>& dataArray) {
        if (dataArray.front() == "None") {  // �����һԪ�ر���Ϊ "None"
            dataArray.erase(dataArray.begin()); // ɾ����Ԫ��
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front())); // stio��������string����ת����int����

        dataArray.erase(dataArray.begin());

        root -> left = redeserialize(dataArray); // �ݹ齨��������
        root -> right = redeserialize(dataArray);   // �ݹ齨��������

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;

        // ��ȡ����������
        for (auto& ch: data) {  // ��������
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            }
            else{
                str.push_back(ch);
            }
        }

        // ��ȡ���һ������
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        // ���գ����е����붼��������dataArray����

        return redeserialize(dataArray);
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

    Solution solution;

    cout << solution.serialize(root) << endl;


    return 0;
}
