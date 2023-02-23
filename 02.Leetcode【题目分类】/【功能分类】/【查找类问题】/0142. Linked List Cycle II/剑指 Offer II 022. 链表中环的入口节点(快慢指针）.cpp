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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast != nullptr) {

            slow = slow->next;

            if (fast->next == nullptr) {
                return nullptr;
            }

            fast = fast->next->next; // ����ʱ�̣�fast�߹��ľ�����slow��2��

            if (fast == slow) { // ����ָ������
                ListNode *ptr = head;

                // ��ѧ���ɣ�ptr��slow���뻷��������������ϵ��
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return nullptr;
    }
};

int main(){
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head -> next = node2;
    node2 -> next = node3;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node2;

    Solution solution;

    int n = 2;

    ListNode* res = solution.detectCycle(head);

    cout << "the result is " << res -> val << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(N)
// �ռ临�Ӷȣ�O(1)
