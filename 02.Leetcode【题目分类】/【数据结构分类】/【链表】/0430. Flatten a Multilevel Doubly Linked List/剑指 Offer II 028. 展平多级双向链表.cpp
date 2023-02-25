#include <iostream>
#include <functional>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {

        // lambda表达式：编译器会自动生成匿名类，这个类里面会默认实现一个public类型的operator()函数，我们称为闭包类型。
        // 那么在运行时，这个lambda表达式就会返回一个匿名的闭包实例，它是一个右值
        // [&] 默认引用捕获的所有变量

        // dfs为什么要定义成这个类型
        function<Node*(Node*)> dfs = [&](Node* node) {

            Node* cur = node;
            // 记录链表的最后一个节点
            Node* last = nullptr;

            while (cur) {
                Node* next = cur->next;

                //  如果有子节点，那么首先处理子节点
                if (cur->child) {

                    // 优先处理子结点
                    Node* child_last = dfs(cur->child); // 深度优先遍历

                    next = cur->next;

                    //  将 node 与 child 相连（双向）
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    //  如果 next 不为空，就将 last 与 next 相连
                    if (next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    // 将 child 置为空
                    cur->child = nullptr;
                    last = child_last;
                }
                else {
                    last = cur;
                }

                cur = next;
            }

            return last;
        };

        dfs(head);  // 深度优先遍历算法
        return head;
    }
};

void print(Node * head) {
    while (head) {
        cout << head -> val << " ";
        head = head -> next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node();
    head -> val = 1;
    Node* node2 = new Node();
    node2 -> val = 2;
    Node* node3 = new Node();
    node3 -> val = 3;
    Node* node4 = new Node();
    node4 -> val = 4;
    Node* node5 = new Node();
    node5 -> val = 5;
    Node* node6 = new Node();
    node6 -> val = 6;
    Node* node7 = new Node();
    node7 -> val = 7;
    Node* node8 = new Node();
    node8 -> val = 8;
    Node* node9 = new Node();
    node9 -> val = 9;
    Node* node10 = new Node();
    node10 -> val = 10;
    Node* node11 = new Node();
    node11 -> val = 11;
    Node* node12 = new Node();
    node12 -> val = 12;

    head -> prev = nullptr;
    head -> next = node2;

    node2 -> prev = head;
    node2 -> next = node3;

    node3 -> prev = node2;
    node3 -> next = node4;
    node3 -> child = node7;

    node4 -> prev = node3;
    node4 -> next = node5;

    node5 -> prev = node4;
    node5 -> next = node6;

    node6 -> prev = node5;
    node6 -> next = nullptr;

    node7 -> prev = node6;
    node7 -> next = node8;

    node8 -> prev = node7;
    node8 -> next = node9;
    node8 -> child = node11;

    node9 -> prev = node8;
    node9 -> next = node10;

    node10 -> prev = node9;
    node10 -> next = nullptr;

    node11 -> prev = nullptr;
    node11 -> next = node12;

    node12 -> prev = node11;
    node12-> next = nullptr;

    Solution solution;

    Node* res = solution.flatten(head);

    print(res);

    return 0;
}

// 时间复杂度：O(N)
// 空间复杂度：O(1)
