class Solution {
public:
    vector<pair<int,int>> findPair(vector<int> &nums){
        int n = nums.size();
        vector<pair<int,int>> ans(n);
        stack<int> st;
        //find ngl
        for(int i=0; i<n; i++){
            while(!st.empty() and nums[st.top()] <= nums[i]) st.pop();
            
            if(st.empty()) ans[i].first = -1;
            else ans[i].first = st.top();
            st.push(i);
        }
        
        //clear stack
        while(!st.empty()) st.pop();
        
        //find nsr
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and nums[st.top()] >= nums[i]) st.pop();
            
            if(st.empty()) ans[i].second = n;
            else ans[i].second = st.top();
            st.push(i);
        }
        return ans;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        v = findPair(nums);
        // for(int i=0; i<n; i++)
        //     printf("\n(%d,%d)",v[i].first,v[i].second);
        bool flag = true;
        int s=0,e=-1;
        for(int i=0;i<n;i++){
            int j = v[i].first;
            int k = v[i].second;
            if(j>=0 or k<n){
                if(flag){
                    s=i;
                    flag = false;
                }
                e=i;
            }
        }
        return e-s+1;
    }
};