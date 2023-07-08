#pragma once

#include <vector>
#include <stdexcept>
#include "Log.h"

#include "common.h"

struct GraphAdjVect {
    int v;
    std::vector<int> adjVert;
};


class Graph
{
    using AdjacencyListType = GraphAdjVect;
public:

    friend void print_graph(const Graph& g);

    class GraphIter {
    public:

        using iterator_category = std::random_access_iterator_tag;
        using value_type = AdjacencyListType;
        using difference_type = std::ptrdiff_t;
        using pointer = AdjacencyListType*;
        using reference = AdjacencyListType&;

        GraphIter()
        : m_ptr(nullptr)
        {}

        GraphIter(pointer ptr)
        : m_ptr(ptr)
        {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        friend bool operator== (const GraphIter& a, const GraphIter& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const GraphIter& a, const GraphIter& b) { return a.m_ptr != b.m_ptr; };

        // Prefix increment
        GraphIter& operator++() { m_ptr++; return *this; }

        // Postfix increment
        GraphIter operator++(int) { GraphIter tmp = *this; ++(*this); return tmp; }

    private:
        pointer m_ptr = nullptr;
    };


    GraphIter begin() { return m_G.empty() ? GraphIter() : GraphIter(&m_G[0]); }
    GraphIter end()   { return m_G.empty() ? GraphIter() : GraphIter(&m_G[m_G.size() - 1] + 1); }

    inline AdjacencyListType& at(int idx) { if (idx < m_G.size()) return m_G[idx]; throw std::invalid_argument("Error: invalid Graph idx"); }
    inline AdjacencyListType& operator[](int idx) noexcept { return m_G[idx]; }

    Graph()
    : m_bOriented(false)
    {}

    size_t numV() { return m_G.size(); }

    GErr readInputFromBook(std::vector<GraphAdjVect>& adjList, bool bOriented);

    // Use base graph G=(V, E) to create reverse graph
    // in which every (v, s) from E transform to (s, v)
    Graph reverseEdges();

    void clear() { m_G.clear(); }

private:
    bool m_bOriented = false;
    std::vector<AdjacencyListType> m_G;
};

void print_graph(const Graph& g);
