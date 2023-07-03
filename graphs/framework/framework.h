#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <deque>
#include "Graph.h"

std::deque<int> alg_topological_sort(Graph& G);

std::vector<std::vector<int>> alg_kosaraju(Graph& G);