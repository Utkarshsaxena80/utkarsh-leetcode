class Solution {
public:
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
long long  dfs(int i,int j,long long val,vector<vector<int>>&grid,vector<vector<bool>>&vis){
    vis[i][j]=true;
    val +=grid[i][j];
    int m1=grid.size();
        int n=grid[0].size();
    for(int m=0;m<4;m++){
        int nx=i+dx[m];
        int ny=j+dy[m];
        if(nx<0||ny<0||nx>=m1||ny>=n) continue;
        if(vis[nx][ny]||grid[nx][ny]==0) continue;
         val+=dfs(nx,ny,0,grid,vis);
    }
    return val;
    

}
    int countIslands(vector<vector<int>>& grid, int k) {
        //this is simple dfs
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]!=0){
                   long long  val=dfs(i,j,0,grid,vis);
                   if(val%k==0) count++;
                }
            }
        }
        return count;
    }
};