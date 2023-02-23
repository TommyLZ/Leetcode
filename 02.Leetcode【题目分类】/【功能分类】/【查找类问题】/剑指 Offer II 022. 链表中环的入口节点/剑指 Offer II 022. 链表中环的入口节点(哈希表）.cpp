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
        unordered_set<ListNode *> visited;

        while (head != nullptr) {

            if (visited.count(head)) { // headһֱ���ڲ����ƶ���
                return head;
            }

            visited.insert(head);
            head = head->next;
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
    node3 -> next = node4;
    node4 -> next = node2;

    Solution solution;

    int n = 2;

    ListNode* res = solution.detectCycle(head);

    cout << "the result is " << res -> val << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(N)
// �ռ临�Ӷȣ�O(N)
