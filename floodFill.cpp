class Solution {
public:
    
     void fill(vector<vector<int>>& image,int r,int c,int oldcolor,int i,int j,int newColor){
        if(i<0 ||j<0 ||i>=r  ||j>=c ||image[i][j]!=oldcolor || newColor==oldcolor){
            return;
        }
        image[i][j] = newColor;
        fill(image,r,c,oldcolor,i+1,j,newColor);
        fill(image,r,c,oldcolor,i-1,j,newColor);
        fill(image,r,c,oldcolor,i,j+1,newColor);
        fill(image,r,c,oldcolor,i,j-1,newColor);   
    }  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
        int r=image.size();
        int c=image[0].size();
        int oldcolor=image[sr][sc];
        fill(image,r,c,oldcolor,sr,sc,newColor);
        return image;
    } 
};

