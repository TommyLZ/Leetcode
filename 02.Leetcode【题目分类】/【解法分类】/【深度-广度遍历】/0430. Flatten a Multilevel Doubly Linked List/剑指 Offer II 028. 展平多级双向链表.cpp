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

        // lambda���ʽ�����������Զ����������࣬����������Ĭ��ʵ��һ��public���͵�operator()���������ǳ�Ϊ�հ����͡�
        // ��ô������ʱ�����lambda���ʽ�ͻ᷵��һ�������ıհ�ʵ��������һ����ֵ
        // [&] Ĭ�����ò�������б���

        // dfsΪʲôҪ������������
        function<Node*(Node*)> dfs = [&](Node* node) {

            Node* cur = node;
            // ��¼��������һ���ڵ�
            Node* last = nullptr;

            while (cur) {
                Node* next = cur->next;

                //  ������ӽڵ㣬��ô���ȴ����ӽڵ�
                if (cur->child) {

                    // ���ȴ����ӽ��
                    Node* child_last = dfs(cur->child); // ������ȱ���

                    next = cur->next;

                    //  �� node �� child ������˫��
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    //  ��� next ��Ϊ�գ��ͽ� last �� next ����
                    if (next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    // �� child ��Ϊ��
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

        dfs(head);  // ������ȱ����㷨
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

// ʱ�临�Ӷȣ�O(N)
// �ռ临�Ӷȣ�O(1)
