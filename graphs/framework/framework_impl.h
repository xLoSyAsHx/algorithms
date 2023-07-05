#pragma once

#include <deque>
#include "Graph.h"

void _impl_alg_topological_sort_rec(Graph& G, int v, std::vector<bool>& v_visited, int& curIdx, std::deque<int>& v_topo_order);

void _impl_alg_dfs_iter(Graph& G, int v, std::vector<bool>& v_visited, std::deque<int>& v_topo_order);

