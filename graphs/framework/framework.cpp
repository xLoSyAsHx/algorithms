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
        _impl_alg_topological_sort_rec(G, it->v, v_visited, curIdx, v_topo_order);
    }

    return v_topo_order;
}

std::map<int, std::vector<int>> alg_kosaraju(Graph& G)
{
    std::map<int, std::vector<int>> vec_scc;
    std::vector<bool>             v_visited(G.numV(), false);
    Graph revG = G.reverseEdges();

    auto revg_topo_sort = alg_topological_sort(revG);

    int curSCC = 0;
    for (auto it = revg_topo_sort.cbegin(); it != revg_topo_sort.cend(); ++it)
    {
        int v2 = G[*it].v;
        if (v_visited[v2])
            continue;

        curSCC += 1;
        _impl_alg_dfs_scc(G, v2, v_visited, curSCC, vec_scc);
    }

    return vec_scc;
}
