/**
* Mouse Position Simple
* @Version 1.0
* @author Ariel Ivan Diaz
* @URL www.arielivandiaz.net
* \note Este programa immprime en consola la posicion del mouse
*/

#include<windows.h>
#include<stdio.h>

int main(int argc, char** argv)
{

    while(1)
    {

        POINT mouse; //Estructura que contiene las coordenadas
        HDC _hdc = GetDC(NULL);  //Crea el contexto
        if(_hdc)
        {


            GetCursorPos(&mouse);
             printf("La posicion del mouse es %d ; %d \n", mouse.x,mouse.y);
        }


    }

    return 0;
}
