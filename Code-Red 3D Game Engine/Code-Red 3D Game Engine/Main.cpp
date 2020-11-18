#include <stdexcept>
#include "AppWindow.h"
#include <winuser.h>
#include <Windows.h>

/*

		CODE-RED Game Engine Concept

		A DIRECT X RENDERING SYSTEM


*/



int main()
{

	// on startup execute to determine exceptions
	try
	{
		// instantiate object app of class AppWindow
		AppWindow app;

		app.init();

		// if(initialize function in class app is executed, and while the app is running, broadcast app)
		if (app.init() == 1)
		{
			while (app.isRun())
			{
				app.broadcast();
			}
		}
	}

	// if the following error is found, execute MessageBox function with following parameters
	catch (const std::runtime_error& error)
	{

		// parameters(has no owner window so displays independently, 
		MessageBoxA(nullptr, error.what(), "An error has occured", MB_OK);
	}


	return 0;
}