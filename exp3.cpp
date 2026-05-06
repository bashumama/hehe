#include<iostream>
#include<vector>
#include<queue>
# define max 10
using namespace std;
int n;
int matrix[max][max];
int visited[max];
vector<int>adj[max];


class graph{
    public:
    void init(){
        for(int i=1;i<=n;i++){
            visited[i]=0;
            adj[i].clear();
            for(int j=1;j<=n;j++){
                matrix[i][j]=0;
            }
        }
    }
    void resetvisited(){
        for(int i=1;i<=n;i++){
            visited[i]=0;
        }
    }
    void creategraph(){
        int u,v ,edges;
        cout<<"Enter the number of edges::";
        cin>>edges;
        cout<<"Enter number of vertex::";
        cin>>n;
        init();
        for(int i=1;i<=edges;i++){
            cout<<"Enter u & v::";
            cin>>u>>v;
            matrix[u][v]=matrix[v][u]=1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void printmatrix(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<matrix[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void printlist(){
       for(int i=1;i<=n;i++){
           cout<<i<<"->";
           for(int x:adj[i]){
               cout<<x;
           }
           cout<<endl;
       }
    }
    void DFS(int v){
        resetvisited();
        cout<<v<<" ";
        visited[v]=1;
        for(int i=1;i<=n;i++){
            if(matrix[v][i]==1 &&visited[i]==0){
                DFS(i);
            }
        }
    }
    void BFS(int start){
        resetvisited();
        queue<int>q;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int v=q.front();
            cout<<v<<" ";
            q.pop();
            for(int x:adj[v]){
                if(visited[x]==0){
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
    }
        
};
int main(){
    graph g;
   int choice=0;
   while(choice!=6){
        cout<<"Enter the choise::";
        cin>>choice;
        switch(choice){
            case 1:{
                g.creategraph();
                break;
            }
            case 2:{
                g.printmatrix();
                break;
            }
            case 3:{
                g.printlist();
                break;
            }
            case 4:{
                int ver;
                cout<<"Enter starting  vertex::";
                cin>>ver;
                g.DFS(ver);
                break;
            }
            case 5:{
                int ver;
                cout<<"Enter starting  vertex::";
                cin>>ver;
                g.BFS(ver);
                break;
            }
            case 6:{
                choice=6;
                break;
            }
            default:
                cout<<"wrong choice entered\n";
        }
   }
   return 0;
}
