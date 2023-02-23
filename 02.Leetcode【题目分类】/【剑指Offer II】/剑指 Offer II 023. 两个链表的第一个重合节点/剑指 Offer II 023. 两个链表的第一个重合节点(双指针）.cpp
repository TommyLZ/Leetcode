#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *pA = headA, *pB = headB;

        // ���������У��и����ģ��и��̵�
        // ����һ���������֮��ת�Ƶ���һ��������ָ��ֱ��߹���ͬ·�̵�ʱ��ͻ�����
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }

        return pA;
    }
};


int main(){
    ListNode* headA = new ListNode(4);
    ListNode* nodeA2 = new ListNode(1);
    ListNode* sharenode1 = new ListNode(8);
    ListNode* sharenode2 = new ListNode(4);
    ListNode* sharenode3 = new ListNode(5);
    ListNode* headB = new ListNode(5);
    ListNode* nodeB2 = new ListNode(0);
    ListNode* nodeB3 = new ListNode(1);

    headA -> next = nodeA2;
    nodeA2 -> next = sharenode1;
    sharenode1 -> next = sharenode2;
    sharenode2 -> next = sharenode3;
    headB -> next = nodeB2;
    nodeB2 -> next = nodeB3;
    nodeB3 -> next = sharenode1;

    Solution solution;

    ListNode* res = solution.getIntersectionNode(headA, headB);

    cout << "the result is " << res -> val << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(m+n)
// �ռ临�Ӷȣ�O(m)
