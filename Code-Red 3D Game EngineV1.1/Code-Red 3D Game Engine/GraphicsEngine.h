#include <d3d12.h>

class GraphicsEngine
{
public:

	//constructors for graphics engine(implements the DirectX device 12
	GraphicsEngine();
	~GraphicsEngine();
	//initialization function
	bool init();
	// release all resources loaded
	bool release();

private:
	ID3D12Device* m_d3d_device;








};

