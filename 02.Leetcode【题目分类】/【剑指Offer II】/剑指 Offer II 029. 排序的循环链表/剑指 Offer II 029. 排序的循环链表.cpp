#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *node = new Node(insertVal);   // 形成新结点

        if (head == nullptr) { // 形成闭环
            node->next = node;
            return node;
        }

        if (head->next == head) {
            head->next = node;
            node->next = head;
            return head;
        }

        Node *curr = head, *next = head->next;

        while (next != head) {

            if (insertVal >= curr->val && insertVal <= next->val) {
                break;
            }

            if (curr->val > next->val) {
                if (insertVal > curr->val || insertVal < next->val) {
                    break;
                }
            }

            curr = curr->next;
            next = next->next;
        }

        curr->next = node;
        node->next = next;

        return head;
    }
};

void print(Node* head) {
    Node* node = head;

    while (node) {
        cout << node -> val << " ";
        node = node -> next;

        if (node == head) {
            break;
        }
    }

    cout << endl;
}

int main() {
    Node* headA = new Node (3);
    Node* node2 = new Node (4);
    Node* node3 = new Node (1);

    headA -> next = node2;
    node2 -> next = node3;
    node3 -> next = headA;

    Solution solution;

    int interval = 2;

    Node* res = solution.insert(headA, interval);

    print(res);

    return 0;
}

// 时间复杂度：O(N)
// 空间复杂度：O(1)
