#include "GraphConstructor.h"

std::vector<std::vector<std::pair<int, int>>>
GraphConstructor::constructAdjacencyLists(std::vector<std::vector<std::string>>& raw_data, int n) {
    std::vector<std::vector<std::pair<int, int>>> ans(n, std::vector<std::pair<int, int>>());

    for (int i = 1; i < raw_data.size(); ++i) {
        for (int j = 0; j < raw_data[i].size(); ++j) {
            if (raw_data[i][j] != "0") {
                ans[i - 1].push_back({atoi(raw_data[i][j].c_str()), j});
            }
        }
    }

    return ans;
}

std::vector<std::vector<int64_t>>
GraphConstructor::constructAdjacencyMatrix(std::vector<std::vector<std::string>>& raw_data, int n) {
    std::vector<std::vector<int64_t>> ans(n, std::vector<int64_t>(n));

    for (int i = 1; i < raw_data.size(); ++i) {
        for (int j = 0; j < raw_data[i].size(); ++j) {
            ans[i - 1][j] = raw_data[i][j] != "0" ? atoi(raw_data[i][j].c_str()) : INF;
        }
    }

    return ans;
}

std::vector<Edge> GraphConstructor::constructEdgesList(std::vector<std::vector<std::string>>& raw_data) {
    std::vector<Edge> ans;

    for (int i = 1; i < raw_data.size(); ++i) {
        for (int j = 0; j < raw_data[i].size(); ++j) {
            if (raw_data[i][j] != "0") {
                ans.push_back({i - 1, j, atoi(raw_data[i][j].c_str())});
            }
        }
    }

    return ans;
}