// framework.cpp : Defines the functions for the static library.
//

#include "framework.h"
#include "framework_impl.h"


std::deque<int> alg_topological_sort(Graph& G)
{
    std::deque<int> v_topo_order;
    std::vector<bool> v_visited(G.numV(), false);
    int curIdx = (int)G.numV();

    for (auto it = G.begin(); it != G.end(); ++it)
    {
        _impl_alg_topological_sort(G, it->v, v_visited, curIdx, v_topo_order);
    }

    return v_topo_order;
}

std::vector<std::vector<int>> alg_kosaraju(Graph& G)
{
    std::vector<std::vector<int>> vec_scc;

    Graph revG = G.reverseEdges();

    return vec_scc;
}
