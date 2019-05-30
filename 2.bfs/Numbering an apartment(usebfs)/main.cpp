#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
const int N_MIN = 5;
const int N_MAX = 26;
int b[N_MAX][N_MAX];
int Count = 0;
int result[500];
int is_visited[N_MAX][N_MAX] = { 0 };
void bfs(int start, int start_second, int num) {
	queue<pair<int, int>> q;
	int t_count = 0;
	
	q.push(pair<int, int>(start, start_second));
	if (b[start][start_second] == 1&&is_visited[start][start_second]==0) {
		t_count++;
	}
	is_visited[start][start_second] = 1;
	while (q.size()!=0 && b[start][start_second] == 1) {
		
		pair<int, int> next = q.front();
		q.pop();
		if (b[next.first + 1][next.second] == 1 && is_visited[next.first + 1][next.second] == false) {
			is_visited[next.first + 1][next.second] = 1;
			q.push(pair<int, int>(next.first + 1, next.second));
			t_count++;
			

		}
		if (b[next.first][next.second + 1] == 1 && is_visited[next.first][next.second + 1] == false) {
			is_visited[next.first][next.second + 1] = 1;
			q.push(pair<int, int>(next.first, next.second + 1));
			t_count++;
			
		}
		if (next.first > 0) {
			if (b[next.first - 1][next.second] == 1 && is_visited[next.first - 1][next.second] == false) {
				is_visited[next.first - 1][next.second] = 1;
				q.push(pair<int, int>(next.first - 1, next.second));
				t_count++;
				
				
			}

		}
		if (next.second > 0) {
			if (b[next.first][next.second - 1] == 1 && is_visited[next.first][next.second - 1] == false) {
				is_visited[next.first][next.second - 1] = 1;
				q.push(pair<int, int>(next.first, next.second - 1));
				t_count++;
				
			}

		}
		if (b[next.first][next.second] == 1 &&b[next.first][next.second - 1] == 0 && b[next.first-1][next.second] == 0 && b[next.first][next.second +1] == 0 && b[next.first+1][next.second] == 0) {
			t_count = 1;
		}
		
		


	}
	if (t_count > 0) {
		result[Count] = t_count;
		Count++;
	}
	
}
int main(){
	int N;
	cin >> N;
	
	
	for (int i=0; i < N; i++) { //띄어쓰기 없이 수받아 저장
		
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &b[i][j]);
			
		}
		
	}
	
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			
			if (is_visited[j][i] == 0) {
				bfs(j,i, N);
				
			}

		}
	}
	
	sort(result, result+Count);
	cout << Count << endl;
	for (int i = 0; i < Count; i++) {
		cout << result[i] << endl;
	}
	return 0;
}
