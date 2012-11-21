#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "cube.hpp"

namespace shapes
{

Cube::Cube(GLfloat size) : size(size)
{
    GLfloat xCursor = 0.0f; 
    GLfloat yCursor = 0.0f; 
    GLfloat zCursor = 0.0f; 
    // offset cursor?

    // someway to make this cleaner...
    using namespace utils;
    
    Vertex* v1 = new Vertex(xCursor, yCursor, zCursor); 
    Vertex* v2 = new Vertex(xCursor+size, yCursor, zCursor);
    Vertex* v3 = new Vertex(xCursor+size, yCursor+size, zCursor);
    Vertex* v4 = new Vertex(xCursor, yCursor+size, zCursor);
    Vertex* v5 = new Vertex(xCursor, yCursor, zCursor+size);
    Vertex* v6 = new Vertex(xCursor+size, yCursor, zCursor+size);
    Vertex* v7 = new Vertex(xCursor+size, yCursor+size, zCursor+size);
    Vertex* v8 = new Vertex(xCursor, yCursor+size, zCursor+size);

    // front face
    Vertex* v9 = new Vertex(xCursor+(size/2.0f), yCursor+(size/2.0f), zCursor);
    // top face
    Vertex* v10 = new Vertex(xCursor+(size/2.0f), yCursor, zCursor+(size/2.0f));
    // back face
    Vertex* v11 = new Vertex(xCursor+(size/2.0f), yCursor+(size/2.0f), zCursor+size);
    // left side face
    Vertex* v12 = new Vertex(xCursor, yCursor+(size/2.0f), zCursor+(size/2.0f));
    // right side face
    Vertex* v13 = new Vertex(xCursor+size, yCursor+(size/2.0f), zCursor+(size/2.0f));
    // bottom face
    Vertex* v14 = new Vertex(xCursor+(size/2.0f), yCursor+size, zCursor+(size/2.0f));


    // front face
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v4));
    f1.AddEdge(new Edge(v4, v1));

    f1.AddEdge(new Edge(v1, v9));
    f1.AddEdge(new Edge(v2, v9));
    f1.AddEdge(new Edge(v3, v9));
    f1.AddEdge(new Edge(v4, v9));

    faces.push_back(f1);

    // top face
    Face f2;
    f2.AddEdge(new Edge(v1, v5));
    f2.AddEdge(new Edge(v5, v6));
    f2.AddEdge(new Edge(v6, v2));
    f2.AddEdge(new Edge(v2, v1));


    f2.AddEdge(new Edge(v1, v10));
    f2.AddEdge(new Edge(v5, v10));
    f2.AddEdge(new Edge(v6, v10));
    f2.AddEdge(new Edge(v2, v10));

    faces.push_back(f2);

    // left face
    Face f3;
    f3.AddEdge(new Edge(v1, v5));
    f3.AddEdge(new Edge(v5, v8));
    f3.AddEdge(new Edge(v8, v4));
    f3.AddEdge(new Edge(v4, v1));

    f3.AddEdge(new Edge(v1, v12));
    f3.AddEdge(new Edge(v5, v12));
    f3.AddEdge(new Edge(v8, v12));
    f3.AddEdge(new Edge(v4, v12));

    faces.push_back(f3);

    // bottom face
    Face f4;
    f4.AddEdge(new Edge(v4, v8));
    f4.AddEdge(new Edge(v8, v7));
    f4.AddEdge(new Edge(v7, v3));
    f4.AddEdge(new Edge(v3, v4));

    f4.AddEdge(new Edge(v4, v14));
    f4.AddEdge(new Edge(v8, v14));
    f4.AddEdge(new Edge(v7, v14));
    f4.AddEdge(new Edge(v3, v14));

    faces.push_back(f4);

    // right face
    Face f5;
    f5.AddEdge(new Edge(v3, v2));
    f5.AddEdge(new Edge(v2, v6));
    f5.AddEdge(new Edge(v6, v7));
    f5.AddEdge(new Edge(v7, v3));

    f5.AddEdge(new Edge(v3, v13));
    f5.AddEdge(new Edge(v2, v13));
    f5.AddEdge(new Edge(v6, v13));
    f5.AddEdge(new Edge(v7, v13));

    faces.push_back(f5);

    Face f6;
    f6.AddEdge(new Edge(v7, v6));
    f6.AddEdge(new Edge(v6, v5));
    f6.AddEdge(new Edge(v5, v8));
    f6.AddEdge(new Edge(v8, v7));

    f6.AddEdge(new Edge(v7, v11));
    f6.AddEdge(new Edge(v6, v11));
    f6.AddEdge(new Edge(v5, v11));
    f6.AddEdge(new Edge(v8, v11));

    faces.push_back(f6);

}

void Cube::Draw()
{
    using namespace utils;
    std::vector<Face>::const_iterator it;
    for (it = faces.begin(); it != faces.end(); ++it)
    {
        std::vector<Edge*>::const_iterator jt;
        for (jt = (*it).CBegin(); jt != (*it).CEnd(); ++jt)
        {
            const Vertex& p1 = (*jt)->P1();
            const Vertex& p2 = (*jt)->P2();

            glBegin(GL_LINES);

            glVertex3f(p1.X(), p1.Y(), p1.Z());
            glVertex3f(p2.X(), p2.Y(), p2.Z());

            glEnd();
        }
    }
}

}

