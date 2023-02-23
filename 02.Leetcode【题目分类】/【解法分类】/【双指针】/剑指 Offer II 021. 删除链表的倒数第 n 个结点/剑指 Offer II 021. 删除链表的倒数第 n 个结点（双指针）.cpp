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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* first = head;
        ListNode* second = dummy;


        for (int i = 0; i < n; ++i) {
            first = first->next;
        }

        // firstָ��������n�����
        // �൱��fisrt��second֮��ǡ������ɾ���ľ��룬Ȼ��һ������ƶ�
        while (first) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        ListNode* ans = dummy->next;

        delete dummy;
        return ans;
    }
};


void printList (ListNode * head) {
    ListNode* node = head;

    while (node) {
        cout << node -> val << " ";
        node = node -> next;
    }

    cout << endl;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    Solution solution;

    int n = 2;

    ListNode* res = solution.removeNthFromEnd(head, n);

    printList(res);

    return 0;
}

// ʱ�临�Ӷȣ�O(L)
// �ռ临�Ӷȣ�O(1)
