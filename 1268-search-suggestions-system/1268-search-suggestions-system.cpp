class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        string prefix = "";
        int index = 0, start = 0, n = products.size();
        for(char &c: searchWord) {
            prefix += c;
            index = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();
            vector<string> temp;
            
            for(int i = index; i < min(index + 3, n) ; i++) {
                if(products[i].find(prefix) == string::npos) break;
                temp.push_back(products[i]);
            }
            
            res.push_back(temp);
        }
        return res;
    }
};