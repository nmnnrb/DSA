class Solution {
    private:
    void dfs(int node , int parent ,vector<int> &discoverytim,
                vector<int> &lowtim, int &timer , vector<int> &vis,
                vector<int> adj[], vector<vector<int>> &result){
         vis[node] =1;
        lowtim[node] = discoverytim[node] = timer++;

        for(int nbr : adj[node]){
            if(parent == nbr){
                continue;
            }else if(vis[nbr] == 0){
                dfs(nbr,node , discoverytim, lowtim, timer, vis, adj,result);
                lowtim[node] = min(lowtim[node] , lowtim[nbr]);
                if( lowtim[nbr] > discoverytim[node]){
                    result.push_back({node,nbr});
                }

            }else{
                //visted = 1
                lowtim[node] = min(lowtim[node] , discoverytim[nbr]);
            }
        }


        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections ){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int timer= 0;
        int parent = -1;
        vector<int> lowtim(n); 
        vector<int>  discoverytim(n);
            vector<vector<int>> result;
        for(int i = 0 ; i< n ; i++){
            dfs(i,parent , discoverytim, lowtim, timer, vis, adj , result);
        }
    return result;
    }
       
};