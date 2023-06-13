#!/usr/bin/env python3

import random
from copy import deepcopy


def generate_complete_graph(n: int) -> list[list[int]]:
    ans = [deepcopy([0] * n) for _ in range(n)]
    for i in range(n):
        for j in range(i, n):
            ans[j][i] = ans[i][j] = random.randint(1, 10)
    return ans


def generate_connected_graph(n: int) -> list[list[int]]:
    num_edges = n * (n - 1) * random.uniform(0.4, 0.5) // 2

    graph = generate_spanning_tree(n)

    remaining_edges = num_edges - (n - 1)
    while remaining_edges > 0:
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        if u != v and graph[u][v] == 0:
            distance = random.randint(1, 10)
            graph[u][v] = distance
            graph[v][u] = distance
            remaining_edges -= 1

    return graph


def generate_spanning_tree(n: int) -> list[list[int]]:
    graph = [[0] * n for _ in range(n)]

    visited = [False] * n
    visited[0] = True
    remaining_vertices = set(range(1, n))

    for _ in range(n - 1):
        u = random.choice(list(remaining_vertices))
        v = random.randint(0, u - 1)

        distance = random.randint(1, 10)
        graph[u][v] = distance
        graph[v][u] = distance

        visited[u] = True
        remaining_vertices.remove(u)

    return graph


def graph_to_csv(filename: str, graph: list[list[int]]) -> None:
    n = len(graph)
    m = sum(sum(1 if distance != 0 else 0 for distance in graph[i]) for i in range(len(graph))) // 2
    start = random.randint(0, n)
    end = random.randint(0, n)

    with open(filename, 'w') as f:
        f.write(f'{n};{m};{start};{end}\n')
        for row in graph:
            f.write(';'.join(map(str, row)) + '\n')
