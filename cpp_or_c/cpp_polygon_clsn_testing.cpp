class vertex2D
{
public:
    float x,y;
    vertex2D() {x=0;y=0;}
    vertex2D(float a, float b) {x=a; y=b;}
};
 
class polygon
{
private:
    std::vector<vertex2D> vertices;
public:
    bool collision(polygon* poly, float x, float y);
};
 
bool polygon::collision(polygon* poly, float x, float y)
{
    bool status=false; //Collision status
    for (int i=0; i<vertices.size(); i++) // All edges of this polygon
    {
        int j=i+1;
        if (j==vertices.size()) j=0;
        float M=vertices[i].y-vertices[j].y, // General Form of Equation
              N=vertices[j].x-vertices[i].x, //  Mx+Ny+Q=0
              Q=0-M*vertices[j].x-N*vertices[j].y; 
        for (int k=0; k<poly->vertices.size(); k++) //All edges of tested polygon
        {
            int l=k+1;
            if (l==poly->vertices.size()) l=0;
            float A=poly->vertices[k].y-poly->vertices[l].y, // General Form of Equation
                  B=poly->vertices[l].x-poly->vertices[k].x, //  Ax+By+C=0
                  C=0-A*(poly->vertices[l].x+x)-B*(poly->vertices[l].y+y);
            if (A*N-B*M==0 && B*Q-C*N==0) //Both edges on the same line
            {
                if ((between(poly->vertices[k].x+x,vertices[i].x,vertices[j].x) && between(poly->vertices[k].y+y,vertices[i].y,vertices[j].y)) || (between(poly->vertices[l].x+x,vertices[i].x,vertices[j].x) && between(poly->vertices[l].y+y,vertices[i].y,vertices[j].y))) //Test interval
                {
                    status=true;
                }
            }
            else if (A*N-B*M!=0) //If intersection exists
            {
                float X1=(B*Q-C*N)/(A*N-B*M); //X-Coordinate of Intersection
                float Y1=(A*Q-M*C)/(M*B-A*N); //Y-Coordinate of Intersection
                if (between(X1,poly->vertices[k].x+x,poly->vertices[l].x+x) && between(X1,vertices[i].x,vertices[j].x) && between(Y1,poly->vertices[k].y+y,poly->vertices[l].y+y) && between(Y1,vertices[i].y,vertices[j].y))
                {/*
                    glColor3f(0,0,0);
                    glBegin(GL_QUADS);
                    glVertex3f(X1-0.1,Y1+0.1,0.001);
                    glVertex3f(X1+0.1,Y1+0.1,0.001);
                    glVertex3f(X1+0.1,Y1-0.1,0.001);
                    glVertex3f(X1-0.1,Y1-0.1,0.001);
                    glEnd(); */
                    status=true;
                }
            }
        }
    }
    return status;
}
