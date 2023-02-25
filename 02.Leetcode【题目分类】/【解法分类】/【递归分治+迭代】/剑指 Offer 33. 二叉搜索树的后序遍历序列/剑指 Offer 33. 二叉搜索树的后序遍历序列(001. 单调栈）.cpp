// ��������ջ
// �ؼ������������������������򣨸����󣩣����ҵ�����һ����һ��������������У�������ջ����Ȼ���ҵ���������ͨ����ջ���ҵ���������Ӧ�ĸ�
// ������ϳ����ܹ�˳��ִ����ȥ����˵�����϶����������Ķ���
#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> st;
        int root = INT_MAX; // ��ʼ������ջʱ����Ҫ�������ֵ

        for (int i = postorder.size() - 1; i >= 0; i--) {    // �������

            if (postorder[i] > root) {  // ����������������������������򣨸����󣩵Ķ���
                return false;
            }

            // Ѱ�Ҹ����
            while (!st.empty() && st.top() > postorder[i]) { // ����������������������еĽ�������ѭ��
                root = st.top();
                st.pop();   // ���ص��ǿգ�ͨ����ջѰ��postorder[i]�ĸ���㣬�����ǵ���ջ������ջΪ��ʱ���ҵ������
            }

            st.push(postorder[i]); // ��ǰ�����ջ
        }

        return true;
    }

};

int main() {

    Solution solution;

    vector<int> postorder = {1, 3, 2, 6, 5};

//    vector<int> postorder = {1, 6, 3, 2, 5};

    bool res = solution.verifyPostorder(postorder);

    cout << "the result is :" << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(N)
// �ռ临�Ӷȣ�O(N)
