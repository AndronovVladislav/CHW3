#!/usr/bin/env python3
from subprocess import run
from copy import deepcopy
from utils import *

ALGORITHMS_PREFIX = 'GraphAlgorithms/'
PRETTY_NAMES = {'dijkstra': 'Dijkstra',
                'floyd_warshall': 'Floyd-Warshall',
                'ford_bellman': 'Ford-Bellman'}
GRAPH_TYPES = {generate_complete_graph: 'Complete Graph',
               generate_connected_graph: 'Medium-density Graph',
               generate_spanning_tree: 'Spanning Tree'}

VERTICES_AMOUNT = range(10, 1011, 50)
TESTS_ITERATIONS = 15
ALGORITHMS_RESULTS = [[deepcopy([0] * (len(GRAPH_TYPES) + len(PRETTY_NAMES)))
                       for _ in range(len(VERTICES_AMOUNT))]
                      for _ in range(len(PRETTY_NAMES))]
GRAPHS_RESULTS = [[deepcopy([0] * (len(PRETTY_NAMES) + 1))
                   for _ in range(len(VERTICES_AMOUNT))]
                  for _ in range(len(GRAPH_TYPES))]

if __name__ == '__main__':
    for j, graph_size in enumerate(VERTICES_AMOUNT):
        for k, generate_specific_graph in enumerate(GRAPH_TYPES.keys()):
            graph = generate_specific_graph(graph_size)
            graph_to_csv('graph.csv', graph)

            edges_in_graph = \
                str(sum(
                        sum(1 if distance != 0 else 0 for distance in graph[i]) for i in range(len(graph))
                    ) // 2
                )
            GRAPHS_RESULTS[k][j][len(PRETTY_NAMES)] = edges_in_graph
            # print(edges_amount)
            # break

            for i, algorithm in enumerate(PRETTY_NAMES.keys()):
                print(len(graph), generate_specific_graph, algorithm)

                time = str(sum([int(run([ALGORITHMS_PREFIX + algorithm], capture_output=True, text=True).stdout)
                                for _ in range(TESTS_ITERATIONS)]) / TESTS_ITERATIONS)
                # noinspection PyTypeChecker
                ALGORITHMS_RESULTS[i][j][k] = time
                # noinspection PyTypeChecker
                GRAPHS_RESULTS[k][j][i] = time
                # noinspection PyTypeChecker
                ALGORITHMS_RESULTS[i][j][len(PRETTY_NAMES) + k] = edges_in_graph

                # print(RESULTS[i][j])

    for algorithm, result in zip(PRETTY_NAMES.keys(), ALGORITHMS_RESULTS):
        with open(f'Measurements/{algorithm}.csv', 'w') as f:
            f.write(';'.join(list(GRAPH_TYPES.values()) + [x + ' Edges' for x in GRAPH_TYPES.values()]) + '\n')
            for row in result:
                print(row)
                f.write(';'.join(row) + '\n')

    for graph_type, result in zip(GRAPH_TYPES.values(), GRAPHS_RESULTS):
        filename = '_'.join(graph_type.lower().split(' '))
        with open(f'Measurements/{filename}.csv', 'w') as f:
            f.write(';'.join(list(PRETTY_NAMES.keys()) + ['Edges']) + '\n')
            for row in result:
                f.write(';'.join(row) + '\n')
