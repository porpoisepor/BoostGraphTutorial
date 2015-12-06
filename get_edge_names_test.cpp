#include "get_edge_names.h"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "create_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"

void get_edge_names_test() noexcept
{
  //Unnamed K2 graph: should not compile, and it doesn't :-)
  {
    //get_edge_names(create_k2_graph());
  }
  //Named K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::vector<std::string> expected_names{"AB", "BC", "CA"};
    const std::vector<std::string> edge_names{get_edge_names(g)};
    assert(expected_names == edge_names);
  }
  std::cout << __func__ << ": OK" << '\n';
}