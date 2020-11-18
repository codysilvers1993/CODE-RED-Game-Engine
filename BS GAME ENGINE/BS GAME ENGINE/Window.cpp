
#include "Window.h"
#include <Windows.h>
#include <string.h>
#include <conio.h>

Window::Window()
{

}

//correct this

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);



Window::~Window()
{

}

bool Window::Initialize()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = NULL;
	wc.lpszMenuName = NULL;
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;


	if (!::RegisterClassEx(&wc)); {

		return FALSE;
	}

	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, NULL, NULL, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1074, 768, NULL, NULL, NULL, NULL);

	if (!m_hwnd) {
		return FALSE;
	}

	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	return TRUE;
}


bool Window::Release() {

	if (m_hwnd) {
		::DestroyWindow(m_hwnd);
		return FALSE;
	}

	return true;

}


