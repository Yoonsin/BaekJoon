#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;


bool isVisited[MAX];
vector<int> graph[MAX];
int parent[MAX];
int N;

void bfs()
{
    queue<int> q;
    q.push(1);
    isVisited[1] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int node = graph[now][i];
            if (!isVisited[node]) {
                parent[node] = now;
                isVisited[node] = true;
                q.push(node);
            }
        }

    }
}

int main(int argc, char** argv)
{
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
