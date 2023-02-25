#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // �ҵ�ǰ�벿�������β�ڵ㲢��ת��벿������
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // �ж��Ƿ����
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;

        while (result && p2 != nullptr) {

            if (p1->val != p2->val) {
                result = false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        // ��ԭ�������ؽ��
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
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

    // �ҵ�������е�
    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

//void print(ListNode * head) {
//    while (head) {
//        cout << head -> val << " ";
//        head = head -> next;
//    }
//
//    cout << endl;
//}

int main() {
    ListNode* headA = new ListNode (1);
    ListNode* node2 = new ListNode (2);
    ListNode* node3 = new ListNode (3);
    ListNode* node4 = new ListNode (3);
    ListNode* node5 = new ListNode (2);
    ListNode* node6 = new ListNode (1);

    Solution solution;

    bool res = solution.isPalindrome(headA);

    cout << "the result is " << res << endl;

    return 0;
}
// ʱ�临�Ӷȣ� O(N)
// �ռ临�Ӷȣ�O(1)
