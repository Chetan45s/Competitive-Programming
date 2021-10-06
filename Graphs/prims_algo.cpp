#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i, z, n) for (int i = z; i < n; i++)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define __ std::chrono::high_resolution_clock::now();
#define _c_ std::chrono::duration_cast<std::chrono::microseconds>


class Prims{

    vpii *l;
    int V;
    public:
    Prims(int n){
        V = n;
        l = new vpii [n];
    }

    void addEdge(int x,int y,int w){
        l[x].pb({y,w});
        l[y].pb({x,w});
    }

    vpii mst(){
        vpii result;
        priority_queue<pii,vpii,greater<pii>> Q;
        bool *visited = new bool[V]{0};
        int ans = 0;

        Q.push({0,0});

        while(!Q.empty()){
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if(visited[to]){
                continue;
            }
            result.pb({to,weight});
            ans += weight;
            visited[to] = 1;

            for(auto x:l[to]){
                if(visited[x.first] == 0){
                    Q.push({x.second,x.first});
                }
            }
        }
        return result;
    }
};


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif


    int n,m,w,u,v;
    cin>>n>>m;

    Prims p(n);

    fo(i,0,m){
        cin>>v>>u>>w;
        p.addEdge(v-1,u-1,w);
    }
    auto start = __ 
    vpii result(p.mst());
    auto stop = __
    int time_taken = _c_(stop - start).count(); 
    int sum = 0;
    cout<<"Edges\tWeights"<<endl;
    for(auto s:result){
        sum += s.second;
        cout<<s.first+1<<"\t\t"<<s.second<<endl;
    }
    cout<<"Mst Cost : "<<sum<<endl;
    cout<<"Time Taken : "<<time_taken<<" ms"<<endl;

    return 0;
}

/*
12 20
2 3 1
9 10 1
2 5 2
3 7 2
7 9 2
3 4 2
11 12 3
5 6 4
1 2 6
1 3 6
1 4 6
5 3 7
10 12 8
6 8 10
6 7 11
8 9 12
9 11 16
4 10 18
7 8 22
8 11 25
*/