#include <windows.h>
#include <commctrl.h>
#include <stdlib.h>
#include <time.h>
//#include <iostream>>

//using namespace std;

#define CM_NUEVAPARTIDA       101
#define CM_AYUDA              102
#define CM_SALIR              103
#define CM_PEDIRCARTA         104
#define CM_INICIARPARTIDA     105
#define CM_PLANTARSE          106
#define CM_CARTA              110
#define CM_JUGARDENUEVO       111
#define CM_ATRAS              112



int xinicial = 0;
int yinicial = 500;

int x = 50;
int y = 150;

int alto = 0;
int ancho = 0;
int anchocarta = 0;
int altocarta = 0;
int comp = 0;
int xbot = 0;
int ybot = 0;

int BANCAx = 550;
int BANCAy = 150;

int baraja[51];
int a = {0, 1, 2, 3};
int numero = 0;
int left;
int cx;
int cy;
int cuentabanca = 0;

/*  Declaración del procedimiento de ventana  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND hwnd;

void CStretchBltjugador1(HDC, HWND, HBITMAP);
void CStretchBltjugador2(HDC, HWND, HBITMAP);
void CStretchBltbanca(HDC, HWND, HBITMAP);
void CStretchBltjugador(HDC, HWND, HBITMAP);
void CStretchBltayuda(HDC, HWND, HBITMAP);
void CStretchBltjugadorcartacartabanca1(HDC, HWND, HBITMAP);
void CStretchBlt0(HDC, HWND, HBITMAP);
void CStretchBlt1(HDC, HWND, HBITMAP);
void CartasBanca ();
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
                  /* Manipulador de ventana */
    MSG mensaje;             /* Mensajes recibidos por la aplicación */
    WNDCLASSEX wincl;


    /* Estructura de datos para la clase de ventana */


    /* Estructura de la ventana */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "NUESTRA_CLASE";
    wincl.lpfnWndProc = WindowProcedure;      /* Esta función es invocada por Windows */
    wincl.style = CS_DBLCLKS;                 /* Captura los doble-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Usar icono y puntero por defector */
    wincl.hIcon = LoadIcon (hThisInstance, "Icono");
    wincl.hIconSm = LoadIcon (hThisInstance, "Icono");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;                      /* Sin información adicional para la */
    wincl.cbWndExtra = 0;                      /* clase o la ventana */
    /* Usar el color de fondo por defecto para la ventana */
    wincl.hbrBackground =  CreateSolidBrush(RGB (0, 69, 0)); //COLOR_BACKGROUND);

    /* Registrar la clase de ventana, si falla, salir del programa */
    if(!RegisterClassEx(&wincl)) return 0;

    /* La clase está registrada, crear la ventana */
    hwnd = CreateWindowEx(
           0,                   /* Posibilidades de variación */
           "NUESTRA_CLASE",     /* Nombre de la clase */
           "BLACKJACK",       /* Texto del título */
           WS_OVERLAPPEDWINDOW, /* Tipo por defecto */
           CW_USEDEFAULT,       /* Windows decide la posición */
           CW_USEDEFAULT,       /* donde se coloca la ventana */
           CW_USEDEFAULT,                 /* Ancho */
           CW_USEDEFAULT,                 /* Alto en pixels */
           HWND_DESKTOP,        /* La ventana es hija del escritorio */
           NULL,                /* Sin menú */
           hThisInstance,       /* Manipulador de instancia */
           NULL                 /* No hay datos de creación de ventana */
    );

    InitCommonControls();
    /* Mostrar la ventana */
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);


    /* Bucle de mensajes, se ejecuta hasta que haya error o GetMessage devuelva FALSE */
    while(TRUE == GetMessage(&mensaje, NULL, 0, 0))
    {
       if(!IsDialogMessage(hwnd, &mensaje) ) {
        /* Traducir mensajes de teclas virtuales a mensajes de caracteres */
        TranslateMessage(&mensaje);
        /* Enviar mensaje al procedimiento de ventana */
        DispatchMessage(&mensaje);
        }
    }
    /* Salir con valor de retorno */
    return mensaje.wParam;





}

/*  Esta función es invocada por la función DispatchMessage()  */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    /* Variables para diálogo */
    HDC hDC;
    PAINTSTRUCT ps;
    RECT re;
    GetClientRect(hwnd, &re);



    static HWND nuevapartida, salir, ayuda, pedircarta, iniciarpartida, plantarse, jugardenuevo, JUGADOR, atras, cuenta;

    static HINSTANCE hInstance;



    ancho = re.right;
    alto = re.bottom;

    anchocarta = (ancho / 80)*5.8;
    altocarta = (alto/50)*9;



    static HBITMAP corazones1;
    static HBITMAP corazones2;
    static HBITMAP corazones3;
    static HBITMAP corazones4;
    static HBITMAP corazones5;
    static HBITMAP corazones6;
    static HBITMAP corazones7;
    static HBITMAP corazones8;
    static HBITMAP corazones9;
    static HBITMAP corazones10;
    static HBITMAP corazonesJ;
    static HBITMAP corazonesQ;
    static HBITMAP corazonesK;

    static HBITMAP treboles1;
    static HBITMAP treboles2;
    static HBITMAP treboles3;
    static HBITMAP treboles4;
    static HBITMAP treboles5;
    static HBITMAP treboles6;
    static HBITMAP treboles7;
    static HBITMAP treboles8;
    static HBITMAP treboles9;
    static HBITMAP treboles10;
    static HBITMAP trebolesJ;
    static HBITMAP trebolesQ;
    static HBITMAP trebolesK;

    static HBITMAP diamantes1;
    static HBITMAP diamantes2;
    static HBITMAP diamantes3;
    static HBITMAP diamantes4;
    static HBITMAP diamantes5;
    static HBITMAP diamantes6;
    static HBITMAP diamantes7;
    static HBITMAP diamantes8;
    static HBITMAP diamantes9;
    static HBITMAP diamantes10;
    static HBITMAP diamantesJ;
    static HBITMAP diamantesQ;
    static HBITMAP diamantesK;

    static HBITMAP picas1;
    static HBITMAP picas2;
    static HBITMAP picas3;
    static HBITMAP picas4;
    static HBITMAP picas5;
    static HBITMAP picas6;
    static HBITMAP picas7;
    static HBITMAP picas8;
    static HBITMAP picas9;
    static HBITMAP picas10;
    static HBITMAP picasJ;
    static HBITMAP picasQ;
    static HBITMAP picasK;

    static HBITMAP jugador;
    static HBITMAP banca;

    static HBITMAP imagen;

    static HBITMAP ayuda1;

    static HBITMAP yw;
    int A[4];

    static int tipo = 0;
    static int tipo0 = 0;
    static int tipo1 = 0;
    static int tipo2 = 0;
    static int tipo3 = 0;
    static int tipo4 = 0;
    static int tipo5 = 0;
    static int tipo6 = 0;

    static int carta0 = 0;
    static int carta = 0;
    static HRGN cregion0;
    static HRGN cregion1;
    static HRGN cregion2;
    static HRGN cregion3;
    static HRGN regionbanca;
    static HRGN regionultima;
    static int letrero = 0;


    xbot = (re.right - re.left)/20;
    ybot = (re.bottom - re.top)/20;


	int aux = 0;
	int aux1 = 0;
	int cuentajugador = 0;
	srand(time(NULL));

    switch (msg)              /* manipulador del mensaje */
    {
        case WM_CREATE:
           hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
           imagen = LoadBitmap(hInstance, "inicio");
           jugador = LoadBitmap(hInstance, "jugador");
           banca = LoadBitmap(hInstance, "casino");
           RECT re;
           GetClientRect(hwnd, &re);
           cregion0 = CreateRectRgn(200, 300, 316, 480);
           cregion1 = CreateRectRgn(250, 350, 366, 530);
           cregion2 = CreateRectRgn(300, 400, 416, 580);
           cregion3 = CreateRectRgn(350, 450, 466, 630);
           regionbanca = CreateRectRgn(600, 100, 10000, 10000);

           ayuda1 = LoadBitmap(hInstance, "ayuda");
           yw = LoadBitmap(hInstance, "yw");

           corazones1 = LoadBitmap(hInstance, "corazones1");
           corazones2 = LoadBitmap(hInstance, "corazones2");
           corazones3 = LoadBitmap(hInstance, "corazones3");
           corazones4 = LoadBitmap(hInstance, "corazones4");
           corazones5 = LoadBitmap(hInstance, "corazones5");
           corazones6 = LoadBitmap(hInstance, "corazones6");
           corazones7 = LoadBitmap(hInstance, "corazones7");
           corazones8 = LoadBitmap(hInstance, "corazones8");
           corazones9 = LoadBitmap(hInstance, "corazones9");
           corazones10 = LoadBitmap(hInstance, "corazones10");
           corazonesJ = LoadBitmap(hInstance, "corazonesJ");
           corazonesQ = LoadBitmap(hInstance, "corazonesQ");
           corazonesK = LoadBitmap(hInstance, "corazonesK");

           diamantes1 = LoadBitmap(hInstance, "diamantes1");
           diamantes2 = LoadBitmap(hInstance, "diamantes2");
           diamantes3 = LoadBitmap(hInstance, "diamantes3");
           diamantes4 = LoadBitmap(hInstance, "diamantes4");
           diamantes5 = LoadBitmap(hInstance, "diamantes5");
           diamantes6 = LoadBitmap(hInstance, "diamantes6");
           diamantes7 = LoadBitmap(hInstance, "diamantes7");
           diamantes8 = LoadBitmap(hInstance, "diamantes8");
           diamantes9 = LoadBitmap(hInstance, "diamantes9");
           diamantes10 = LoadBitmap(hInstance, "diamantes10");
           diamantesJ = LoadBitmap(hInstance, "diamantesJ");
           diamantesQ = LoadBitmap(hInstance, "diamantesQ");
           diamantesK = LoadBitmap(hInstance, "diamantesK");

           treboles1 = LoadBitmap(hInstance, "treboles1");
           treboles2 = LoadBitmap(hInstance, "treboles2");
           treboles3 = LoadBitmap(hInstance, "treboles3");
           treboles4 = LoadBitmap(hInstance, "treboles4");
           treboles5 = LoadBitmap(hInstance, "treboles5");
           treboles6 = LoadBitmap(hInstance, "treboles6");
           treboles7 = LoadBitmap(hInstance, "treboles7");
           treboles8 = LoadBitmap(hInstance, "treboles8");
           treboles9 = LoadBitmap(hInstance, "treboles9");
           treboles10 = LoadBitmap(hInstance, "treboles10");
           trebolesJ = LoadBitmap(hInstance, "trebolesJ");
           trebolesQ = LoadBitmap(hInstance, "trebolesQ");
           trebolesK = LoadBitmap(hInstance, "trebolesK");

           picas1 = LoadBitmap(hInstance, "picas1");
           picas2 = LoadBitmap(hInstance, "picas2");
           picas3 = LoadBitmap(hInstance, "picas3");
           picas4 = LoadBitmap(hInstance, "picas4");
           picas5 = LoadBitmap(hInstance, "picas5");
           picas6 = LoadBitmap(hInstance, "picas6");
           picas7 = LoadBitmap(hInstance, "picas7");
           picas8 = LoadBitmap(hInstance, "picas8");
           picas9 = LoadBitmap(hInstance, "picas9");
           picas10 = LoadBitmap(hInstance, "picas10");
           picasJ = LoadBitmap(hInstance, "picasJ");
           picasQ = LoadBitmap(hInstance, "picasQ");
           picasK = LoadBitmap(hInstance, "picasK");

           nuevapartida = CreateWindowEx(0, "BUTTON", "NUEVA PARTIDA", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, xbot, 4*ybot, 130, 50, hwnd, (HMENU)CM_NUEVAPARTIDA, hInstance, NULL);
           ayuda = CreateWindowEx(0, "BUTTON", "AYUDA", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, xbot, 12*ybot, 130, 50, hwnd, (HMENU)CM_AYUDA, hInstance, NULL);
           salir = CreateWindowEx(0, "BUTTON", "SALIR", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, xbot, 20*ybot, 130, 50, hwnd, (HMENU)CM_SALIR, hInstance, NULL);
           iniciarpartida = CreateWindowEx(0, "BUTTON", "INICIAR PARTIDA", WS_CHILD | WS_BORDER | WS_TABSTOP, 50, 50, 50, 50, hwnd, (HMENU)CM_INICIARPARTIDA, hInstance, NULL);
           plantarse = CreateWindowEx(0, "BUTTON", "PLANTARSE", WS_CHILD | WS_BORDER |WS_TABSTOP, 15*xbot, 25*ybot, 130, 50, hwnd, (HMENU)CM_PLANTARSE, hInstance, NULL);
           pedircarta = CreateWindowEx(0, "BUTTON", "PEDIR CARTA", WS_CHILD | WS_BORDER |WS_TABSTOP , 9*xbot, 25*ybot, 130, 50, hwnd, (HMENU)CM_CARTA, hInstance, NULL);
           jugardenuevo = CreateWindowEx(0, "BUTTON", "JUGAR DE NUEVO", WS_CHILD | WS_BORDER |WS_TABSTOP, 8.5*xbot, 25*ybot, 130, 50, hwnd, (HMENU)CM_JUGARDENUEVO, hInstance, NULL);
           atras = CreateWindowEx(0, "BUTTON", "ATRÁS", WS_CHILD | WS_BORDER | WS_TABSTOP, re.right-200, re.bottom-200, 130, 50, hwnd, (HMENU)CM_ATRAS, hInstance, NULL);
           cuenta  = CreateWindowEx(0, "STATIC", a, WS_CHILD, 10, 10, 130, 50, hwnd, NULL, hInstance, NULL);
           return 0;

        case WM_COMMAND:

           switch(LOWORD(wParam)) {
                case CM_NUEVAPARTIDA:
                    tipo=1;
                    InvalidateRect(hwnd, NULL, TRUE);
                    ShowWindow(nuevapartida, SW_HIDE);
                    ShowWindow(ayuda, SW_HIDE);
                    ShowWindow(iniciarpartida, SW_SHOWMAXIMIZED);
                    ShowWindow(salir, SW_HIDE);
                    break;
                case CM_AYUDA:
                    tipo=2;
                    InvalidateRgn(hwnd, NULL, TRUE);
                    ShowWindow(nuevapartida, SW_HIDE);
                    ShowWindow(ayuda, SW_HIDE);
                    ShowWindow(salir, SW_HIDE);
                    ShowWindow(atras, SW_SHOWNORMAL);
                    break;
                case CM_SALIR:
                    tipo = 3;
                    InvalidateRect(hwnd, NULL, TRUE);
                    DeleteObject(corazones1);
                    DeleteObject(corazones2);
                    PostQuitMessage(0);
                    break;
                case CM_INICIARPARTIDA:
                    carta0 = 1;
                    carta = 0;
                    letrero = 1;
                    ShowWindow(iniciarpartida, SW_HIDE);
                    ShowWindow(pedircarta, SW_SHOWNORMAL);
                    ShowWindow(plantarse, SW_SHOWNORMAL);
                    InvalidateRect(hwnd, NULL, TRUE);
                    cuentajugador = 0;

                    break;
               case CM_CARTA:
                   carta0 = 4;
                   carta++;
                   InvalidateRect(hwnd, NULL, TRUE);

                   /*if(carta == 1){
                    InvalidateRgn(hwnd, cregion0, TRUE);
                   }
                   if(carta == 2){
                    InvalidateRgn(hwnd, cregion1, TRUE);
                   }
                   if(carta == 3){
                    InvalidateRgn(hwnd, cregion2, TRUE);
                   }
                   if(carta == 4){
                    InvalidateRgn(hwnd, cregion3, TRUE);
                   }*/



                    break;
                case CM_PLANTARSE:
                    tipo = 6;
                    carta = 20;
                    tipo6 = 1;
                    xbot = (re.right - re.left)/20;
                    ybot = (re.bottom - re.top)/20;
                    ShowWindow(pedircarta, SW_HIDE);
                    ShowWindow(jugardenuevo, SW_SHOW);
                    ShowWindow(salir, SW_SHOW);
                    MoveWindow(salir, 10.9*xbot, 17.1*ybot, 130, 50, TRUE);
                    ShowWindow(plantarse, SW_HIDE);
                    ShowWindow(cuenta, SW_SHOW);
                    InvalidateRgn(hwnd, regionbanca, TRUE);
                    break;

                case CM_JUGARDENUEVO:
                    ShowWindow(iniciarpartida, SW_SHOWMAXIMIZED);
                    ShowWindow(plantarse, SW_HIDE);
                    ShowWindow(jugardenuevo, SW_HIDE);
                    ShowWindow(salir, SW_HIDE);

                    tipo6 = 0;
                    cuentajugador = 0;
                    cuentabanca = 0;
                    BANCAx = 550;
                    BANCAy = 150;
                    x = 50;
                    y = 150;
                    break;

                case CM_ATRAS:
                    tipo = 0;
                    ShowWindow(nuevapartida, SW_SHOWNORMAL);
                    ShowWindow(ayuda, SW_SHOWNORMAL);
                    ShowWindow(salir, SW_SHOWNORMAL);
                    ShowWindow(atras, SW_HIDE);
                    InvalidateRgn(hwnd, NULL, TRUE);
                    }
           break;

        case WM_PAINT:

            hDC = BeginPaint(hwnd, &ps);
          if(tipo == 0){
            CStretchBltinicio1(hDC, hwnd, trebolesK);
            CStretchBltinicio0(hDC, hwnd, corazones1);
            }
            else if (tipo == 2){

                CStretchBltayuda(hDC, hwnd, ayuda1);
            }
                if(letrero == 1){
            CStretchBltjugador1(hDC, hwnd, jugador);
            CStretchBltjugador2(hDC, hwnd, banca);
        }

if(carta0 == 1){
		for(int i=0; i<=0; i++){
			aux = rand()%51;
			//cout << aux << endl;

		//cuentabanca = 17;
		if(aux == 0 || aux == 13 || aux == 26 || aux == 39){
			if(cuentajugador >= 11){
				cuentajugador += 1;
			}
			else {
				cuentajugador += 11;
			}
		for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones1);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas1);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles1);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes1);
				}
		}
		}
		else if(aux == 1 || aux == 14 || aux == 27 || aux == 40){
			cuentajugador +=2;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones2);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas2);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles2);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes2);
				}
			}
		}
		else if(aux == 2 || aux == 15 || aux == 28 || aux == 41){
			cuentajugador +=3;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones3);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas3);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles3);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes3);
				}
		}
		}
		else if(aux == 3 || aux == 16 || aux == 29 || aux == 42){
			cuentajugador +=4;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones4);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas4);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles4);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes4);
				}
		}
		}
		else if(aux == 4 || aux == 17 || aux == 30 || aux == 43){
			cuentajugador +=5;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones5);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas5);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles5);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes5);
				}
		}
		}
		else if(aux == 5 || aux == 18 || aux == 31 || aux == 44){
			cuentajugador +=6;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones6);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas6);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles6);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes6);
				}
			}
		}
		else if(aux == 6 || aux == 19 || aux == 32 || aux == 45){
			cuentajugador +=7;
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones7);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas7);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles7);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes7);
				}
		}}
		else if(aux == 7 || aux == 20 || aux == 33 || aux == 46){
			cuentajugador +=8;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones8);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas8);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles8);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes8);
				}
		}}
		else if(aux == 8 || aux == 21 || aux == 34 || aux == 47){
			cuentajugador +=9;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones9);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas9);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles9);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes9);
				}
		}}
		else if(aux == 9 || aux == 22 || aux == 35 || aux == 48){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones10);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas10);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles10);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes10);
				}
		}}
		else if(aux == 10 || aux == 23 || aux == 36 || aux == 49){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesJ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasJ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesJ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesJ);
				}
		}}
		else if(aux == 11 || aux == 24 || aux == 37 || aux == 50){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesQ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasQ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesQ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesQ);
				}
		}
		}
		else if(aux == 12 || aux == 25 || aux == 38 || aux == 51){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesK);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasK);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesK);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesK);
				}
		}
		}
		//cout << cuentabanca << endl;

		}
        }
if(carta0 == 1){


		for(int i=0; i<=0; i++){
			aux = rand()%51;
			//cout << endl<<endl<<endl<<aux<<endl;


		//cout << aux << endl;
		//cuentabanca = 17;

		if(aux == 0 || aux == 13 || aux == 26 || aux == 39){

			if(cuentajugador >= 11){
				cuentajugador += 1;
			}
			else {
				cuentajugador += 11;
			}
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones1);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas1);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles1);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes1);
				}
		}
		}

		else if(aux == 1 || aux == 14 || aux == 27 || aux == 40){
			cuentajugador +=2;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones2);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas2);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles2);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes2);
				}
			}

		}
		else if(aux == 2 || aux == 15 || aux == 28 || aux == 41){
			cuentajugador +=3;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones3);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas3);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles3);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes3);
				}
		}
		}
		else if(aux == 3 || aux == 16 || aux == 29 || aux == 42){
			cuentajugador +=4;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones4);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas4);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles4);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes4);
				}
		}
		}
		else if(aux == 4 || aux == 17 || aux == 30 || aux == 43){
			cuentajugador +=5;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones5);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas5);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles5);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes5);
				}
		}
		}
		else if(aux == 5 || aux == 18 || aux == 31 || aux == 44){
			cuentajugador +=6;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones6);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas6);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles6);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes6);
				}
		}
		}
		else if(aux == 6 || aux == 19 || aux == 32 || aux == 45){
			cuentajugador +=7;
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones7);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas7);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles7);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes7);
				}
		}
		}
		else if(aux == 7 || aux == 20 || aux == 33 || aux == 46){
			cuentajugador +=8;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones8);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas8);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles8);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes8);
				}
		}
		}
		else if(aux == 8 || aux == 21 || aux == 34 || aux == 47){
			cuentajugador +=9;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones9);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas9);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles9);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes9);
				}
		}
		}
		else if(aux == 9 || aux == 22 || aux == 35 || aux == 48){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones10);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas10);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles10);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes10);
				}
		}
		}
		else if(aux == 10 || aux == 23 || aux == 36 || aux == 49){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesJ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasJ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesJ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesJ);
				}
		}
		}
		else if(aux == 11 || aux == 24 || aux == 37 || aux == 50){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesQ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasQ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesQ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesQ);
				}
		}
		}
		else if(aux == 12 || aux == 25 || aux == 38 || aux == 51){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesK);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasK);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesK);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesK);
				}
		}
		}
		//cout <<endl<<endl<<endl<<cuentajugador;
		//cout << cuentabanca << endl;
		}
		}

if(carta == 1){


		for(int i=0; i<=0; i++){
			aux = rand()%51;
			//cout << endl<<endl<< endl<<aux <<endl <<endl <<endl;


		//cout << aux << endl;
		//cuentabanca = 17;

		if(aux == 0 || aux == 13 || aux == 26 || aux == 39){

			if(cuentajugador >= 11){
				cuentajugador += 1;
			}
			else {
				cuentajugador += 11;
			}
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones1);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas1);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles1);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes1);
				}
                }
		}
		else if(aux == 1 || aux == 14 || aux == 27 || aux == 40){
			cuentajugador +=2;
		for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones2);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas2);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles2);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes2);
				}
			}

		}
		else if(aux == 2 || aux == 15 || aux == 28 || aux == 41){
			cuentajugador +=3;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones3);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas3);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles3);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes3);
				}
		}
		}
		else if(aux == 3 || aux == 16 || aux == 29 || aux == 42){
			cuentajugador +=4;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones4);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas4);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles4);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes4);
				}
		}
		}
		else if(aux == 4 || aux == 17 || aux == 30 || aux == 43){
			cuentajugador +=5;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones5);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas5);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles5);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes5);
				}
		}
		}
		else if(aux == 5 || aux == 18 || aux == 31 || aux == 44){
			cuentajugador +=6;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones6);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas6);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles6);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes6);
				}
		}}
		else if(aux == 6 || aux == 19 || aux == 32 || aux == 45){
			cuentajugador +=7;
		for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones7);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas7);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles7);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes7);
				}
		}}
		else if(aux == 7 || aux == 20 || aux == 33 || aux == 46){
			cuentajugador +=8;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones8);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas8);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles8);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes8);
				}
		}}
		else if(aux == 8 || aux == 21 || aux == 34 || aux == 47){
			cuentajugador +=9;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones9);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas9);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles9);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes9);
				}
		}}
		else if(aux == 9 || aux == 22 || aux == 35 || aux == 48){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones10);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas10);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles10);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes10);
				}
		}
		}
		else if(aux == 10 || aux == 23 || aux == 36 || aux == 49){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesJ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasJ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesJ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesJ);
				}
		}
		}
		else if(aux == 11 || aux == 24 || aux == 37 || aux == 50){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesQ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasQ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesQ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesQ);
				}
		}
		}
		else if(aux == 12 || aux == 25 || aux == 38 || aux == 51){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesK);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasK);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesK);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesK);
				}
		}
		}
		}
        }
		//cout << cuentabanca << endl;
if(carta == 2){


		for(int i=0; i<=0; i++){
			aux = rand()%51;
		//	cout << endl<<endl<<endl<<aux <<endl<< endl<<endl;


		//cout << aux << endl;
		//cuentabanca = 17;

		if(aux == 0 || aux == 13 || aux == 26 || aux == 39){

			if(cuentajugador >= 11){
				cuentajugador += 1;
			}
			else {
				cuentajugador += 11;
			}
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones1);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas1);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles1);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes1);
				}
		}
		}
		else if(aux == 1 || aux == 14 || aux == 27 || aux == 40){
			cuentajugador +=2;
		for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones2);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas2);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles2);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes2);
				}
			}

		}
		else if(aux == 2 || aux == 15 || aux == 28 || aux == 41){
			cuentajugador +=3;
		for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones3);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas3);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles3);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes3);
				}
		}
		}
		else if(aux == 3 || aux == 16 || aux == 29 || aux == 42){
			cuentajugador +=4;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones4);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas4);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles4);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes4);
				}
		}
		}
		else if(aux == 4 || aux == 17 || aux == 30 || aux == 43){
			cuentajugador +=5;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones5);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas5);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles5);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes5);
				}
		}
		}
		else if(aux == 5 || aux == 18 || aux == 31 || aux == 44){
			cuentajugador +=6;
		for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones6);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas6);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles6);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes6);
				}
		}
		}
		else if(aux == 6 || aux == 19 || aux == 32 || aux == 45){
			cuentajugador +=7;
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones7);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas7);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles7);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes7);
				}
		}
		}
		else if(aux == 7 || aux == 20 || aux == 33 || aux == 46){
			cuentajugador +=8;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones8);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas8);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles8);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes8);
				}
		}
		}
		else if(aux == 8 || aux == 21 || aux == 34 || aux == 47){
			cuentajugador +=9;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones9);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas9);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles9);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes9);
				}
		}
		}
		else if(aux == 9 || aux == 22 || aux == 35 || aux == 48){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
            aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones10);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas10);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles10);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes10);
				}
		}
		}
		else if(aux == 10 || aux == 23 || aux == 36 || aux == 49){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesJ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasJ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesJ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesJ);
				}
		}
		}
		else if(aux == 11 || aux == 24 || aux == 37 || aux == 50){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesQ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasQ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesQ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesQ);
				}
		}
		}
		else if(aux == 12 || aux == 25 || aux == 38 || aux == 51){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesK);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasK);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesK);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesK);
				}
		}
		}
		//cout << cuentabanca << endl;
        }
		}
if(carta == 3){


		for(int i=0; i<=0; i++){
			aux = rand()%51;
		//	cout << endl<<endl<< endl<<aux <<endl <<endl <<endl;


		//cout << aux << endl;
		//cuentabanca = 17;

		if(aux == 0 || aux == 13 || aux == 26 || aux == 39){

			if(cuentajugador >= 11){
				cuentajugador += 1;
			}
			else {
				cuentajugador += 11;
			}
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones1);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas1);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles1);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes1);
				}
		}
		}
		else if(aux == 1 || aux == 14 || aux == 27 || aux == 40){
			cuentajugador +=2;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones2);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas2);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles2);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes2);
				}
			}

		}
		else if(aux == 2 || aux == 15 || aux == 28 || aux == 41){
			cuentajugador +=3;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones3);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas3);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles3);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes3);
				}
		}
		}
		else if(aux == 3 || aux == 16 || aux == 29 || aux == 42){
			cuentajugador +=4;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones4);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas4);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles4);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes4);
				}
		}
		}
		else if(aux == 4 || aux == 17 || aux == 30 || aux == 43){
			cuentajugador +=5;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones5);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas5);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles5);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes5);
				}
		}
		}
		else if(aux == 5 || aux == 18 || aux == 31 || aux == 44){
			cuentajugador +=6;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones6);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas6);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles6);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes6);
				}
		}
		}
		else if(aux == 6 || aux == 19 || aux == 32 || aux == 45){
			cuentajugador +=7;
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones7);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas7);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles7);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes7);
				}
		}
		}
		else if(aux == 7 || aux == 20 || aux == 33 || aux == 46){
			cuentajugador +=8;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones8);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas8);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles8);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes8);
				}
		}
		}
		else if(aux == 8 || aux == 21 || aux == 34 || aux == 47){
			cuentajugador +=9;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones9);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas9);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles9);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes9);
				}
		}
		}
		else if(aux == 9 || aux == 22 || aux == 35 || aux == 48){
			cuentajugador +=10;
		for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones10);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas10);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles10);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes10);
				}
		}
		}
		else if(aux == 10 || aux == 23 || aux == 36 || aux == 49){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesJ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasJ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesJ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesJ);
				}
		}
		}
		else if(aux == 11 || aux == 24 || aux == 37 || aux == 50){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesQ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasQ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesQ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesQ);
				}
		}
		}
		else if(aux == 12 || aux == 25 || aux == 38 || aux == 51){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesK);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasK);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesK);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesK);
				}
		}
		}
		//cout << cuentabanca << endl;
		}
		}
if(carta == 4){
		for(int i=0; i<=0; i++){
			aux = rand()%51;
			//cout << endl<<endl<< endl<<aux <<endl <<endl <<endl;


		//cout << aux << endl;
		//cuentabanca = 17;

		if(aux == 0 || aux == 13 || aux == 26 || aux == 39){

			if(cuentajugador >= 11){
				cuentajugador += 1;
			}
			else {
				cuentajugador += 11;
			}
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones1);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas1);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles1);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes1);
				}
		}
		}
		else if(aux == 1 || aux == 14 || aux == 27 || aux == 40){
			cuentajugador +=2;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones2);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas2);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles2);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes2);
				}
			}

		}
		else if(aux == 2 || aux == 15 || aux == 28 || aux == 41){
			cuentajugador +=3;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones3);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas3);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles3);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes3);
				}
		}
		}
		else if(aux == 3 || aux == 16 || aux == 29 || aux == 42){
			cuentajugador +=4;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones4);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas4);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles4);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes4);
				}
		}
		}
		else if(aux == 4 || aux == 17 || aux == 30 || aux == 43){
			cuentajugador +=5;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones5);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas5);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles5);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes5);
				}
		}
		}
		else if(aux == 5 || aux == 18 || aux == 31 || aux == 44){
			cuentajugador +=6;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones6);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas6);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles6);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes6);
				}
		}
		}
		else if(aux == 6 || aux == 19 || aux == 32 || aux == 45){
			cuentajugador +=7;
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones7);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas7);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles7);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes7);
				}
		}
		}
		else if(aux == 7 || aux == 20 || aux == 33 || aux == 46){
			cuentajugador +=8;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones8);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas8);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles8);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes8);
				}
		}
		}
		else if(aux == 8 || aux == 21 || aux == 34 || aux == 47){
			cuentajugador +=9;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones9);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas9);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles9);
				}
				if(aux1 == 3){
					CStretchBltjugaor(hDC, hwnd, diamantes9);
				}
		}
		}
		else if(aux == 9 || aux == 22 || aux == 35 || aux == 48){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazones10);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picas10);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, treboles10);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantes10);
				}
		}
		}
		else if(aux == 10 || aux == 23 || aux == 36 || aux == 49){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesJ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasJ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesJ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesJ);
				}
		}
		}
		else if(aux == 11 || aux == 24 || aux == 37 || aux == 50){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesQ);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasQ);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesQ);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesQ);
				}
		}
		}
		else if(aux == 12 || aux == 25 || aux == 38 || aux == 51){
			cuentajugador +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltjugador(hDC, hwnd, corazonesK);
				}
				if(aux1 == 1){
					CStretchBltjugador(hDC, hwnd, picasK);
				}
				if(aux1 == 2){
					CStretchBltjugador(hDC, hwnd, trebolesK);
				}
				if(aux1 == 3){
					CStretchBltjugador(hDC, hwnd, diamantesK);
				}
		}
	}
		}
	}
if(tipo6 == 1){ //banca
	while(cuentabanca < 17){
		for(int i=0; i<=0; i++){
			aux = rand()%51;
		}

		//cout << aux << endl;
		//cuentabanca = 17;

		if(aux == 0 || aux == 13 || aux == 26 || aux == 39){
			if(cuentabanca >= 11){
				cuentabanca += 1;
			}
			else {
				cuentabanca += 11;
			}
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones1);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas1);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles1);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes1);
				}
		}
		}
		else if(aux == 1 || aux == 14 || aux == 27 || aux == 40){
			cuentabanca +=2;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones2);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas2);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles2);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes2);
				}
			}
		}
		else if(aux == 2 || aux == 15 || aux == 28 || aux == 41){
			cuentabanca +=3;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones3);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas3);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles3);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes3);
				}
		}
		}
		else if(aux == 3 || aux == 16 || aux == 29 || aux == 42){
			cuentabanca +=4;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones4);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas4);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles4);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes4);
				}
		}
		}
		else if(aux == 4 || aux == 17 || aux == 30 || aux == 43){
			cuentabanca +=5;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones5);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas5);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles5);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes5);
				}
		}}
		else if(aux == 5 || aux == 18 || aux == 31 || aux == 44){
			cuentabanca +=6;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones6);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas6);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles6);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes6);
				}
		}}
		else if(aux == 6 || aux == 19 || aux == 32 || aux == 45){
			cuentabanca +=7;
			for(int i= 0; i<=0; i++){

				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones7);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas7);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles7);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes7);
				}
		}}
		else if(aux == 7 || aux == 20 || aux == 33 || aux == 46){
			cuentabanca +=8;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones8);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas8);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles8);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes8);
				}
		}}
		else if(aux == 8 || aux == 21 || aux == 34 || aux == 47){
			cuentabanca +=9;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones9);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas9);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles9);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes9);
				}
		}}
		else if(aux == 9 || aux == 22 || aux == 35 || aux == 48){
			cuentabanca +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazones10);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picas10);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, treboles10);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantes10);
				}
		}}
		else if(aux == 10 || aux == 23 || aux == 36 || aux == 49){
			cuentabanca +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazonesJ);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picasJ);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, trebolesJ);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantesJ);
				}
		}}
		else if(aux == 11 || aux == 24 || aux == 37 || aux == 50){
			cuentabanca +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazonesQ);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picasQ);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, trebolesQ);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantesQ);
				}
		}
		}
		else if(aux == 12 || aux == 25 || aux == 38 || aux == 51){
			cuentabanca +=10;
			for(int i= 0; i<=0; i++){
				aux1 = rand()%3;
				if(aux1 == 0){
					CStretchBltbanca(hDC, hwnd, corazonesK);
				}
				if(aux1 == 1){
					CStretchBltbanca(hDC, hwnd, picasK);
				}
				if(aux1 == 2){
					CStretchBltbanca(hDC, hwnd, trebolesK);
				}
				if(aux1 == 3){
					CStretchBltbanca(hDC, hwnd, diamantesK);
				}
		}
		}
		//cout << cuentabanca << endl;
		}
            }
           /*if (cuentajugador < 21)
           {
               CStretchBltjugador(hDC, hwnd, banca);
           }

           EndPaint(hwnd, &ps);

           break;
        case WM_DESTROY:
           PostQuitMessage(0);    /* envía un mensaje WM_QUIT a la cola de mensajes */
           break;
        default:                  /* para los mensajes de los que no nos ocupamos */
           return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}


void CStretchBltjugador(HDC hDC, HWND hWnd, HBITMAP hBitmap){

    HDC memDC;
    BITMAP bm;
    RECT re;
    memDC = CreateCompatibleDC(hDC);
    SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
    GetClientRect(hWnd, &re);
    x += 50;
    y += 50;
    StretchBlt(hDC, x, y, anchocarta, altocarta, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
    DeleteDC(memDC);
}
/*void CStretchBltjugador01(HDC hDC, HWND hWnd, HBITMAP hBitmap){

    HDC memDC;
    BITMAP bm;
    RECT re;




    memDC = CreateCompatibleDC(hDC);
    SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
    GetClientRect(hWnd, &re);
    x += 50;
    y += 50;
    StretchBlt(hDC, x, y, anchocarta, altocarta, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
    DeleteDC(memDC);
}*/


void CStretchBltinicio0(HDC hDC0, HWND hWnd0, HBITMAP hBitmap0){

    HDC memDC0;
    BITMAP bm0;
    RECT re0;

    memDC0 = CreateCompatibleDC(hDC0);
    SelectObject(memDC0, hBitmap0);
    GetObject(hBitmap0, sizeof(BITMAP), (LPSTR)&bm0);
    GetClientRect(hWnd0, &re0);
    StretchBlt(hDC0, 800, 320, 232, 360, memDC0, 0, 0, bm0.bmWidth, bm0.bmHeight, SRCCOPY);
    DeleteDC(memDC0);
}

void CStretchBltinicio1(HDC hDC, HWND hWnd, HBITMAP hBitmap){

    HDC memDC;
    BITMAP bm;
    RECT re;

    memDC = CreateCompatibleDC(hDC);
    SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
    GetClientRect(hWnd, &re);
    StretchBlt(hDC, 650, 200, 232, 360, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
    DeleteDC(memDC);
}

void CStretchBltjugador1(HDC hDC, HWND hWnd, HBITMAP hBitmap){

    HDC memDC;
    BITMAP bm;
    RECT re;

    memDC = CreateCompatibleDC(hDC);
    SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
    GetClientRect(hWnd, &re);
    StretchBlt(hDC, 10, 10, 300, 100, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
    DeleteDC(memDC);
}

void CStretchBltjugador2(HDC hDC, HWND hWnd, HBITMAP hBitmap){

    HDC memDC;
    BITMAP bm;
    RECT re;

    memDC = CreateCompatibleDC(hDC);
    SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
    GetClientRect(hWnd, &re);
    StretchBlt(hDC, 500, 10, 300, 100, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
    DeleteDC(memDC);
}

void CStretchBltbanca(HDC hDC, HWND hWnd, HBITMAP hBitmap){

    HDC memDC;
    BITMAP bm;
    RECT re;


    BANCAx = BANCAx + 50;
    BANCAy = BANCAy + 50;

    memDC = CreateCompatibleDC(hDC);
    SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
    GetClientRect(hWnd, &re);
    StretchBlt(hDC, BANCAx, BANCAy, anchocarta, altocarta, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
    DeleteDC(memDC);
}

void CStretchBltayuda(HDC hDC, HWND hWnd, HBITMAP hBitmap){

    HDC memDC;
    BITMAP bm;
    RECT re;


    memDC = CreateCompatibleDC(hDC);
    SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
    GetClientRect(hWnd, &re);
    StretchBlt(hDC, 0, 0, re.right, re.bottom, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
    DeleteDC(memDC);
}
