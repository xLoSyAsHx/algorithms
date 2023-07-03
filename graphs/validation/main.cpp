
#include "framework.h"

#define CHECK_STS(expr) { GErr retErr = expr; if (retErr != G_OK) return -1; }
#define CHECK_EQU(expr, line) { bool res = expr; if (!res) { std::cout << "\nError: mismatch on line " << line << "\n"; return -1; } }

bool g_print_res = true;

int main()
{
    GraphAdjVect gAdjList{
        1, {1, 2, 3}
    };


    std::vector<GraphAdjVect> input0{
        GraphAdjVect{ 1,  {2, 3}},
        GraphAdjVect{ 2,  {4}},
        GraphAdjVect{ 3,  {4}},
        GraphAdjVect{ 4,  {}},
    };

    std::vector<GraphAdjVect> input1 {
        GraphAdjVect{ 1,  {3}},
        GraphAdjVect{ 2,  {4, 10}},
        GraphAdjVect{ 3,  {5, 11}},
        GraphAdjVect{ 4,  {7}},
        GraphAdjVect{ 5,  {1, 7, 9}},
        GraphAdjVect{ 6,  {10}},
        GraphAdjVect{ 7,  {9}},
        GraphAdjVect{ 8,  {6}},
        GraphAdjVect{ 9,  {2, 4, 8}},
        GraphAdjVect{ 10, {8}},
        GraphAdjVect{ 11, {6, 8}},
    };

    Graph G;

    //
    // Topological sort
    //

    // Input0
    G.clear();
    CHECK_STS(G.readInputFromBook(input0, true));

    std::vector<int> golden_topo_sort_input0 = { 1, 3, 2, 4 };
    auto v_topo_sort0 = alg_topological_sort(G);
    if (g_print_res)
    {
        Log::AddMsg("Print topological sort0:");
        for (auto el : v_topo_sort0)
            std::cout << el + 1 << ' ';
        std::cout << '\n' << std::endl;
    }

    CHECK_EQU(golden_topo_sort_input0.size() == v_topo_sort0.size(), __LINE__);
    for (int i = 0; i < v_topo_sort0.size(); ++i)
        CHECK_EQU(golden_topo_sort_input0[i] == v_topo_sort0[i]+1, __LINE__);

    // Input1
    G.clear();
    CHECK_STS(G.readInputFromBook(input1, true));
    std::vector<int> golden_topo_sort_input1 = { 0 }; // Graph is not an acyclic graph - therefore topological sort is not possible
    auto v_topo_sort1 = alg_topological_sort(G);
    if (g_print_res)
    {
        Log::AddMsg("Print topological sort1:");
        for (auto el : v_topo_sort1)
            std::cout << el + 1 << ' ';
        std::cout << '\n' << std::endl;
    }

    CHECK_EQU(golden_topo_sort_input1.size() == v_topo_sort1.size(), __LINE__);
    for (int i = 0; i < v_topo_sort1.size(); ++i)
        CHECK_EQU(golden_topo_sort_input1[i] == v_topo_sort1[i]+1, __LINE__);

    Log::AddMsg("All tests are passed!");
}