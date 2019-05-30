/*한윤성 http://22ema.github.io
queue 에대한 공부*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 9; // 노드의 개수
int visit[9]; // 방문 했는지 확인하는 배열
vector<int> a[10]; // 백터를 만들어 경로를 갔는지 확인함

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		// 큐에 값이 있을 경우 계속 반복 실행
		// 큐에 값이 있다. => 아직 방문하지 않은 노드가 존재 한다.
		int x = q.front();	// queue의 front를 x에 저장한다.
		q.pop();			// 젤 앞에 있는것을 pop 시킨다.
		printf("%d", x);	// x의 값을 출력한다.
		for (int i = 0; i < a[x].size(); i++) {// a[x](vector)의 크기 만큼 반복한다.
			int y = a[x][i];//해당 벡터의 i위치를 변수 y에 넣는다.
			if (!visit[y]) {//방문한적없으면
				q.push(y);  //q에 y를 push한다.
				visit[y] = true; // 방문했다고 표시한다.
			}
		}
	}
}
int main() {
	for (int i = 0; i < number; i++) { // 방문했다는 증거
		int N, M;
		cin >> N >> M;
		a[N].push_back(M);
		a[M].push_back(N);

	}
	bfs(1);
	return 0;
}