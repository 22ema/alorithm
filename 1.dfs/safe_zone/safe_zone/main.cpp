#include<iostream>
#include<vector>
#include<algorithm>
#define N_MAX 101
int zone[N_MAX][N_MAX];
int is_visited[N_MAX][N_MAX];
int N;
int t_count;
int result;
int Count[101];
using namespace std;

void dfs(int start, int start_second,int thresh) {
	if (zone[start][start_second] >= thresh && is_visited[start][start_second] == 0) {
		is_visited[start][start_second] = 1;
		t_count++;
	}
	if (zone[start][start_second] >= thresh) {
		if (zone[start + 1][start_second] >= thresh && is_visited[start + 1][start_second] == 0) {
			dfs(start + 1, start_second, thresh);
			is_visited[start + 1][start_second] = 1;
			t_count++;
		}
		if (zone[start][start_second + 1] >= thresh && is_visited[start][start_second + 1] == 0) {
			dfs(start, start_second + 1, thresh);
			is_visited[start][start_second + 1] = 1;
			t_count++;
		}
		if (start > 0) {
			if (zone[start - 1][start_second] >= thresh && is_visited[start - 1][start_second] == 0) {
				dfs(start - 1, start_second, thresh);
				is_visited[start - 1][start_second] = 1;
				t_count++;
			}
		}
		if (start_second > 0) {
			if (zone[start][start_second - 1] >= thresh && is_visited[start][start_second - 1] == 0) {
				dfs(start, start_second - 1, thresh);
				is_visited[start][start_second - 1] = 1;
				t_count++;
			}
		}
	}
	
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> zone[i][j];
			
		}
		
	}
	Count[0] = 1;
	
	for(int k = 1; k < 100; k++){
		int Count_s=0;
		
		memset(is_visited, 0, sizeof(is_visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (is_visited[N_MAX][N_MAX] == 0) {
					t_count = 0;
					dfs(i, j,k);
					
					if (t_count > 0) {
						Count_s++;
					}
				}

			}
		}
		Count[k] = Count_s;
		if (Count[k] == 0) {
			break;
		}
	}
	
	int max = Count[0];
	for (int i = 1; i < sizeof(Count); i++) {
		if (max < Count[i]) {
			max = Count[i];
		}
	}
	cout << max << endl;

	return 0;
}
