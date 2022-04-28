// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    //checks if the stirng is palindrome
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++] != s[j--]) 
                return false;
        }
        return true;
    }
    
    void solve(string s, vector<vector<string>> &res, vector<string> temp, int idx){
        if(s==""){
            res.push_back(temp);
            return;
        }
        
        for(int i=1; i<=s.size(); i++){
            string left = s.substr(0,i); //stores the left substring
            string right = s.substr(i); // stores the right substring
            if(isPalindrome(left)){
                temp.push_back(left); // if the substring is palindrome pushh it in temp vector
                solve(right, res, temp, idx); // recursively call for the right substring
                temp.pop_back(); // backtracking
            }
        }  
    }
    
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> res;
        vector<string> temp;
        solve(S, res, temp, 0);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends