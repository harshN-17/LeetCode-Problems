// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meet(n);
        for(int i=0;i<n;i++){
            meet[i] = {start[i],end[i]};
        }
        
        sort(meet.begin(), meet.end(), cmp);
        
        int i=0,j=1, cnt=0;
        while(j<n){
            if(meet[j].first > meet[i].second){
                i=j;
                cnt++;
            }
            j++;
        }
        return cnt+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends