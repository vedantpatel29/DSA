class Solution {
public:
    int Mandist(vector<vector<int>>& points,int p1, int p2){
        return abs(points[p1][0]-points[p2][0]) +  abs(points[p1][1]-points[p2][1]);
                
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> mstset(n,false);

        int mstcost = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

        pq.push({0,0});

        while(pq.size()>0){
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;

            pq.pop();

            if(mstset[node]) {
                continue;
            }
            mstset[node]=true;
            mstcost += wt;

            for(int i=0; i< n ; i++){
                if(!mstset[i]){
                    int edgewt = Mandist(points,node,i);
                    pq.push({edgewt,i});
                }
                
            }
        }return mstcost;
        
    }
};