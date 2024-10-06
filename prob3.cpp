#include<stdio.h>
struct vectf
{
    float x=0;
    float y=0;
    void print()
    {
        printf("%f %f\n",x,y);

    }
    vectf add(vectf b)
    {
        vectf result;
        result.x=x+b.x;
        result.y=y+b.y;
        return result;
    
    }

};
int main()
{
    vectf v1,v2;
    v1.print();

    v1.x=5;
    v1.y=9;
    v1.print();
    v2.x=4;
    v2.y=8;
    v2.print();
    vectf v3=v1.add(v2);
    v3.print();
    return 0;
}