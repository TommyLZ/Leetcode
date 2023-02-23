#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool checkInclusion(string s1, string s2){
        vector <int> ans;
        int m = s1.size();
        int n = s2.size();
        vector<int> win_s1 (26, 0);
        vector<int> win_s2 (26, 0);
        int start = 0;

        if (n < m){
            return false;
        }

        for (int i=0; i<n; ++i){
            win_s1[s1[i] - 'a']++;
        }

        for (int end=0; end<m; ++end){
            win_s2[s2[end] - 'a']++;

            if(end >= m){
                win_s2[s2[start] - 'a']--;
                start++;
            }

            if(win_s1 == win_s2){
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