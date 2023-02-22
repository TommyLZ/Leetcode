// 此方法：c++无法利用二进制转10进制进行计算，只能利用直接模拟法
// 因为：转10进制，某些测试用例会超过64位整型的表示范围

// 所以该程序只能表示在64位整型以内的二进制加法

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:

    //将传入的二进制字符串转换成十进制，并返回十进制数字。
    long long int BinStr2Dec(string binaryString)
    {
        //在此处调用判断一个字符串有多长的函数
        int size = binaryString.length();

        //将二进制数字转换为十进制
        long long int parseBinary = 0;
        for (int i = 0; i < size; ++i) {
            if (binaryString[i] == '1') {
                parseBinary += pow(2.0, size - i - 1);
            }
        }

        return parseBinary;
    }

    //十进制数字转成二进制字符串
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

        int ans = 0, carry = 0; // 这里必须对初值进行设置

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
