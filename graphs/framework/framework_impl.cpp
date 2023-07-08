#include "framework_impl.h"

void _impl_alg_topological_sort_rec(Graph& G, int v, std::vector<bool>& v_visited, int& curIdx, std::deque<int>& v_topo_order)
{
    if (v_visited[v])
        return;

    v_visited[v] = true;
    for (auto& el : G[v].adjVert)
    {
        if (v_visited[el])
            continue;

        _impl_alg_topological_sort_rec(G, el, v_visited, curIdx, v_topo_order);
    }

    v_topo_order.emplace_front(v);
    --curIdx;
}

void _impl_alg_dfs_iter(Graph& G, int v, std::vector<bool>& v_visited, std::deque<int>& v_topo_order)
{
    if (v_visited[v])
        return;

    std::deque<int> pq;

    pq.emplace_back(v);
    while (!pq.empty())
    {
        int v1 = pq.front();
        pq.pop_front();

        for (auto it = G[v1].adjVert.cbegin(); it != G[v1].adjVert.cend(); ++it)
        {
            int v2 = *it;
            if (v_visited[v2])
                continue;

            v_visited[v2] = true;
            pq.push_front(v2);
        }
    }
}

void _impl_alg_dfs_scc(Graph& G, int v, std::vector<bool>& v_visited, int curSCC, std::map<int, std::vector<int>>& vec_scc)
{
    if (v_visited[v])
        return;

    v_visited[v] = true;
    vec_scc[curSCC].emplace_back(v);
    for (auto& el : G[v].adjVert)
    {
        if (v_visited[el])
            continue;

        _impl_alg_dfs_scc(G, el, v_visited, curSCC, vec_scc);
    }
}
