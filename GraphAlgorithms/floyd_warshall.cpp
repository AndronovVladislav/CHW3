#include "../Utils/CSVReader.h"
#include "../Utils/GraphConstructor.h"

void fordWarshall(std::vector<std::vector<int64_t>>& distances) {
    auto start = std::chrono::high_resolution_clock::now();

    int n = distances.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distances[i][j] > distances[i][k] + distances[k][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
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

    auto graph = GraphConstructor::constructAdjacencyMatrix(parsed_data, n);

    fordWarshall(graph);
    return 0;
}