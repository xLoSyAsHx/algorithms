#pragma once

#include <deque>
#include "Graph.h"

void _impl_alg_topological_sort(Graph& G, int v, std::vector<bool>& v_visited, int& curIdx, std::deque<int>& v_topo_order);

