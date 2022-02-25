#include "pixelArt.h"

int main()
{

    pixelArt p0(70,16);
    p0.readArts("art_0");
    

    pixelArt p1(70,16);
    p1.readArts("art_1");
    p1 = p1+1;


    pixelArt p2(70,16);
    p2.readArts("art_2");
    p2 = p2+2;


    p0=p0-9;
    p1=p1-9;
    p2=p2-9;
    p0 = p0+p1+p2+9;
    cout<<p0<<endl;


}
