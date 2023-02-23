#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool checkInclusion(string s1, string s2){
        unordered_map<char, int> visit;

        if (s1.size() > s2.size()){
            return false;
        }

        for (auto &c : s1){
            visit[c]++;
        }

        int start = 0, end = 0;

        while (end < s2.size()){
            char c = s2[end++];
            visit[c]--;
            
            while (start < end && visit[c] < 0){
                visit[s2[start++]]++;
            }

            if(end - start == s1.size()){
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution solution;
    string s1 = "ab", s2 = "eidbaooo";
    bool ans;

    ans = solution.checkInclusion(s1, s2);

    cout << "ans: " << ans << endl;
    
    return 0;
}
