// �˷�����c++�޷����ö�����ת10���ƽ��м��㣬ֻ������ֱ��ģ�ⷨ
// ��Ϊ��ת10���ƣ�ĳЩ���������ᳬ��64λ���͵ı�ʾ��Χ

// ���Ըó���ֻ�ܱ�ʾ��64λ�������ڵĶ����Ƽӷ�

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:

    //������Ķ������ַ���ת����ʮ���ƣ�������ʮ�������֡�
    long long int BinStr2Dec(string binaryString)
    {
        //�ڴ˴������ж�һ���ַ����ж೤�ĺ���
        int size = binaryString.length();

        //������������ת��Ϊʮ����
        long long int parseBinary = 0;
        for (int i = 0; i < size; ++i) {
            if (binaryString[i] == '1') {
                parseBinary += pow(2.0, size - i - 1);
            }
        }

        return parseBinary;
    }

    //ʮ��������ת�ɶ������ַ���
    string Dec2Binary(long long int x)
    {
        if (x == 0) {
            return "0";
        }

        string s = "";
        while(x){
            if(x % 2 == 0) s = '0' + s;
            else s = '1' + s;
            x /= 2;
        }
        return s;
    }


    string addBinary(string a, string b) {

        long long int x = BinStr2Dec(a);
        long long int y = BinStr2Dec(b);

        if (y == 0) {
            return a;
        }

        if (x == 0) {
            return b;
        }

        int ans = 0, carry = 0; // �������Գ�ֵ��������

        while (y) {
            ans = x ^ y;
            carry = (x & y) << 1;

            x = ans;
            y = carry;
        }

        string res = Dec2Binary(ans);

        return res;
    }
};


int main() {

    Solution solution;
    string a = "1", b = "0", res;

    res = solution.addBinary(a, b);

    cout << "the result is " << res << endl;
    return 0;
}
