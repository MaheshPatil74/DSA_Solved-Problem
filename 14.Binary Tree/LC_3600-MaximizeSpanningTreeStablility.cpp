class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return false;
        parent[pa]=pb;
        return true;
    }

    bool can(int n, vector<vector<int>>& edges, int k, int target){

        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;

        int used=0;
        int upgrades=0;

        vector<vector<int>> normal;
        vector<vector<int>> upgrade;

        // mandatory edges
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must==1){
                if(s<target) return false;

                if(unite(u,v)) used++;
                else return false;
            } 
            else{
                if(s>=target) normal.push_back(e);
                else if(s*2>=target) upgrade.push_back(e);
            }
        }

        // use edges without upgrade first
        for(auto &e:normal){
            if(unite(e[0],e[1])){
                used++;
                if(used==n-1) return true;
            }
        }

        // then use upgrade edges
        for(auto &e:upgrade){
            if(upgrades>=k) break;

            if(unite(e[0],e[1])){
                upgrades++;
                used++;
                if(used==n-1) return true;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo=0,hi=200000;
        int ans=-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }

        return ans;
    }
};