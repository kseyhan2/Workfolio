#include <iostream>
#include "canvas.cpp"      
#include "ekfonksiyonlar.cpp"


int main(int argc, char** argv)
{
    canvas graphic("ELE142 - Üç Cisim Projesi", 1, 1);
    graphic.startDoc();
    graphic.drawFrame();
    Universe evren;
    create(&evren, &graphic);
    const int totalstep = 60000;
    int n;

    for(int t = 0; t < totalstep; t++)
    {
    	
        purevirtual** arr = evren.getObjects(); 
		n = evren.getSize();

        for(int i = 0; i < n; i++)
        {
            vector2d pos = arr[i]->getkonum();

            switch(i)
            {
                case 0:
                    graphic.drawPoint(pos.getx(), pos.gety(), "red");
                    break;
                case 1:
                    graphic.drawPoint(pos.getx(), pos.gety(), "green");
                    break;
                case 2:
                    graphic.drawPoint(pos.getx(), pos.gety(), "blue");
                    break;
            }
        }

        evren.step();

    }

    graphic.finishDoc();

    return 0;
}

