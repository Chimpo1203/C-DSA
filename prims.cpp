#include<bits/stdc++.h>
using namespace std;


int helper(vector<int> &dist,vector<bool> &mstset){
    int ans=INT_MAX,vertex;

    for(int i=0;i<dist.size();i++){
        if(ans>dist[i] && !mstset[i]){
            ans=dist[i];
            vertex=i;
        }
    }

    return vertex;
}


void Prims(vector<pair<int,int>> *adj,int n){


    vector<bool> mstset(n,false); // for storing in result in a set
    vector<int> dist(n,INT_MAX); // storing minimum distance
    vector<int> parent(n); // parent child holding like DSU

    parent[0]=-1;
    dist[0]=0;


    for(int i=0;i<n-1;i++){


        int getMinimumVertex = helper(dist,mstset);

        mstset[getMinimumVertex]=true;


        for(auto x: adj[getMinimumVertex]){


            if(!mstset[x.first] && dist[x.first]>x.second){

                dist[x.first]=x.second;
                parent[x.first]=getMinimumVertex;
            }

        }
    }

    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-->"<<i<<" -------->"<<dist[i]<<endl;
    }

}

int main(){


    int n;
    cin>>n;

    int m=9;
    vector<pair<int,int>> adj[n];

    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    Prims(adj,n);
}
