#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;

        int e = 0;
        for (int num: nums) {

              // ʹ��tie�����������ǣ�ʵ��pair�Ķ�Ӧ��ֵ
              // ����ʹ��pair�ܹ�ʵ��a��b��ͬ������
              tie(a, b) = pair{(~a & b & num) | (a & ~b & ~num), ~a & (b ^ num)};


              // ע�⣺��ʽ�������滻�ɣ�
              // a = (~a & b & num) | (a & ~b & ~num);
              // b = ~a & (b ^ num);
              // ��Ϊa��b����Ҫͬʱ���м���


              // ����ʹ��c++ 17��auto�ṹ���󶨣���Ϊ auto֮�����c��fҪ���ǵ�һ�ζ���
              // �����ʽ��Ҫ����ǵ�ʽ���߶���a,b��auto��ʹ��Ҫ���ǻ����ͻ��
              // �����ʽ�Ӳ����Ǳ������ȷ����ǣ�����Ҳ������ȷ�������
              // auto [c, f] = pair{(~a & b & num) | (a & ~b & ~num), ~a & (b ^ num)};
              // e = f;
        }

        // return e;

        return b;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 2, 3, 2};

    int res = solution.singleNumber(nums);

    cout << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
