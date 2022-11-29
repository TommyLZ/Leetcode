#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <cfloat>

using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int> & quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> h(n, 0);

        iota(h.begin(), h.end(), 0);    // 对数组中的元素从0开始进行递增初始化

        sort(h.begin(), h.end(), [&](int& a, int& b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
        }); // 可以先将工人按照权重进行升序排序

        double res = DBL_MAX;   // 作为初始比较值
        double totalq = 0.0;    // 总工薪

        priority_queue<int, vector<int>, less<int>> q;  // 优先级队列（队列头部的元素优先级最高）
        // 参数： int， 队列中需要维护的数据类型是int
        // vector<int> 使用vector来作为队列，维护数据int 
        //  less是一个默认的排序断言，定义在头文件 function 中，决定了容器中最大的元素会排在队列前面

        for (int i = 0; i < k - 1; i++) {   // 使用优先级队列维护工作质量最少的k-1名工人
            totalq += quality[h[i]];
            q.push(quality[h[i]]);
        }

        // 工作质量最高的会排在队首

        for (int i = k - 1; i < n; i++) {
            int idx = h[i]; // 工资组中权重最高
            totalq += quality[idx]; 
            q.push(quality[idx]);

            double totalc = ((double) wage[idx] / quality[idx]) * totalq;   // 计算总支出
            res = min(res, totalc); // 比较取最小值
            totalq -= q.top();  // 队首元素出栈
            q.pop();    // 移除第一个元素
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    double ans;
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;

    ans = solution.mincostToHireWorkers(quality, wage, k);

    cout << "answer: " << ans << endl;

    return 0;
}