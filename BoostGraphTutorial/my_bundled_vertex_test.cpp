#include "my_bundled_vertex.h"
//#include "my_bundled_vertex_demo.impl"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test.hpp>

#include <sstream>

my_bundled_vertex::my_bundled_vertex(
  const std::string& name,
  const std::string& description,
  const double x,
  const double y
) noexcept :
  m_name{name},
  m_description{description},
  m_x{x},
  m_y{y}
{

}

bool operator==(const my_bundled_vertex& lhs, const my_bundled_vertex& rhs) noexcept
{
  return
       lhs.m_description == rhs.m_description
    && lhs.m_name == rhs.m_name
    && lhs.m_x == rhs.m_x
    && lhs.m_y == rhs.m_y
  ;
}

bool operator!=(const my_bundled_vertex& lhs, const my_bundled_vertex& rhs) noexcept
{
  return !(lhs == rhs);
}