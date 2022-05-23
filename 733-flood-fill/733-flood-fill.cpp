class Solution {
public:
    void solve(vector<vector<int>>& image, int newColor, int color, int sr, int sc){
        if(image[sr][sc]==color){
            image[sr][sc] = newColor;        
            if(sr-1>=0) solve(image, newColor, color, sr-1, sc);
            if(sc-1>=0) solve(image, newColor, color, sr, sc-1);
            if(sr+1<image.size()) solve(image, newColor, color, sr+1, sc);
            if(sc+1<image[0].size()) solve(image, newColor, color, sr, sc+1);    
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color != newColor)
            solve(image, newColor, color,sr,sc);
        return image;
    }
};