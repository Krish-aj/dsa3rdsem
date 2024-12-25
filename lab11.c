#include <stdio.h>
int a[10][10],visited[10],n;

void bfs(int s){
    int i;
    visited[s]=1;
    for(i=1;i<=n;i++){
        if(visited[i]==0&&a[s][i]==1)
            bfs(i);
    }
}

int main(){
    int i,j,s;

    printf("enter the number of vertices: ");
    scanf("%d",&n);

    printf("enter the adjacent matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("enter the source node: ");
    scanf("%d",&s);
    bfs(s);

    printf("node reachable from %d are: ",s);
    for(i=1;i<=n;i++){
        if(visited[i]=1&& i!=s){
            printf("%d,",i);
        }
    }
    return 0;
}
