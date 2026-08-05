class Solution {
public:
    bool iscycleDFS(int src, vector<bool>&vis, vector<bool>&recpath, vector<vector<int>>&edge){
        vis[src]=true;
        recpath[src]=true;

        for(int i=0;i<edge.size();i++){
            int v= edge[i][0];
            int u= edge[i][1];

            if(u==src){
                if(!vis[v]){
                    if(iscycleDFS(v,vis,recpath,edge)){
                        return true;
                    }
                }else if(recpath[v]){
                    return true;
                }
            }
        }recpath[src]=false;
        return false;
        
    }
    bool canFinish(int n, vector<vector<int>>& edge) {
        vector<bool>vis(n,false);
        vector<bool>recpath(n,false);

        for(int i =0; i<n ; i++){
            if(!vis[i]){
                if(iscycleDFS(i,vis,recpath,edge)){
                    return false;
                }
            }
        }return true;
        
    }
};