//------------------------kruskals algorithm


// ---------------------disjoint set union (dsu)
struct DSU{
 
        vector<int> parent ;
        vector<int> size ;
        int comp;
        
        DSU(int N){
                parent.resize(N+1,0);
                size.resize(N+1,0);
                comp = N;
                for(int i=1;i<=N;i++){
                        make_set(i) ;
                }
        }
        void make_set(int v){
                parent[v] = v ;
                size[v] = 1 ;
        }
 
        int find_set(int v){
                if(parent[v] == v){
                        return v ;
                }
                return parent[v] = find_set(parent[v]);
        }
        void union_set(int a, int b){
                a = find_set(a) ;
                b = find_set(b) ;
 
                if(a!=b){
                        if(size[a]> size[b]){
                                swap(a, b);
                        }
                        parent[a] =  parent[b] ;
                        size[b]   += size[a];
                        comp--;
                }
 
        }
 
        int count_comp(){
                return comp;
        }
 
        int size_set(int v){
                return size[find_set(v)] ;
        }
};
 

 
struct edge{
        int u , v , w ;
        edge(int u , int v , int w ){
                this->u = u ;
                this->v = v ;
                this->w = w ;
        }
};
 
bool comp( edge &a , edge &b ){
        return a.w < b.w ;
}
 
void solve(){
 
        int n , m ;
        cin >> n >> m ;
 
        vector<edge> edg ;
 
        while(m--){
                int u , v , w ;
                cin >> u >> v >> w ;
                edge newedge(u,v,w) ;
                edg.pb(newedge) ;
        }
 
        sort(all(edg) , comp ) ;
 
        int mst_sum = 0 ;
 
        DSU vec(n) ;
 
        for(auto x : edg ){
                int u = x.u ;
                int v = x.v ;
                int w = x.w ;
 
                u = vec.find_set(u) ;
                v = vec.find_set(v) ;
 
                if(u!=v){
                        mst_sum += w ;
                        vec.union_set(u,v) ;
                }
        }
 
        cout << mst_sum << endl ;
 
}
