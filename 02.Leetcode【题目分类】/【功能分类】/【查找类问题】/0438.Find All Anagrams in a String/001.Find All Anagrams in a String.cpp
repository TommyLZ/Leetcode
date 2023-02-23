#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> findAnagrams(string s, string p){
        vector <int> ans;
        int m = s.size();
        int n = p.size();
        vector<int> win_s (26, 0);
        vector<int> win_p (26, 0);
        int start = 0;

        if (m < n){
            return ans;
        }

        for (int i=0; i<n; ++i){
            win_p[p[i] - 'a']++;
        }

        for (int end=0; end<m; ++end){
            win_s[s[end] - 'a']++;

            if(end >= n){
                win_s[s[start] - 'a']--;
                start++;
            }

            if(win_s == win_p){
                ans.push_back(start);
            }
        }

        return ans;
    }

};

int main(){
    Solution solution;
    string s = "cbaebabacd", p = "abc";
    vector<int> ans;

    ans = solution.findAnagrams(s, p);

    cout << "ans: [";

    for(int i=0; i<ans.size(); ++i){
        if(i == ans.size()-1){
            cout << ans[i] << "]";
        }
        else{
            cout << ans[i] << ",";
        }
    }
    
    return 0;
}