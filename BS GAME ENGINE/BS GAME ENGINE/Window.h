#include <Windows.h>




class Window

{
public:
	Window();
	~Window();
	bool Initialize();
	bool Release() {};

protected:
	HWND m_hwnd;


};

