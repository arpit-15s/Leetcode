class Solution {
public:
    int find(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        int temp = find(parent[x], parent);
        parent[x] = temp;
        return temp;
    }
    
    bool union1(int x, int y, vector<int>& rank, vector<int>& parent){
        int lx = find(x, parent);
        int ly = find(y, parent);
        if(lx != ly){
            if(rank[lx] > rank[ly]){
                parent[ly] = lx;
            } else if(rank[lx] < rank[ly]){
                parent[lx] = ly;
            } else{
                parent[lx] = ly;
                rank[ly]++;
            }
            return true;
        }
        return false;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());
        vector<int> parent1(n), parent2(n), rank1(n, 1), rank2(n, 1);
        for(int i = 0; i < n; i++){
            parent1[i] = i;
            parent2[i] = i;
        }
        int count = 0, mergeda = 1, mergedb = 1;
        for(vector<int> edge: edges){
            int type = edge[0];
            int u = edge[1] - 1;
            int v = edge[2] - 1;
            if(type == 3){
                bool temp1 = union1(u, v, rank1, parent1);
                bool temp2 = union1(u, v, rank2, parent2);
                if(temp1) mergeda++;
                if(temp2) mergedb++;
                if(!temp1 && !temp2) count++; 
            } else if(type == 2){
                bool temp2 = union1(u, v, rank2, parent2);
                if(!temp2) count++;
                if(temp2) mergedb++;
            } else{
                bool temp1 = union1(u, v, rank1, parent1);
                if(!temp1) count++;
                if(temp1) mergeda++;
            }
        }
        if(mergeda != n ||mergedb != n) return -1;
        return count;
    }
};