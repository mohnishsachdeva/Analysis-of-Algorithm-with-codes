#include<stdio.h>

int a[10][10], n, indegree[10];

void find_degree() {
    int i, j, sum;
    for(i = 1; i <= n; i++) {
        sum = 0;
        for(j = 1; j <= n; j++)
            sum += a[j][i];
        indegree[i] = sum;
        printf("%d ", indegree[i]);
    }
}

void topology() {
    int i, u, v, t[10], s[10], top = 0, k = 1;
    find_degree();
    for(i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            s[++top] = i;
        }
    }
    printf("%d top", top);
    printf("%d stop", s[top]);

    while(top != 0) {
        u = s[top--];
        t[k++] = u;
        for(v = 1; v <= n; v++) {
            if(a[u][v] == 1) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    s[++top] = v;
                }
            }
        }
    }
    printf("The topological sequence is:\n");
    for(i = 1; i <= n; i++) {
        printf("%d ", t[i]);
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    topology();
    return 0;
}