#include "create_nasty_directed_named_vertices_graph.h"

#include <boost/test/unit_test.hpp>

#include "add_named_vertex.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "save_named_vertices_graph_to_dot.h"
#include "load_directed_named_vertices_graph_from_dot.h"
#include "get_sorted_named_vertex_my_vertexes.h"

BOOST_AUTO_TEST_CASE(create_nasty_directed_named_vertices_graph_thorough)
{
  {
    auto g = create_nasty_directed_named_vertices_graph();
    const std::string filename{
      "create_nasty_directed_named_vertices_graph_test.dot"
    };
    save_named_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_named_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_vertex_names(g);
    const auto b = get_sorted_vertex_names(h);
    BOOST_CHECK(a == b);
  }
  
}
