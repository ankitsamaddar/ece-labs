//(2)Write a C program to implement the breadth-first search algorithm.
#include<stdio.h>
#include<stdlib.h>

int a[30][20],q[30],vis[30],n,i,j,f=0,r=-1;
void BFS(int v) {
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !vis[i]) {
            q[++r] = i;
        }
    }
    if (f <= r) {
        vis[q[f]] = 1;
        BFS(q[f++]);
    }
}
int main() {
int v;
printf("\nEnter Vertices to represent: ");
scanf("%d",&n);
for (i=1;i<=n;i++) {
q[i]=0;
vis[i]=0;
}
printf("\nEnter graph data especially in matrix format: \n");
for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
    }
}
printf("\nEnter Starting vertex for traversal: ");
scanf("%d", &v);
BFS(v);
printf("\nReachable nodes are: \n");
for (i = 1; i <= n; i++) {
    if (vis[i]) {
        printf("%d\t", i);
    } else {
        printf("\nBfs not possible if not proper.");
    }
}
return 0;
}
