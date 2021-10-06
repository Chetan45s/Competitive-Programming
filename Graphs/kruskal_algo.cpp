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
#define __ std::chrono::high_resolution_clock::now();
#define _c_ std::chrono::duration_cast<std::chrono::microseconds>
#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int find(int i,vi &parent){

    if(parent[i] == -1){
        return i;
    }

    return parent[i] = find(parent[i],parent);
}

void merge(int a,int b,vi &parent,vi &rank){

    int s1 = find(a,parent);
    int s2 = find(b,parent);

    if(s1!=s2){
        if(rank[s1] > rank[s2]){
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
        else{
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
    }
}

int32_t main(){

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    int V,E,w,u,v;
    cin>>V>>E;

    vector<vector<int>> adj, mst_edges;
    fo(i,0,E){
        cin>>v>>u>>w;
        adj.pb({w,v-1,u-1});
    }

    vi parent(V,-1);
    vi rank(V,1);
    auto start = __ 

    sort(adj.begin(),adj.end());

    int spanning_tree_cost = 0;

    for(auto edge:adj){
        int weight = edge[0];
        int first = edge[1];
        int second = edge[2];

        if(find(first,parent) != find(second,parent)){
            merge(first,second,parent,rank);
            mst_edges.pb({first+1,second+1,weight});
            spanning_tree_cost += weight;
        }
    }
    auto stop = __
    int time_taken = _c_(stop - start).count(); 
    cout<<"From    To   Weight"<<endl;

    for(auto s : mst_edges){
        cout<<s[0]<<"\t\t"<<s[1]<<"\t\t"<<s[2]<<endl;
    }
    cout<<"Cost of MST : "<<spanning_tree_cost<<endl;
    cout<<"Time Taken : "<<time_taken<<" ms"<<endl;
    cout<<endl;
    return 0;
}

