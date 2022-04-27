// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(vector<string>& dict, string s, string t, vector<string> &res){
        if(s==""){
            t.pop_back();
            res.push_back(t);
            return;
        }
        
        int n = s.size();
        for(int i=1;i<=n;i++){
            string left = s.substr(0,i);
            if(find(dict.begin(), dict.end(), left) != dict.end())
                solve(dict, s.substr(i), t+left+" ", res);
            
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> res;
        solve(dict,s,"",res);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends