#include "framework_impl.h"

void _impl_alg_topological_sort(Graph& G, int v, std::vector<bool>& v_visited, int& curIdx, std::deque<int>& v_topo_order)
{
    if (v_visited[v])
        return;

    v_visited[v] = true;
    for (auto& el : G[v].adjVert)
    {
        if (v_visited[el])
            continue;

        _impl_alg_topological_sort(G, el, v_visited, curIdx, v_topo_order);
    }

    v_topo_order.emplace_front(v);
    --curIdx;
}
