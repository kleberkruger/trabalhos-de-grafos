#!/usr/bin/env bash

./main dijkstra 0 datasets/in_cormen1.txt datasets/out_cormen1_dijkstra0.txt
./main dijkstra 1 datasets/in_cormen1.txt datasets/out_cormen1_dijkstra1.txt
./main dijkstra 2 datasets/in_cormen1.txt datasets/out_cormen1_dijkstra2.txt
./main bellman-ford 0 datasets/in_cormen1.txt datasets/out_cormen1_bellmanford.txt
./main floyd-warshall 0 datasets/in_cormen1.txt datasets/out_cormen1_floyd.txt
./main johnson 0 datasets/in_cormen1.txt datasets/out_cormen1_johnson0.txt
./main johnson 1 datasets/in_cormen1.txt datasets/out_cormen1_johnson1.txt
./main johnson 2 datasets/in_cormen1.txt datasets/out_cormen1_johnson2.txt

./main dijkstra 0 datasets/in_cormen2.txt datasets/out_cormen2_dijkstra0.txt
./main dijkstra 1 datasets/in_cormen2.txt datasets/out_cormen2_dijkstra1.txt
./main dijkstra 2 datasets/in_cormen2.txt datasets/out_cormen2_dijkstra2.txt
./main bellman-ford 0 datasets/in_cormen2.txt datasets/out_cormen2_bellmanford.txt
./main floyd-warshall 0 datasets/in_cormen2.txt datasets/out_cormen2_floyd.txt
./main johnson 0 datasets/in_cormen2.txt datasets/out_cormen2_johnson0.txt
./main johnson 1 datasets/in_cormen2.txt datasets/out_cormen2_johnson1.txt
./main johnson 2 datasets/in_cormen2.txt datasets/out_cormen2_johnson2.txt

./main dijkstra 0 datasets/in_kruger.txt datasets/out_kruger_dijkstra0.txt
./main dijkstra 1 datasets/in_kruger.txt datasets/out_kruger_dijkstra1.txt
./main dijkstra 2 datasets/in_kruger.txt datasets/out_kruger_dijkstra2.txt
./main bellman-ford 0 datasets/in_kruger.txt datasets/out_kruger_bellmanford.txt
./main floyd-warshall 0 datasets/in_kruger.txt datasets/out_kruger_floyd.txt
./main johnson 0 datasets/in_kruger.txt datasets/out_kruger_johnson0.txt
./main johnson 1 datasets/in_kruger.txt datasets/out_kruger_johnson1.txt
./main johnson 2 datasets/in_kruger.txt datasets/out_kruger_johnson2.txt

./main dijkstra 0 datasets/in_lu980.txt datasets/out_lu980_dijkstra0.txt
./main dijkstra 1 datasets/in_lu980.txt datasets/out_lu980_dijkstra1.txt
./main dijkstra 2 datasets/in_lu980.txt datasets/out_lu980_dijkstra2.txt
./main bellman-ford 0 datasets/in_lu980.txt datasets/out_lu980_bellmanford.txt
./main floyd-warshall 0 datasets/in_lu980.txt datasets/out_lu980_floyd.txt
./main johnson 0 datasets/in_lu980.txt datasets/out_lu980_johnson0.txt
./main johnson 1 datasets/in_lu980.txt datasets/out_lu980_johnson1.txt
./main johnson 2 datasets/in_lu980.txt datasets/out_lu980_johnson2.txt

./main dijkstra 0 datasets/in_ja9847.txt datasets/out_ja9847_dijkstra0.txt
./main dijkstra 1 datasets/in_ja9847.txt datasets/out_ja9847_dijkstra1.txt
./main dijkstra 2 datasets/in_ja9847.txt datasets/out_ja9847_dijkstra2.txt
./main bellman-ford 0 datasets/in_ja9847.txt datasets/out_ja9847_bellmanford.txt
./main floyd-warshall 0 datasets/in_ja9847.txt datasets/out_ja9847_floyd.txt
./main johnson 0 datasets/in_ja9847.txt datasets/out_ja9847_johnson0.txt
./main johnson 1 datasets/in_ja9847.txt datasets/out_ja9847_johnson1.txt
./main johnson 2 datasets/in_ja9847.txt datasets/out_ja9847_johnson2.txt
