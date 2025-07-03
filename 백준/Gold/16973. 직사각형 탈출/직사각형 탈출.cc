#include<iostream>
#include<queue>
 
#define endl "\n"
#define MAX 1000
using namespace std;
 
int N, M, H, W, Sx, Sy, Ex, Ey;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
    cin >> H >> W >> Sx >> Sy >> Ex >> Ey;
    Sx--; Sy--; Ex--; Ey--;
}
 
bool Can_Move(int x, int y, int dir)
{
    if (dir == 0)
    {
        int ny = y + W - 1;
        if (ny >= M) return false;
 
        for (int i = x; i < x + H; i++)
        {
            if (MAP[i][ny] == 1) return false;
        }
    }
    else if (dir == 1)
    {
        for (int i = x; i < x + H; i++)
        {
            if (MAP[i][y] == 1) return false;
        }
    }
    else if (dir == 2)
    {
        int nx = x + H - 1;
        if (nx >= N) return false;
 
        for (int i = y; i < y + W; i++)
        {
            if (MAP[nx][i] == 1) return false;
        }
    }
    else if (dir == 3)
    {
        for (int i = y; i < y + W; i++)
        {
            if (MAP[x][i] == 1) return false;
        }
    }
 
    return true;
}
 
void BFS(int a, int b)
{
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();
 
        if (x == Ex && y == Ey)
        {
            cout << Cnt << endl;
            return;
        }
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (Visit[nx][ny] == false)
                {
                    if (Can_Move(nx, ny, i) == true)
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}
 
void Solution()
{
    BFS(Sx, Sy);
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}