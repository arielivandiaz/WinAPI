/**
* Mouse Hook
* @Version 1.0
* @author Ariel Ivan Diaz
* @URL www.arielivandiaz.net
* \note Este programa toma el control del mouse
*/

#define _WIN32_WINNT 0x0500 //Inicializacion necesarioa para INPUT
#include <stdio.h>
#include <stdlib.h>
#include<strings.h>
#include <windows.h>

#define d 1
//Prototipo de funciones

void LeftClick();
void RightClick();

void LeftClick_2();  //Funciones alternativas usando Set y Unset
void RightClick_2();

void SetLeftClick();
void UnSetLeftClick();
void SetRightClick();
void UnSetRightClick();

void print_coords (); //IMprimir posicion del mouse

//Arreglo de coordenadas a utilizar
int coords[2][22]= {{2334,2412, 1950,  1950, 2350, 2350,  1950,  2547, 2000, 2000, 2400, 2400,  2000,2615, 2050, 2050, 2450, 2450,2050}
    ,{880, 69,   180,  580,  580,  180,   180,    94,  230,  630,  630,  230,   230,70,  270,  670,  670,  270,270}
};


int main()
{
    /** En el main lo que se ejecuta es la secuencia de pasos para hacer un dibujo en paint
    *   La demostracion de ejecucion de este dibujo esta en:https://www.youtube.com/watch?v=Gg7trLQ0Ndg
    **/

    int i=0,j,h,g;
    int flag_quit=GetKeyState(VK_ESCAPE);
    int offset=0;

     Sleep(2000); //Esperar 2 segundos antes de empezar

    print_coords();
    SetCursorPos(coords[0][i],coords[1][i]);
    i++;
    print_coords();

    for(g=0; g<3; g++)
    {
        SetCursorPos(coords[0][i],coords[1][i]);
        Sleep(d);
        LeftClick();
        i++;
        print_coords();
        for(h=0; h<3; h++)
        {

            SetCursorPos(coords[0][i],coords[1][i]);
            SetLeftClick();
            print_coords();
            for(j=coords[1][i]; j<coords[1][i+1]; j++)
            {
                SetCursorPos(coords[0][i]+offset,j+offset);
                Sleep(d);

            }
            i++;
            SetCursorPos(coords[0][i],coords[1][i]);


            for(j=coords[0][i]; j<coords[0][i+1]; j++)
            {
                SetCursorPos(j+offset,coords[1][i]+offset);
                Sleep(d);
            }
            i++;
            SetCursorPos(coords[0][i],coords[1][i]);
            UnSetLeftClick();

            SetLeftClick();
            for(j=coords[1][i]; j>coords[1][i+1]; j--)
            {
                SetCursorPos(coords[0][i]+offset,j+offset);
                Sleep(d);

            }
            i++;
            SetCursorPos(coords[0][i],coords[1][i]);


            for(j=coords[0][i]; j>coords[0][i+1]; j--)
            {
                SetCursorPos(j+offset,coords[1][i]+offset);
                Sleep(d);
            }
            UnSetLeftClick();

            print_coords();
            i++;
            SetCursorPos(coords[0][i],coords[1][i]);
            print_coords();
            i++;
            print_coords();
            SetCursorPos(coords[0][i],coords[1][i]);
            i++;
            LeftClick();
            print_coords();




            if(flag_quit!=GetKeyState(VK_ESCAPE))return 0; //Si se aprieta ESC salir*/

        }
        i=1;
        offset+=125;
    }


    return 1;

}

//Declaracion de funciones
void print_coords () //IMprimir posicion del mouse
{

    static HDC _hdc;    //Estructura que contiene las coordenadas
    static unsigned int flag_init=0; //Bandera para inicializar el HDC solo una vez
    POINT mouse; //Estructura que contiene las coordenadas

    static POINT mouse_aux; //Auxiliar para saber si se movio o no el mouse


    if(flag_init==0)  //Si el contexto no esta creado, crearlo.
    {
        _hdc = GetDC(NULL);
        flag_init=1;
        mouse_aux.x=0;
        mouse_aux.y=0;
    }

    if(_hdc)  //Si todo esta bien obtener e imprimir las cordenadas
    {
        GetCursorPos(&mouse);
        if(mouse.x!=mouse_aux.x || mouse.y!=mouse_aux.y )  //Si el mouse se movio imprimir coordenadas
        {
            printf("La posicion del mouse es %d ; %d \n", mouse.x,mouse.y);
            mouse_aux.x=mouse.x;
            mouse_aux.y=mouse.y;
        }
    }

}

void LeftClick()
{
    puts("LEFT CLICK");
    INPUT    Input= {0};												// Crear la esturctura de INPUT

    Input.type        = INPUT_MOUSE;									// Decimos que vamos a usar el mouse
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;							// Establecemos el evento como  apretar el boton izquierdo
    SendInput( 1, &Input, sizeof(INPUT) );								// Enviamos los cambios de INPUT

    ZeroMemory(&Input,sizeof(INPUT));									// Borramos los datos de estructura INPUT
    Input.type        = INPUT_MOUSE;									// Decimos que vamos a usar el mouse
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								// Establecemos el evento como soltar el boton izquierdo
    SendInput( 1, &Input, sizeof(INPUT) );								// Enviamos los cambios de INPUT
}
void RightClick()
{
    puts("RIGHT CLICK");
    INPUT    Input= {0};

    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;							// Establecemos el evento como  apretar el boton derecho
    SendInput( 1, &Input, sizeof(INPUT) );

    ZeroMemory(&Input,sizeof(INPUT));
    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;							// Establecemos el evento como soltar el boton derecho
    SendInput( 1, &Input, sizeof(INPUT) );
}
void LeftClick_2()
{
    SetLeftClick();
    Sleep(150);                                //Llamamos a la funcion para apretar el boton
    UnSetLeftClick();                        //Llamamos a la funcion para soltar el boton
}
void RightClick_2()
{
    SetRightClick();
    Sleep(50);
    UnSetRightClick();

}

void SetLeftClick()
{
    puts("SET LEFT CLICK");
    INPUT    Input= {0};

    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    SendInput( 1, &Input, sizeof(INPUT) );

}
void UnSetLeftClick()
{
    puts("UNSET LEFT CLICK");
    INPUT    Input= {0};

    ZeroMemory(&Input,sizeof(INPUT));
    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    SendInput( 1, &Input, sizeof(INPUT) );
}
void SetRightClick()
{
    puts("SET RIGHT CLICK");
    INPUT    Input= {0};

    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
    SendInput( 1, &Input, sizeof(INPUT) );
}
void UnSetRightClick()
{
    puts("UNSET RIGHT CLICK");
    INPUT    Input= {0};

    ZeroMemory(&Input,sizeof(INPUT));
    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
    SendInput( 1, &Input, sizeof(INPUT) );
}

