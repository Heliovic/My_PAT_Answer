#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int graph[1002][1002];
int N, M, K;
int visit[1002];

void dfs(int v);

int main()
{
    memset(graph, 0, sizeof(graph));// memset ���ֽ�Ϊ��λ���� int ֻ��������ʼ��0��-1��Ҫ��ʼ��Ϊ����ֵ���ο�fill��fill_n
    // cin��cout �ᳬʱ��scanf��printf ���ᳬʱ
    // cin >> N >> M >> K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++)
    {
        int j, k;
        // cin >> j >> k;
        scanf("%d %d", &j, &k);
        graph[j][k] = 1;
        graph[k][j] = 1;
    }
    int query[K];
    for (int i = 0; i < K; i++)
        // cin >> query[i];
        scanf("%d", &query[i]);

    for (int i = 0; i < K; i++)
    {
        int d = query[i];
        fill_n(visit, 1002, 0);// ������ 0
        visit[d] = 1;
        int component = 0;
        for (int j = 1; j <= N; j++)
        {
            if (visit[j] == 0)
            {
                component++;
                dfs(j);
            }
        }
        // cout << component - 1 << endl;
        printf("%d\n", component - 1);
    }
    return 0;
}

// ע�����鴫��
void dfs(int v)
{
    visit[v] = 1;
    for (int i = 1; i <= N; i++)
        if (graph[v][i] == 1 && visit[i] == 0)
            dfs(i);
}
