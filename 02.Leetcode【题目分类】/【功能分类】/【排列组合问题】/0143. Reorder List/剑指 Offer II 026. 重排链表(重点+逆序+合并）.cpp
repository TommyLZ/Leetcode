#include <iostream>
#include <stack>
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
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);

        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;

        l2 = reverseList(l2); // ��ת�Ұ벿������

        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) { // �ҵ�ԭ�����е�
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;

        while (l1 != nullptr && l2 != nullptr) {

            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
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

    Solution solution;

    solution.reorderList(headA);

    return 0;
}
// ʱ�临�Ӷȣ� O(N)
// �ռ临�Ӷȣ�O(1)
