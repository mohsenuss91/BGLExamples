#include <iostream>
#include <boost/graph/adjacency_list.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;

int main(int,char*[])
{
  // Create a graph object
  Graph g;
  boost::graph_traits<Graph>::vertex_descriptor v0 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v1 = add_vertex(g);

  // Check if an edge between v0 and v1 exists. It should not at this point.
  std::cout << "Edge exists?" << edge(v0, v1, g).second << std::endl; // false

  // Add an edge between v0 and v1.
  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> e0 = add_edge(v0, v1, g);

  // Check again if an edge between v0 and v1 exists. It should now.
  std::cout << "Edge exists?" << edge(v0, v1, g).second << std::endl; // true

  // A demonstration of the full return type of edge(). At this point, retrievedEdge.first
  // should be exactly equal to e0
  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> retrievedEdge = edge(v0, v1, g);

  return 0;
}
