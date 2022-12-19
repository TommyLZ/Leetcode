// 深度优先搜索
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
    void reserialize (TreeNode* root, string& str) {    // 引用传值，所以不用返回
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
        if (dataArray.front() == "None") {  // 如果第一元素变量为 "None"
            dataArray.erase(dataArray.begin()); // 删除改元素
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front())); // stio函数：将string类型转化成int类型

        dataArray.erase(dataArray.begin());

        root -> left = redeserialize(dataArray); // 递归建立左子树
        root -> right = redeserialize(dataArray);   // 递归建立右子树

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;

        // 读取并整理数据
        for (auto& ch: data) {  // 遍历输入
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            }
            else{
                str.push_back(ch);
            }
        }

        // 读取最后一个数据
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        // 最终，所有的输入都整理在了dataArray当中

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
