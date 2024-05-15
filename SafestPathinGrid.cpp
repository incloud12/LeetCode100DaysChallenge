#define p pair<int,pair<int,int>>
#define pp pair<int,int>
class Solution {
public:
    int arrX[4]={0,0,-1,1};
    int arrY[4]={-1,1,0,0};

    void f(vector<vector<int>>& grid,vector<vector<int>>& score,int n){
        queue<pp> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    score[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto t=q.front();
            q.pop();

            int x=t.first,y=t.second;
            int s=score[x][y];

            for(int i=0;i<4;i++){
                int currX=x+arrX[i];
                int currY=y+arrY[i];

                if(currX>=0 && currX<n && currY>=0 && currY<n && score[currX][currY]> 1+s){
                    score[currX][currY]=1+s;
                    q.push({currX,currY});
                }
            }
        }

        
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0] || grid[n-1][n-1])
        return 0;

        vector<vector<int>> score(n,vector<int>(n,INT_MAX));
        f(grid,score,n);

        vector<vector<bool>> visited(n,vector<bool>(n,false));

        priority_queue<p> pq;
        pq.push({score[0][0],{0,0}});

        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();

            int safe=t.first;
            if(t.second.first==n-1 && t.second.second==n-1)
            return safe;

            visited[t.second.first][t.second.second]=true;

            for(int i=0;i<4;i++){
                int currX=t.second.first+arrX[i];
                int currY=t.second.second+arrY[i];

                if(currX>=0 && currX<n && currY>=0 && currY<n && !visited[currX][currY]){
                    int s=min(safe,score[currX][currY]);
                    pq.push({s,{currX,currY}});
                    visited[currX][currY]=true;
                }
            }
        }

        return -1;
        
    }
};
