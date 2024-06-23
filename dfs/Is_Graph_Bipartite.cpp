class Solution {
public:
    bool dfs(int src,vector<int>&color,vector<vector<int>>& adj,int col)
    {
        color[src]=col;
        for(int child : adj[src])
        {
            if(color[child]==-1){
                if(dfs(child,color,adj,1-col)==false)
                    return false;
            }
            else{
                if(color[child]==color[src])
                    return false; 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,color,adj,0)==false)
                    return false;
            }
        }
        
        return true;
    }
};
