#include "GraphicsEngine.h"
#include <iostream>
#include <wtypes.h>
#include "D3d12SDKLayers.h"
#include "d3d12.h"


using namespace std;

                                       /* meat and potatoes of the rendering/graphics engine, powered by DX12 */


// constructors and destuctors
GraphicsEngine::GraphicsEngine()
{
}

GraphicsEngine::~GraphicsEngine()
{
}




// when the graphics engine is init(), an array is created that logs the hardware that is available to it.
// then a macro called ARRAYSIZE computes the size of this array
// then 


 // execute when init() in GraphicsEngine class is true.
bool GraphicsEngine::init()

// store driver_types array with three values, a hardware driver, a warp driver, and a reference driver
// they are ordered in terms of performance with driver type hardware ranked first.
{
	D3D_DRIVER_TYPE driver_types[] =
	{
	 D3D_DRIVER_TYPE_HARDWARE, // driver executed on GPU
	 D3D_DRIVER_TYPE_WARP, // driver executed on CPU
	 D3D_DRIVER_TYPE_REFERENCE // worst, slowest performance

	};

// set usigned integer variable num_driver_types = the size of the driver_types array.

	UINT num_driver_types = ARRAYSIZE(driver_types);

// store feature_levels array with directX 12 feature level.

	D3D_FEATURE_LEVEL feature_levels[] =
	{

		D3D_FEATURE_LEVEL_12_0


	};








// needs work do not understand code
// I think it means, that if there exists a driver type, then execute the below code.
// the code below the for statement specifies the device created and the parameter it must take in.

	for(UINT driver_type_index = 0; driver_type_index < num_driver_types;)
	{
		res = D3D12CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels,
			num_feature_levels, D3D12_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_imm_context);
		
		if (SUCCEEDED(res))
			break;
		++driver_type_index;
		

	}


	

	return TRUE;
}

bool GraphicsEngine::release()
{
	return TRUE;
}
