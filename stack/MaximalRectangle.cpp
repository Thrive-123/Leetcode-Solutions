class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) 
          return 0;
          int r=matrix.size();
          int c=matrix[0].size();
          vector<int>heights(c,0);
          int maxArea=0;
          for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')
                  heights[j]++;
                else
                  heights[j]=0;
            }
            stack<int> st;
            for(int j=0;j<=c;j++){
                int currHeight=(j==c)?0:heights[j];
                while(!st.empty() && currHeight<heights[st.top()]){
                    int h=heights[st.top()];
                    st.pop();
                    int w;
                    if(st.empty())
                       w=j;
                    else
                       w=j-st.top()-1;
                    maxArea=max(maxArea,h*w);
                }
                st.push(j);
            }
          }
          return maxArea;
    }
};
