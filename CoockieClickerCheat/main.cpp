#include<Windows.h>

#define SPEEPTIMEWAIT 200

void toggleFlag(bool* flag) {
	*flag ? *flag = false : *flag = true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	bool quit = false;
	bool cklick = false;
	int sleepTimer = 8;

	while (!quit) {
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x30)) //Ctrl+0
		{
			quit = true;
		}
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x31)) { //Ctrl+1
			sleepTimer = 1;
			Sleep(SPEEPTIMEWAIT);
		}
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x32)) { //Ctrl+2
			sleepTimer = 2;
			Sleep(SPEEPTIMEWAIT);
		}
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x33)) { //Ctrl+3
			sleepTimer = 4;
			Sleep(SPEEPTIMEWAIT);
		}
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x34)) { //Ctrl+4
			sleepTimer = 8;
			Sleep(SPEEPTIMEWAIT);
		}

		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x20)) { //Ctrl+Space
			toggleFlag(&cklick);
			Sleep(SPEEPTIMEWAIT);
			MessageBeep(NULL);
		}

		if (cklick) {
			INPUT    Input = { 0 };													// Create our input.

			Input.type = INPUT_MOUSE;									// Let input know we are using the mouse.
			Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;							// We are setting left mouse button down.
			SendInput(1, &Input, sizeof(INPUT));								// Send the input.

			ZeroMemory(&Input, sizeof(INPUT));									// Fills a block of memory with zeros.
			Input.type = INPUT_MOUSE;									// Let input know we are using the mouse.
			Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;								// We are setting left mouse button up.
			SendInput(1, &Input, sizeof(INPUT));
		}
		Sleep(sleepTimer);
	}

	return 0;
}