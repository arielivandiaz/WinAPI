/**
* Get Pixel Color of Screen
* @Version 1.0
* @author Ariel Ivan Diaz
* @URL www.arielivandiaz.net
* \note Este programa immprime el color RGB de el pixel en donde esta el mouse
*/

#include <stdio.h>
#include <windows.h>

//Posiblemente se necesite incluir -lgdi32 en las linker options


int main(int argc, char **argv)
{

    HDC hDC = GetDC(HWND_DESKTOP); //Crea el contexto
    POINT mouse; //Estructura que contiene las coordenadas
    COLORREF rgb; //Estructura de color

    // Values As byte
    BYTE rVal, gVal, bVal;
    //Valores
    int red, green, blue;



    while(1)
    {
        GetCursorPos(&mouse); // Obtiene la posicion del cursor
        rgb = GetPixel(hDC, mouse.x, mouse.y); //Obtiene una estructura de color en las posicion del mouse

        //Divide el valor rgb en 3 valores tipo byte
        rVal = GetRValue(rgb);
        gVal = GetGValue(rgb);
        bVal = GetBValue(rgb);

        // Convierte los valores byte a enteros
        red = (int)rVal;
        green = (int)gVal;
        blue = (int)bVal;

       //Imprime el resultado
        printf("En la posicion %d,%d el color RGB es: %d,%d,%d\n",mouse.x,mouse.y,red,green,blue);
    }
    return 0;
}
