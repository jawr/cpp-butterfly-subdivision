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
    
    utils::Vertex v1(xCursor, yCursor, zCursor); 
    utils::Vertex v2(xCursor+size, yCursor, zCursor);
    utils::Vertex v3(xCursor+size, yCursor+size, zCursor);
    utils::Vertex v4(xCursor, yCursor+size, zCursor);
    utils::Vertex v5(xCursor, yCursor, zCursor+size);
    utils::Vertex v6(xCursor+size, yCursor, zCursor+size);
    utils::Vertex v7(xCursor+size, yCursor+size, zCursor+size);
    utils::Vertex v8(xCursor, yCursor+size, zCursor+size);

    // front face
    std::cout << "v9: " << xCursor+(size/2.0f) << " " << yCursor-(size/2.0f) << std::endl;
    utils::Vertex v9(xCursor+(size/2.0f), yCursor+(size/2.0f), zCursor);
    // top face
    utils::Vertex v10(xCursor+(size/2.0f), yCursor, zCursor+(size/2.0f));
    // back face
    utils::Vertex v11(xCursor+(size/2.0f), yCursor+(size/2.0f), zCursor+size);
    // left side face
    utils::Vertex v12(xCursor, yCursor+(size/2.0f), zCursor+(size/2.0f));
    // right side face
    utils::Vertex v13(xCursor+size, yCursor+(size/2.0f), zCursor+(size/2.0f));
    // bottom face
    utils::Vertex v14(xCursor+(size/2.0f), yCursor+size, zCursor+(size/2.0f));


    // front face
    utils::Face f1;
    f1.AddEdge(utils::Edge(v1, v2));
    f1.AddEdge(utils::Edge(v2, v3));
    f1.AddEdge(utils::Edge(v3, v4));
    f1.AddEdge(utils::Edge(v4, v1));

    f1.AddEdge(utils::Edge(v1, v9));
    f1.AddEdge(utils::Edge(v2, v9));
    f1.AddEdge(utils::Edge(v3, v9));
    f1.AddEdge(utils::Edge(v4, v9));

    faces.push_back(f1);

    // top face
    utils::Face f2;
    f2.AddEdge(utils::Edge(v1, v5));
    f2.AddEdge(utils::Edge(v5, v6));
    f2.AddEdge(utils::Edge(v6, v2));
    f2.AddEdge(utils::Edge(v2, v1));


    f2.AddEdge(utils::Edge(v1, v10));
    f2.AddEdge(utils::Edge(v5, v10));
    f2.AddEdge(utils::Edge(v6, v10));
    f2.AddEdge(utils::Edge(v2, v10));

    faces.push_back(f2);

    // left face
    utils::Face f3;
    f3.AddEdge(utils::Edge(v1, v5));
    f3.AddEdge(utils::Edge(v5, v8));
    f3.AddEdge(utils::Edge(v8, v4));
    f3.AddEdge(utils::Edge(v4, v1));

    f3.AddEdge(utils::Edge(v1, v12));
    f3.AddEdge(utils::Edge(v5, v12));
    f3.AddEdge(utils::Edge(v8, v12));
    f3.AddEdge(utils::Edge(v4, v12));

    faces.push_back(f3);

    // bottom face
    utils::Face f4;
    f4.AddEdge(utils::Edge(v4, v8));
    f4.AddEdge(utils::Edge(v8, v7));
    f4.AddEdge(utils::Edge(v7, v3));
    f4.AddEdge(utils::Edge(v3, v4));

    f4.AddEdge(utils::Edge(v4, v14));
    f4.AddEdge(utils::Edge(v8, v14));
    f4.AddEdge(utils::Edge(v7, v14));
    f4.AddEdge(utils::Edge(v3, v14));

    faces.push_back(f4);

    // right face
    utils::Face f5;
    f5.AddEdge(utils::Edge(v3, v2));
    f5.AddEdge(utils::Edge(v2, v6));
    f5.AddEdge(utils::Edge(v6, v7));
    f5.AddEdge(utils::Edge(v7, v3));

    f5.AddEdge(utils::Edge(v3, v13));
    f5.AddEdge(utils::Edge(v2, v13));
    f5.AddEdge(utils::Edge(v6, v13));
    f5.AddEdge(utils::Edge(v7, v13));

    faces.push_back(f5);

    utils::Face f6;
    f6.AddEdge(utils::Edge(v7, v6));
    f6.AddEdge(utils::Edge(v6, v5));
    f6.AddEdge(utils::Edge(v5, v8));
    f6.AddEdge(utils::Edge(v8, v7));

    f6.AddEdge(utils::Edge(v7, v11));
    f6.AddEdge(utils::Edge(v6, v11));
    f6.AddEdge(utils::Edge(v5, v11));
    f6.AddEdge(utils::Edge(v8, v11));

    faces.push_back(f6);

}

void Cube::Draw()
{
    std::vector<utils::Face>::const_iterator it;
    for (it = faces.begin(); it != faces.end(); ++it)
    {
        std::vector<utils::Edge>::const_iterator jt;
        for (jt = (*it).CBegin(); jt != (*it).CEnd(); ++jt)
        {
            const utils::Vertex& p1 = (*jt).P1();
            const utils::Vertex& p2 = (*jt).P2();

            glBegin(GL_LINES);

            glVertex3f(p1.X(), p1.Y(), p1.Z());
            glVertex3f(p2.X(), p2.Y(), p2.Z());

            glEnd();
        }
    }
}

}

