#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include <functional>
#pragma warning(disable:4996)

using namespace std;

int INF = INT_MAX;
int num_v, num_e;
int start;
vector<pair<int, int>> map[20010];

vector<int> dijkstra(int start) {
	vector<int> dist(num_v + 1, INF);
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

	pq.push(make_pair(0,start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur_vertex = pq.top().second;
		int cur_distance = pq.top().first;
		pq.pop();

		if (dist[cur_vertex] < cur_distance) continue;


		for (int i = 0; i < map[cur_vertex].size(); i++) {
			int next_vertex = map[cur_vertex][i].first;
			int next_distance = cur_distance + map[cur_vertex][i].second;

			if(next_distance < dist[next_vertex]){
				dist[next_vertex] = next_distance;
				pq.push(make_pair(next_distance, next_vertex));
			}
		}
	}

	return dist;
}

int main() {

	scanf("%d %d", &num_v, &num_e);
	scanf("%d", &start);
	
	for (int i = 0; i < num_e; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		map[u].push_back(make_pair(v, w));
	}

	vector<int> result = dijkstra(start);

	for (int i = 1; i <= num_v; i++) {
		if (result[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", result[i]);
		}
	}

	return 0;
}