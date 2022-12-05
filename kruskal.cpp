//��С��������Kruskal�㷨��1h��
#include <cstdio>
#include <cstdlib>
#define MAXN 10000 + 10
using namespace std;
 
int par[MAXN], Rank[MAXN];
typedef struct{
    int a, b, price;
}Node;
Node a[MAXN];
 
int cmp(const void*a, const void *b){
    return ((Node*)a)->price - ((Node*)b)->price;
}
void Init(int n){
    for(int i = 0; i < n; i++){
        Rank[i] = 0;
        par[i] = i;
    }
}
 
int find(int x){
    int root = x;
    while(root != par[root]) root = par[root];
    while(x != root){
        int t = par[x];
        par[x] = root;
        x = t;
    }
    return root;
}
 
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(Rank[x] < Rank[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}
//nΪ�ߵ�������mΪ��ׯ������
int Kruskal(int n, int m){
    int nEdge = 0, res = 0;
    //���߰���Ȩֵ��С��������
    qsort(a, n, sizeof(a[0]), cmp);
    for(int i = 0; i < n && nEdge != m - 1; i++){
        //�жϵ�ǰ�����ߵ������˵��Ƿ�����ͬһ����
        if(find(a[i].a) != find(a[i].b)){
            unite(a[i].a, a[i].b);
            res += a[i].price;
            nEdge++;
        }
    }
    //�������ߵ�����С��m - 1,�����������ͼ����ͨ,�ȼ��ڲ�������С������
    if(nEdge < m-1) res = -1;
    return res;
}
int main(){
    int n, m, ans;
    while(scanf("%d%d", &n, &m), n){
        Init(m);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].price);
            //����ׯ��ű�Ϊ0~m-1���������ֻ�Ǹ���ϰ�ߣ����Ǳ�Ҫ�ģ�
            a[i].a--;
            a[i].b--;
        }
        ans = Kruskal(n, m);
        if(ans == -1) printf("?\n");
        else printf("%d\n", ans);
    }
    return 0;
}