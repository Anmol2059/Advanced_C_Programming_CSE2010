#include <windows.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[ ] = "MyWin";

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode){
HWND hwnd;
MSG msg;
WNDCLASSEX wcl;
/* */ wcl.cbSize = sizeof(WNDCLASSEX);
wcl.hInstance = hThisInst;
wcl.lpszClassName = szWinName;
wcl.lpfnWndProc = WindowFunc;
wcl.style = 0;
/* */ wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wcl.hIconSm = NULL;
wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
wcl.lpszMenuName = NULL;
wcl.cbClsExtra = 0;
wcl.cbWndExtra = 0;
/* */ wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
if(!RegisterClassEx(&wcl)) return 0;
hwnd = CreateWindow(szWinName,"My Window Area",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hThisInst,NULL);
ShowWindow(hwnd, nWinMode);
UpdateWindow(hwnd);
while(GetMessage(&msg, NULL, 0, 0)){
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return msg.wParam;
}
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
switch(message){
case WM_DESTROY:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hwnd, message, wParam, lParam);
}
return 0;
}