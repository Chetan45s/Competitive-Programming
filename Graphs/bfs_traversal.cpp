#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i, z, n) for (int i = z; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

void addEdge(vi adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

void bfs(vi adj[], int src,int V){
    vector <bool> visited(V,false);
    queue <int> q;
    q.push(src);
    cout<<src<<" ";
    visited[src] = true;
    while(!q.empty()){
        int q1 = q.front();
        q.pop();
        for(int i=0;i<adj[q1].size();i++){
            if(visited[adj[q1][i]] == false){
                visited[adj[q1][i]] = true;
                q.push(adj[q1][i]);
                cout<<adj[q1][i]<<" ";
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());


    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    int V,E,u,v,src;
    cin>>V>>E>>src;
    vi adj[V];

    fo(i,0,E){
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    fo(i,0,V){
        cout<<i<<"->";
        for(auto c:adj[i]){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    bfs(adj,src,V);
    return 0;
}