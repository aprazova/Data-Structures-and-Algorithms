#include <iostream>
#include <vector>
#include <climits>

const long long WEIGHT = 20000000000;

int minVertex(long long* distance, bool* visited, int n)
{
	int minV = -1;
	for (size_t i = 0; i < n; i++)
	{
		if (!visited[i] && ((minV == -1) || distance[i] < distance[minV]))
		{
			minV = i;
		}
	}
	return minV;

}

void dijkstra(std::vector<std::pair<int, int>>* edges, int n, int s)
{
	long long* distance = new long long[n];
	bool* visited = new bool[n];
	for (size_t i = 0; i < n; i++)
	{
		distance[i] = WEIGHT;
		visited[i] = false;
	}
	distance[s] = 0;
	for (size_t i = 0; i < n - 1; i++)
	{
		int minV = minVertex(distance, visited, n);
		visited[minV] = true;
		for (size_t j = 0; j < edges[minV].size(); j++)
		{
			long long dist = distance[minV] + edges[minV][j].second;
			if (dist < distance[edges[minV][j].first] && !visited[edges[minV][j].first])
			{
				distance[edges[minV][j].first] = dist;
			}
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		if (distance[i] != WEIGHT && i != s) std::cout << distance[i] << " ";
		else if (distance[i] == WEIGHT) std::cout << "-1 ";
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t, n, m;
	std::cin >> t;
	int v, u, w;
	int s;
	for (size_t i = 0; i < t; i++)
	{
		std::cin >> n >> m;
		std::vector<std::pair<int, int>>* edges = new std::vector<std::pair<int, int>>[n];
		for (size_t i = 0; i < m; i++)
		{
			std::cin >> v >> u >> w;
			edges[v - 1].push_back(std::pair<int, int>(u - 1, w));
			edges[u - 1].push_back(std::pair<int, int>(v - 1, w));
		}
		std::cin >> s;
		dijkstra(edges, n, s - 1);
		std::cout << "\n";
	}
	return 0;
}