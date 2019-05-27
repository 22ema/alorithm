#include<iostream>  
#include <vector>
using namespace std;
const int N_MAX = 1001;
int N; //³ëµåÀÇ °¹¼ö
int M; //°£¼±ÀÇ °¹¼ö
vector<int> path[N_MAX];
bool is_visited[N_MAX];
void dfs(int number) {
	is_visited[number] = true;
	for (int i = 0; i < path[number].size(); i++) {
		int next = path[number][i];

		if (is_visited[next] == false) {
			dfs(next);
		}
	}

	
}


int main() {
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int K, J;
		cin >> K >> J;
		path[K].push_back(J);
		path[J].push_back(K);
	}
	int Count = 0;
	for (int i = 1; i <= N; i++) {
		if (is_visited[i] == false) {
			dfs(i);
			Count++;
		}
	}
	cout << Count << endl;
	return 0;
	
}