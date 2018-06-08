// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>
#include <fstream>
#include <cmath>

#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
int Lenght1 = 150;
int Lenght2 = 100;
int N = 1;
int value = N;
double pi = 3.1415926535897;
double T = 0;
double A = 0;
double Delay = 0.05;
int Angle1 = 0;
int Angle2 = 0;
int Angle1_saved = 0;
int Angle2_saved= 0;
bool repaint=true;
bool animation = false;
// buttons
HWND hwndButton;

// sent data
RECT drawArea1 = { 0, 101, 1500, 500 };
RECT drawArea2 = { 750, 0, 1200, 100};

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen2(Color(255, 0, 255, 0));
	Pen pen3(Color(255, 255, 0, 0));
	if (animation) {
		//Point first(T * (data[value].X - N), A*(data[value].Y) + 450);
		// second(T * (data[value + 1].X - N), A*(data[value + 1].Y)+450);
		//Point anglex(50 * cos(ax[value+1]), 50 * sin(ax[value+1]));
		//Point angley(50 * cos(ay[value + 1]), 50 * sin(ay[value + 1]));
		//Point anglez(50 * cos(az[value + 1]), 50 * sin(az[value + 1]));
		//graphics.DrawLine(&pen,first.X, first.Y, second.X, second.Y);
		//graphics.DrawLine(&pen, 800, 50, 850, 50);
		//graphics.DrawLine(&pen, 800, 50, 800+anglex.X, 50-anglex.Y);
		//graphics.DrawLine(&pen2, 940, 50, 990, 50);
		//graphics.DrawLine(&pen2, 940, 50, 940 + angley.X, 50 - angley.Y);
		//graphics.DrawLine(&pen3, 1080, 50, 1130, 50);
		//graphics.DrawLine(&pen3, 1080, 50, 1080 + anglez.X, 50 - anglez.Y);
		//if (value % 25 ==0 ) {
			//graphics.DrawLine(&pen, T*(data[value].X-N), 455, T*(data[value].X-N), 465);
			//graphics.DrawLine(&pen, 0, 460, 1500, 460);
		//}

		/*for (; Angle1_saved == Angle1; Angle1++){
			for (; Angle2_saved == Angle2; Angle2++){
				Point first1(T*400,A* 400);
				Point second1(T*cos(Angle1*pi / 18) * Lenght1, A*sin(Angle1*pi / 18) * Lenght1);
				graphics.DrawLine(&pen2, first1.X, first1.Y, 400 + second1.X, 400 - second1.Y);
				Point first2(T*cos(Angle1*pi / 18) * Lenght1, A*sin(Angle1*pi / 18) * Lenght1); //same as second1
				Point second2(T*cos((Angle1 + Angle2)*pi / 18) * Lenght2,A*sin((Angle1 + Angle2)*pi / 18) * Lenght2);
				graphics.DrawLine(&pen2, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);
			}
			
		}*/
		//Arm1
		if ((Angle1 + T) == Angle1_saved){
			Point first1(400, 400);
			Point second1(cos(Angle1*pi / 18) * Lenght1, sin(Angle1*pi / 18) * Lenght1);
			graphics.DrawLine(&pen, first1.X, first1.Y, 400 + second1.X, 400 - second1.Y);
			}
		if ((Angle1 + T) > Angle1_saved){
			Point first1(400, 400);
			Point second1(cos((T+Angle1)*pi / 18) * Lenght1, sin((T+Angle1)*pi / 18) * Lenght1);
			graphics.DrawLine(&pen, first1.X, first1.Y, 400 + second1.X, 400 - second1.Y);
			T=T-Delay;
		}
		if ((Angle1 + T) < Angle1_saved){
			Point first1(400, 400);
			Point second1(cos((T + Angle1)*pi / 18) * Lenght1, sin((T + Angle1)*pi / 18) * Lenght1);
			graphics.DrawLine(&pen, first1.X, first1.Y, 400 + second1.X, 400 - second1.Y);
			T=T+Delay;
		}
			
		//Arm2
		if ((Angle2 + A) == Angle2_saved){
			Point first2(cos((T + Angle1)*pi / 18) * Lenght1, sin((T + Angle1)*pi / 18) * Lenght1); //same as second1
			Point second2(cos((Angle1 + Angle2+T)*pi / 18) * Lenght2, sin((Angle1 + Angle2+T)*pi / 18) * Lenght2);
			graphics.DrawLine(&pen, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);

		}
		if ((Angle2 + A) > Angle2_saved){
			Point first2(cos((T + Angle1)*pi / 18) * Lenght1, sin((T + Angle1)*pi / 18) * Lenght1); //same as second1
			Point second2(cos((Angle1 + Angle2+A+T)*pi / 18) * Lenght2, sin((Angle1 + Angle2+A+T)*pi / 18) * Lenght2);
			graphics.DrawLine(&pen, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);
			A = A - Delay;
		}
		if ((Angle2 + A) < Angle2_saved){
			Point first2(cos((T + Angle1)*pi / 18) * Lenght1, sin((T + Angle1)*pi / 18) * Lenght1); //same as second1
			Point second2(cos((Angle1 + Angle2+A+T)*pi / 18) * Lenght2, sin((Angle1 + Angle2+A+T)*pi / 18) * Lenght2);
			graphics.DrawLine(&pen, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);
			A = A + Delay;
		}
		
	}
	else 
	{	
		Angle1 = Angle1 + T;
		T = 0;
		Angle2 = Angle2 + A;
		A = 0;
		Point first1(400,400);
		Point second1(cos(Angle1*pi / 18) * Lenght1, sin(Angle1*pi / 18) * Lenght1);
		graphics.DrawLine(&pen,first1.X,first1.Y,400+second1.X,400-second1.Y);
		Point first2(cos(Angle1*pi / 18) * Lenght1, sin(Angle1*pi / 18) * Lenght1); //same as second1
		Point second2(cos((Angle1 + Angle2)*pi / 18) * Lenght2, sin((Angle1 + Angle2)*pi / 18) * Lenght2);
		graphics.DrawLine(&pen, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);
		Point Box1(220, 380);
		graphics.DrawRectangle(&pen2, Box1.X, Box1.Y, 20, 20);
		Point Box2(290, 380);
		graphics.DrawRectangle(&pen2, Box2.X, Box2.Y, 20, 20);
		Point Box3(340, 380);
		graphics.DrawRectangle(&pen2, Box3.X, Box3.Y, 20, 20);
		Point Box4(490, 380);
		graphics.DrawRectangle(&pen2, Box4.X, Box4.Y, 20, 20);
		Point Box5(560, 380);
		graphics.DrawRectangle(&pen2, Box5.X, Box5.Y, 20, 20);
		Point Box6(600, 380);
		graphics.DrawRectangle(&pen2, Box6.X, Box6.Y, 20, 20);
	}
}
void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (repaint)
		InvalidateRect(hWnd, drawArea, TRUE); // repaint all
	else
		InvalidateRect(hWnd, drawArea, FALSE); //repaint drawArea
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc);
	EndPaint(hWnd, &ps);
}

int OnCreate(HWND window)
{
	return 0;
}


// main function (exe hInstance)
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);



	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance; // Store instance handle (of exe) in our global variable

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle                                                       
	
	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Lewo"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Prawo"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		140, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Lewo2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		230, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON3,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Prawo2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		320, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON4,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

/*	hwndButton = CreateWindow(TEXT("button"),    // The class name required is button
		TEXT("Automat"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		410, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON5,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Recznie"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		500, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON6,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);     */                          // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Zapis"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		590, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON7,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	// create button and store the handle                                                       

	hwndButton = CreateWindow(TEXT("button"), TEXT("Auto ON"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		40, 560, 100, 30, hWnd, (HMENU)ID_RBUTTON1, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("Auto OFF"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		40, 595, 100, 30, hWnd, (HMENU)ID_RBUTTON2, GetModuleHandle(NULL), NULL);

	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window (low priority)
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// MENU & BUTTON messages
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON1 :
			repaint = true;
			if (Angle1 < 18 && Angle1 >= 0)
				Angle1++;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON2:
			repaint = true;
			if (Angle1 <= 18 && Angle1 > 0)
				Angle1--;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON3:
			repaint = true;
			if (Angle2 < 18 && Angle2 >= -18)
				Angle2++;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		case ID_BUTTON4:
			repaint = true;
			if (Angle2 <= 18 && Angle2 > -18)
				Angle2--;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
	/*	case ID_BUTTON5:
			repaint = true;
			value = N;
			T = 1;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON6:
			repaint = true;
			value = N;
			T = 2;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;*/
		case ID_BUTTON7:
			repaint = true;
			Angle1_saved = Angle1;
			Angle2_saved = Angle2;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_RBUTTON1:
			animation = true;
			SetTimer(hWnd, TMR_1, 25, 0);
			break;
		case ID_RBUTTON2:
			animation = false;
			KillTimer(hWnd, TMR_1);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here (not depend on timer, buttons)
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			//force window to repaint
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			repaint = true;
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			repaint = false;
			value++;
			if(value==1140){
				value = N;
				repaint = true;
			}
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
