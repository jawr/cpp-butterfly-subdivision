#ifndef __UTIL_CLASSES_HPP
#define __UTIL_CLASSES_HPP

#include <iostream>

namespace utils
{

class Vertex
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    int valences; // controlled in the edge
public:
    Vertex(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z), valences(0) {}

    const GLfloat& X() const { return x; }
    const GLfloat& Y() const { return y; }
    const GLfloat& Z() const { return z; }

    // valence control, prefer prefix overload
    // needs boundary check?
    Vertex& operator++() 
    { 
      ++valences; 
      return *this;
    }
    Vertex& operator--() 
    { 
      --valences; 
      return *this;
    } 
};

class Edge
{
    Vertex* p1; // would want to use a shared_ptr here
    Vertex* p2;
public:
    Edge(Vertex* p1, Vertex* p2) : p1(p1), p2(p2) 
    {
        // control vertex's valences, have to use our initalized copies
        ++(*p1);
        ++(*p2);
    }
    ~Edge() 
    {
        // control vertex's valences
        --(*p1);
        --(*p2);
    }
    const Vertex& P1() const { return *p1; }
    const Vertex& P2() const { return *p2; }
};

class Face
{
    std::vector<Edge*> edges; // todo: change to set
public:
    Face() {}
    ~Face() {} // need to do real cleanup

    void AddEdge(Edge* edge) { edges.push_back(edge); }
    int Size() const { return edges.size(); }

    std::vector<Edge*>::const_iterator CBegin() const { return edges.begin(); }
    std::vector<Edge*>::const_iterator CEnd() const { return edges.end(); }
};

}

#endif
