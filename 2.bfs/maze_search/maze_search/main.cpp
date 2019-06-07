/*bfs 최단거리를 구하는 문제
미로찾기 문제임 백준 2178번문제
22ema.github.io*/

#include<iostream>
#include<queue>

#define MAX 101
using namespace std;
int N;
int M;
int maze[MAX][MAX];
int plus_minus[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
queue<pair<int, int>> q;
void bfs() {
	q.push(pair<int, int>(0, 0));
	while (!q.empty()) {
		pair<int, int>current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first + plus_minus[i][0];
			int ny = current.second + plus_minus[i][1];
			if (nx >= 0 && nx < N && ny >=0 && ny < M && maze[nx][ny] == 1) {
				q.push(pair<int,int>(nx, ny));
				maze[nx][ny] = maze[current.first][current.second] + 1;

			}
		}
	}
	cout << maze[N-1][M-1] << endl;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}
	bfs();
	
	
}