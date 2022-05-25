// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int arr[],int n, int index, int total, int sum){
        //base case
        if(total==sum) return true;
        
        if(index == n or total<sum) return false;
        
        //include
        bool inc = solve(arr, n, index+1, total, sum+arr[index]);
        if(inc) return true;
        //exclude
        bool exc = solve(arr, n, index+1, total, sum);
        if(exc) return true;
        
        return inc or exc;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0; i<N; i++) total += arr[i];
        if(total%2==1) return 0;
        return solve(arr,N,0,total/2,0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends