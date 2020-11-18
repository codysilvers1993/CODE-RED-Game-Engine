#include <stdexcept>
#include "AppWindow.h"
#include <winuser.h>
#include <Windows.h>

/*    

		CODE-RED Game Engine Concept

		A DX12 Rendering Software For Simple 3-D Games

		Below you will find documentation for every step of the software


 */



int main()
{

	    // on startup execute to determine exceptions
	try
	{
		// instantiate object 'app' of class 'AppWindow'

		AppWindow app;

		// during try, execute init() function from object app

		app.init();

		// if the init() function from object app is executing, execute below code.
		if (app.init() == 1)
		{

		// run isRun() function from app constantly, do not stop and if while it is running, execute broadcast()
			while (app.isRun())
			{
				app.broadcast();
			}
		}
	}

	// if the following error is found, execute MessageBox function with following parameters
	// pass through unchanged std algo run_time error which is a referance variable.
	catch (const std::runtime_error& error)
	{

		// if an error is caught executre this message block
		MessageBoxA(nullptr, error.what(), "An error has occured", MB_OK);
	}


	return 0;
}