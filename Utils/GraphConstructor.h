#ifndef IHW3_GRAPHCONSTRUCTOR_H
#define IHW3_GRAPHCONSTRUCTOR_H

#include "common.h"

class GraphConstructor {
public:
    static std::vector<std::vector<std::pair<int, int>>>
            constructAdjacencyLists(std::vector<std::vector<std::string>>& raw_data, int n);

    static std::vector<std::vector<int64_t>>
        constructAdjacencyMatrix(std::vector<std::vector<std::string>>& raw_data, int n);

    static std::vector<Edge> constructEdgesList(std::vector<std::vector<std::string>>& raw_data);
};


#endif //IHW3_GRAPHCONSTRUCTOR_H
