#include <iostream>
#include <set>
#include <vector>
#define INF 1e9
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start);

int main() {
	int vertex_count, edge_count;
	cin >> vertex_count >> edge_count;

	vector<vector<pair<int, int>>> graph(vertex_count);

	for (int i = 0; i < edge_count; i++)
	{
		int a, b, weight;
		cin >> a >> b >> weight;

		graph[a].push_back({ b, weight }); // для неоринетированного графа
		graph[b].push_back({ a, weight });
	}

	int start;
	cin >> start;

	vector<int> dist = dijkstra(graph, start);

	for (int d : dist)
	{
		if (d != INF) {
			cout << d << " ";
		}
		else {
			cout << "X ";
		}
	}

	return 0;
}

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start) {
	vector<int> dist(graph.size(), INF)	;
	dist[start] = 0;

	set<pair<int, int>> q;
	q.insert({ dist[start], start });

	while (!q.empty())
	{
		int nearest = q.begin()->second;
		q.erase(q.begin());

		for (auto index : graph[nearest]) {
			if (dist[index.first] > dist[nearest] + index.second) {
				q.erase({ dist[index.first], index.first });
				dist[index.first] = dist[nearest] + index.second;
				q.insert({dist[index.first], index.first});
			}
		}
	}

	return dist;
}