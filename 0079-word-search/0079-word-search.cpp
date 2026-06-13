class Solution {
public:
    
    bool rec(vector<vector<char>>& board, string word,int row,int col,int m,int n,int i){
        if(i==word.size()) return true;
        if(board[row][col]=='$') return false;
         bool ans1=false,ans2=false,ans3=false,ans4=false;
         char temp=board[row][col];
         board[row][col]='$';
        if(row>0 && board[row-1][col]==word[i]){
             ans1 = rec(board,word,row-1,col,m,n,i+1);
        } 
        if(row<m-1 && board[row+1][col]==word[i]){
             ans2 = rec(board,word,row+1,col,m,n,i+1);
        } 
        if(col<n-1 && board[row][col+1]==word[i]){
             ans3 = rec(board,word,row,col+1,m,n,i+1);
        } 
        if(col>0 && board[row][col-1]==word[i]){
             ans4 = rec(board,word,row,col-1,m,n,i+1);
        }
        board[row][col]=temp; 
        return ans1 || ans2|| ans3 || ans4;     
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && rec(board,word,i,j,m,n,1)) return true;
            }
        }
        return false;
    }
};