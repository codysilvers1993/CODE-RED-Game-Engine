#include "Window.h"
#include <stdexcept>
#include <sstream>
#include <string.h>
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
Window::Window()
{

}

bool Window::init()
{
	//Setting up WNDCLASSEX object

 // Using {} to initialize a struct sets all fields to 0 in C++

	WNDCLASSEXA wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = GetModuleHandle(nullptr);
	wc.lpszClassName = "My Window Class";
	wc.lpfnWndProc = &WndProc;

	// If the registration of class will fail, the function will return false
	if (!RegisterClassExA(&wc))
		throw std::runtime_error("Failed to register WNDCLASSEX.");

	// When you create a window the dimensions include the non-client area such as the 
	// border and title bar, I'd use the AdjustWindowRectEx API
	RECT rect = { 0,0,1024,768 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_OVERLAPPEDWINDOW);

	const auto width = rect.right - rect.left;
	const auto height = rect.bottom - rect.top;

	//Creation of the window
	m_hwnd = CreateWindowExA(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "DirectX Application", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		height,
		nullptr,
		nullptr,
		nullptr,
		this);

	//if the creation fail return false

	if (!m_hwnd)
		throw std::runtime_error("Failed to initialize Window.");

	//show up the window

	ShowWindow(m_hwnd, SW_SHOW);
	return true;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		// Event fired when the window is created
		// collected here..
		auto* const params = reinterpret_cast<LPCREATESTRUCT>(lparam);
		auto* const window =
			reinterpret_cast<Window* const>(params->lpCreateParams);

		// .. and then stored for later lookup
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
		window->onCreate();
		break;
	}

	case WM_DESTROY:
	{
		// Event fired when the window is destroyed
		auto* const window =
			reinterpret_cast<Window* const>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		window->onDestroy();
		PostQuitMessage(0);
		break;
	}


	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return 0;
}

void Window::broadcast()
{
	MSG msg{};
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	onUpdate();

	Sleep(1);
}

bool Window::isRun()
{
	return m_is_run;
}

void Window::onCreate()
{
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
	m_is_run = false;
}

Window::~Window()
{
	DestroyWindow(m_hwnd);
}