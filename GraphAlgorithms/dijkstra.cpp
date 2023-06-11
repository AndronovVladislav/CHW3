#include "../Utils/CSVReader.h"
#include "../Utils/GraphConstructor.h"

void dijkstra(std::vector<std::vector<std::pair<int, int>>>& adjacency_list, int n, int start_vertex, int end_vertex) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> distances(n, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> order;

    order.push({0, start_vertex});
    distances[start_vertex] = 0;

    while (!order.empty()) {
        auto [cur_dist, vert] = order.top();
        order.pop();

        if (cur_dist > distances[vert]) {
            continue;
        }

        for (const auto& [distance, neighbour] : adjacency_list[vert]) {
            if (distances[vert] + distance < distances[neighbour]) {
                distances[neighbour] = distance + distances[vert];
                order.push({distances[neighbour], neighbour});
            }
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    CSVReader data("graph.csv", ";");
    auto parsed_data = data.getData();

    int n = atoi(parsed_data[0][0].c_str());
    int start_vertex = atoi(parsed_data[0][2].c_str());
    int end_vertex = atoi(parsed_data[0][3].c_str());

    auto graph = GraphConstructor::constructAdjacencyLists(parsed_data, n);

    dijkstra(graph, n, start_vertex, end_vertex);
    return 0;
}