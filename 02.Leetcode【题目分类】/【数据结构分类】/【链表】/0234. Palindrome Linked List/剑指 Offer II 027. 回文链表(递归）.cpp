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
    ListNode* frontPointer;
public:
    bool recursivelyCheck(ListNode* currentNode) {

        if (currentNode != nullptr) {

            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }

            // �ж������������ж�
            if (currentNode->val != frontPointer->val) {
                return false;
            }

            frontPointer = frontPointer->next; // ��ָ���ƶ�
        }

        return true; // ʹ�õݹ鷴�����
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;

        return recursivelyCheck(head);
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
// �ռ临�Ӷȣ�O(N)
