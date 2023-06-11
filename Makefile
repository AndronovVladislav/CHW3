all: build testing

build:
	g++ GraphAlgorithms/dijkstra.cpp Utils/CSVReader.cpp Utils/GraphConstructor.cpp -o GraphAlgorithms/dijkstra
	g++ GraphAlgorithms/floyd_warshall.cpp Utils/CSVReader.cpp Utils/GraphConstructor.cpp -o GraphAlgorithms/floyd_warshall
	g++ GraphAlgorithms/ford_bellman.cpp Utils/CSVReader.cpp Utils/GraphConstructor.cpp -o GraphAlgorithms/ford_bellman

testing:
	./pypart/tester.py