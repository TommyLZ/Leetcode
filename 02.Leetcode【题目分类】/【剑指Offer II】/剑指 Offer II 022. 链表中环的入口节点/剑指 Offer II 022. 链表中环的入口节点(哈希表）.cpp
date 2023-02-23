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
        unordered_set<ListNode *> visited; // ������ϣ��
        ListNode *temp = headA;

        while (temp != nullptr) {   // ����������ĩβ
            visited.insert(temp);
            temp = temp->next;
        }

        temp = headB;

        while (temp != nullptr) {
            if (visited.count(temp)) { // �ҵ�����֮��return
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
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

// ʱ�临�Ӷȣ�O(N)
// �ռ临�Ӷȣ�O(N)
