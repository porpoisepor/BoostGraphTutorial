#include "create_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraph.h"
#include "create_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_custom_and_selectable_edges_and_vertices_k2_graph.h"
#include "create_custom_and_selectable_edges_and_vertices_k3_graph.h"
#include "create_custom_and_selectable_edges_and_vertices_path_graph.h"
#include "create_custom_and_selectable_edges_and_vertices_petersen_graph.h"
#include "get_my_custom_vertex.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(create_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraph_thorough)
{
  //K2
  {
    const auto g = create_custom_and_selectable_edges_and_vertices_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraph(
        *i,g
      );
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
      const auto v = get_my_custom_vertexes(h);
      std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
      const my_custom_vertex a("A","source",0.0,0.0);
      const my_custom_vertex b("B","target",3.14,3.14);
      BOOST_CHECK(vertexes.count(a) == 1);
      BOOST_CHECK(vertexes.count(b) == 1);
    }
  }
  //K3
  {
    const auto g = create_custom_and_selectable_edges_and_vertices_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraph(
        *i,g
      );
      BOOST_CHECK(boost::num_vertices(h) == 3);
      BOOST_CHECK(boost::num_edges(h) == 3);
      const auto v = get_my_custom_vertexes(h);
      std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
      const my_custom_vertex a("Karen","red",1.1,2.2);
      const my_custom_vertex b("Kristel","black",3.3,4.4);
      const my_custom_vertex c("Kathleen","blond",5.5,6.6);
      BOOST_CHECK(vertexes.count(a) == 1);
      BOOST_CHECK(vertexes.count(b) == 1);
      BOOST_CHECK(vertexes.count(c) == 1);
    }
  }
  //Path graph
  {
    const my_custom_vertex va("A","first",1.1,2.2);
    const my_custom_vertex vb("B","second",3.3,4.4);
    const my_custom_vertex vc("C","third",5.5,6.6);
    const my_custom_edge ea("1","first",1.1,2.2);
    const my_custom_edge eb("2","second",3.3,4.4);
    const auto g = create_custom_and_selectable_edges_and_vertices_path_graph(
      { ea, eb },
      { false, false },
      { va, vb, vc },
      { false, true, false }
    );
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {

      const auto h = create_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraph(
        *i,g
      );

      if (get_my_custom_vertex(*i, g) == va) {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
        BOOST_CHECK(vertexes.count(va) == 1);
        BOOST_CHECK(vertexes.count(vb) == 1);
        BOOST_CHECK(vertexes.count(vc) == 0);
      }
      if (get_my_custom_vertex(*i, g) == vb) {
        BOOST_CHECK(boost::num_vertices(h) == 3);
        BOOST_CHECK(boost::num_edges(h) == 2);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
        BOOST_CHECK(vertexes.count(va) == 1);
        BOOST_CHECK(vertexes.count(vb) == 1);
        BOOST_CHECK(vertexes.count(vc) == 1);
      }
      if (get_my_custom_vertex(*i, g) == vc) {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
        BOOST_CHECK(vertexes.count(va) == 0);
        BOOST_CHECK(vertexes.count(vb) == 1);
        BOOST_CHECK(vertexes.count(vc) == 1);
      }
    }
  }
}
