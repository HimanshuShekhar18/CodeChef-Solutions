// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

// Problem Link: https://www.codechef.com/problems/MCO16405

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

vector<vector<ll>> graph(MAX_N);
vector<vector<ll>> graph2(MAX_N);

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


vector<ll> topo;
vector<ll> new_topo;
vector<bool> vis;
vector<ll> new_cost(MAX_N);
vector<ll> cost(MAX_N);
vector<ll> code(MAX_N);

void dfs2(ll node){
  vis[node]=true;
  code[node]=cnt;
  new_cost[cnt]+=cost[node];
  for(auto v: graph2[node]){
    if(!vis[v]) dfs2(v);
  }
}
void dfs1(ll node){
  vis[node]=true;
  for(auto v: graph[node]){
    if(!vis[v]) dfs1(v);
  }

  topo.push_back(node);
}

void solve(){
    cnt=0;  // used for indexing the SCC
    cin>> n >> m;

    // 0-based indexing
    for(ll i = 0; i<n; i++){
      cin >> cost[i];
    }

    vector<pair<ll,ll>> edges;   // to store the edges

    // 0-based indexing
    for(ll i=0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    x--;
    y--;
    graph[x].push_back(y);  // original graph
    graph2[y].push_back(x); // graph with edges reversed
    edges.push_back({x,y});
    }

    vis.assign(MAX_N, false);

    // step 1: Get the order of nodes in their finishing time
    for(ll i = 0; i<n; i++){
      if(!vis[i]){
        dfs1(i);
    }
    }

    // operation is similar to stack operation
    // basically topo order will be like 5 4 3 2 1, but we want 1 2 3 4 5, so we reversed it
    reverse(topo.begin(),topo.end());
    
    vis.assign(MAX_N, false);

    // now traversing vertices according to "topo" vector
    for(ll i = 0; i<n; i++){
      if(!vis[topo[i]]){
         dfs2(topo[i]);
         cnt++;
      }
    }
 
    // saving the new topological order according to order of SCCs Condensed graph be explored
    set<ll>st;
    for(ll i = 0; i<n; i++){
            if(!st.count(code[topo[i]])){
              st.insert(code[topo[i]]);
              new_topo.push_back(code[topo[i]]);
            }
    }


    vector<vector<ll>> adj(cnt); // to construct edges of SCCs Condensed Graph

    // construct the condensed SCC Graph
    for(auto it: edges){
       ll u = code[it.first];
       ll v = code[it.second];
       if(u!=v){
            adj[u].push_back(v);
          }
    }

    vector<ll> dp(cnt,0);

    // traversing will be done in reverse order of new_topo
    // i.e. niche se upar i.e fron sink to source
    reverse(new_topo.begin(),new_topo.end());

    for(auto it: new_topo){
      for(auto v: adj[it]){
        dp[it]=max(dp[it],dp[v]);
      }
      dp[it]+=new_cost[it];
    }   

  for(ll i = 0; i<n; i++){
    cout << dp[code[i]] << " ";
  } 

  cout << endl; 

       fflush(stdout);
       cout << flush;

}

int main() {

    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

// time_t timetoday
//    time (&timetoday);
//    cout << asctime(localtime(&timetoday)) << endl;
//    // return 0;

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     solve();
       return 0;
}
