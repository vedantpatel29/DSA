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

    void topoorder(int src,vector<bool>&vis,stack<int>&s,vector<vector<int>>&edges){
        vis[src]=true;
        

        for(int i=0;i<edges.size();i++){
            int v= edges[i][0];
            int u= edges[i][1];

            if(u==src){
                if(!vis[v]){
                    topoorder(v,vis,s,edges);
                    
                }
            }
        }s.push(src);
    }    
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<bool>recpath(n,false);
        vector<int>ans;

        for(int i =0; i<n ; i++){
            if(!vis[i]){
                if(iscycleDFS(i,vis,recpath,edges)){
                    return ans;
                }
            }
        }
        stack<int>s;
        vis.assign(n,false);

        for(int i=0; i<n ;i++){
            if(!vis[i]){
                topoorder(i,vis,s,edges);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        } 
        return ans;
        
    }
};