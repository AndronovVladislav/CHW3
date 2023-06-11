#include "../Utils/CSVReader.h"
#include "../Utils/GraphConstructor.h"

// Форд-Беллман хочет список рёбер
void fordBellman(std::vector<Edge>& edges, int n, int m, int start_vertex) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> d(n, INF);
    d[start_vertex] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[edges[j].from] < INF) {
                d[edges[j].to] = std::min(d[edges[j].to], d[edges[j].from] + edges[j].distance);
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
    int m = atoi(parsed_data[0][1].c_str());
    int start_vertex = atoi(parsed_data[0][2].c_str());
    auto edges = GraphConstructor::constructEdgesList(parsed_data);

    fordBellman(edges, n, m, start_vertex);
    return 0;
}