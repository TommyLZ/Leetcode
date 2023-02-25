#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next; // ��Ҫ��ǰ������һ�ֵĽ��
            curr->next = prev; // ���ؼ����裺��ת��
            prev = curr;    // ��ת֮�󣬵�ǰ�������һ�ֵ�prev
            curr = next;    // ��ǰ��ת���֮��ת����һ��
        }
        return prev;
    }
};

void print(ListNode * head) {
    while (head) {
        cout << head -> val << " ";
        head = head -> next;
    }

    cout << endl;
}


int main() {
    ListNode* headA = new ListNode (1);
    ListNode* node2 = new ListNode (2);
    ListNode* node3 = new ListNode (3);
    ListNode* node4 = new ListNode (4);
    ListNode* node5 = new ListNode (5);


    headA -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    Solution solution;

    ListNode * res;

    res = solution.reverseList(headA);

    print(res);
    return 0;
}

// ʱ�临�Ӷȣ� O(n)
// �ռ临�Ӷȣ�O(n)
