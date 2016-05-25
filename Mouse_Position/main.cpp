/**
* Mouse Position
* @Version 1.0
* @author Ariel Ivan Diaz
* @URL www.arielivandiaz.net
* \note Este programa immprime en consola la posicion del mouse
*/

#define _WIN32_WINNT 0x0500 //Inicializacion necesaria para INPUT
#include <windows.h>


#define _WIN32_WINNT 0x0400
#pragma comment( lib, "user32.lib" )

#include <windows.h>
#include <stdio.h>
#include <time.h>


//Variables Globales
int mouse_X,mouse_Y; //En estas variables se almacena la posicion del mouse
HHOOK hMouseHook;


//Prototipo de funciones
__declspec(dllexport) LRESULT CALLBACK KeyboardEvent (int nCode, WPARAM wParam, LPARAM lParam);
void MessageLoop();
DWORD WINAPI MyMouseLogger(LPVOID lpParm);



int main(int argc, char** argv)
{

    HANDLE hThread;
    DWORD dwThread;
    hThread = CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)
                           MyMouseLogger, (LPVOID) argv[0], NULL, &dwThread);


    int x=0,y=0;


    while(!GetAsyncKeyState(VK_ESCAPE)) //Ejecutar hasta que se presione ESCAPE
    {

        if(mouse_X!=x || mouse_Y!=y)  //Si cambio la posicion del mouse la imprime
        {
            x=mouse_X;
            y=mouse_Y;
            printf("La posicion del mouse es %d ; %d \n",x,y);

        }

    }
    return 0;
}

//Declaracion de funciones
__declspec(dllexport) LRESULT CALLBACK KeyboardEvent (int nCode, WPARAM wParam, LPARAM lParam)
{
    MOUSEHOOKSTRUCT * pMouseStruct = (MOUSEHOOKSTRUCT *)lParam;
    if (pMouseStruct != NULL)
    {
        mouse_X=pMouseStruct->pt.x;
        mouse_Y=pMouseStruct->pt.y;
    }
    return CallNextHookEx(hMouseHook,
                          nCode,wParam,lParam);
}

void MessageLoop()
{
    MSG message;
    while (GetMessage(&message,NULL,0,0))
    {
        TranslateMessage( &message );
        DispatchMessage( &message );
    }
}

DWORD WINAPI MyMouseLogger(LPVOID lpParm)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    if (!hInstance) hInstance = LoadLibrary((LPCSTR) lpParm);
    if (!hInstance) return 1;

    hMouseHook = SetWindowsHookEx (
                     WH_MOUSE_LL,
                     (HOOKPROC) KeyboardEvent,
                     hInstance,
                     NULL
                 );
    MessageLoop();
    UnhookWindowsHookEx(hMouseHook);
    return 0;
}


