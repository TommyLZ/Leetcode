// 剑指Offer 36
#include <iostream>

using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution{
private:
    Node *pre, *head;

    void dfs(Node* cur) {
        if (cur == nullptr){
            return ;
        }

        dfs(cur->left);

        if (pre != nullptr) { // 前驱结点非空
             pre->right = cur;
        }
        else{ // 正在访问链表头结点
            head = cur;
        }
        
        cur->left = pre; // 双向指针建立完成（ 如果是head，head->left就是空）
        pre = cur;  // 更新前驱
        
        dfs(cur->right);    
    }

public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        dfs(root); // 中序遍历
        
        // 完整双向链表的形成
        head->left = pre; // 树最右边的结点（最大值）连接到头结点
        pre->right = head; // 头结点连接到最大值 

        return head;
    }
};

int main() {
    return 0;
}
