#include "Graph.h"

#include <algorithm>

GErr Graph::readInputFromBook(std::vector<GraphAdjVect>& adjList, bool bOriented)
{
    if (!m_G.empty())
        return G_OBJECT_ALREADY_INITIALIZED;

    if (bOriented == false)
        return G_NOT_IMPLEMENTED;

    m_bOriented = bOriented;
    m_G.resize(adjList.size());

    for (auto& el : adjList)
    {
        int v = el.v - 1;
        if (v >= m_G.size())
        {
            Log::AddErr("Invalid vertex idx: '%d'", v);
            return G_INVALID_INPUT;
        }

        m_G[v].v = v;
        m_G[v].adjVert.resize(el.adjVert.size());

        for (int i = 0; i < el.adjVert.size(); ++i)
        {
            if (el.adjVert[i] == 0 || el.adjVert[i] > m_G.size())
                return G_INVALID_INPUT;

            m_G[v].adjVert[i] = el.adjVert[i] - 1;
        }
    }

    return G_OK;
}

Graph Graph::reverseEdges()
{
    Graph GRev;

    GRev.m_bOriented = m_bOriented;
    GRev.m_G.resize(m_G.size());

    int v = 0;
    for (const auto& adjacencyList : m_G)
    {
        for (const auto& s : adjacencyList.adjVert)
        {
            GRev.m_G[s].adjVert.emplace_back(v);
        }
        ++v;
    }

    for (auto v = 0; v < m_G.size(); ++v)
        GRev.m_G[v].v = v;

    return GRev;
}

void print_graph(const Graph& g)
{
    for (const auto it : g.m_G)
    {
        std::cout << std::endl << it.v + 1 << " -> ";
        for (const auto w : it.adjVert)
            std::cout << w + 1 << ' ';
    }
    std::cout << std::endl;
}
