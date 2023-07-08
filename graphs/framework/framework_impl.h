#pragma once

#include <deque>
#include <map>
#include "Graph.h"

void _impl_alg_topological_sort_rec(Graph& G, int v, std::vector<bool>& v_visited, int& curIdx, std::deque<int>& v_topo_order);

void _impl_alg_dfs_iter(Graph& G, int v, std::vector<bool>& v_visited, std::deque<int>& v_topo_order);

void _impl_alg_dfs_scc(Graph& G, int v, std::vector<bool>& v_visited, int curSCC, std::map<int, std::vector<int>>& vec_scc);

