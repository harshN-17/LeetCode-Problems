class Solution
{
public:
    const vector<string> pad = {"", "", "abc", "def", "ghi", "jkl",
                                "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string s)
    {
        if (s == "")
            return {};
        else
            return comb(s);
    }
    vector<string> comb(string s)
    {
        if (s.length() == 0)
        {
            vector<string> temp;
            temp.push_back("");
            return temp;
        }
        char first = s[0];
        string t = s.substr(1);

        vector<string> tempans = comb(t);
        string chop = pad[first - '0'];
        vector<string> r;
        for (int i = 0; i < chop.length(); i++)
        {
            for (auto it : tempans)
            {
                r.push_back(chop[i] + it);
            }
        }
        return r;
    }
};