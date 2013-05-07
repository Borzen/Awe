#include "Instance.h"

Instance::Instance()
{
	m_instanceBuffer = 0;
}


Instance::Instance(const Instance& other)
{
}


Instance::~Instance()
{
}


bool Instance::Initialize(ID3D11Device* device, int numInstances, D3DXVECTOR3* posArray)
{
	bool result;


	// Initialize the vertex and instance buffers.
	result = InitializeBuffers(device,numInstances,posArray);
	if(!result)
	{
		return false;
	}

	// Load the texture for this model.

	return true;
}


void Instance::Shutdown()
{

	// Shutdown the vertex and instance buffers.
	ShutdownBuffers();

	return;
}


void Instance::Render(ID3D11DeviceContext* deviceContext)
{
	// Put the vertex and instance buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}


int Instance::GetInstanceCount()
{
	return m_instanceCount;
}




bool Instance::InitializeBuffers(ID3D11Device* device, int numInstances, D3DXMATRIX* posArray)
{
	MeshInstance* instances;
	D3D11_BUFFER_DESC instanceBufferDesc;
    D3D11_SUBRESOURCE_DATA instanceData;
	HRESULT result;

	// Set the number of instances in the array.
	m_instanceCount = numInstances;

	// Create the instance array.
	instances = new MeshInstance[m_instanceCount];
	if(!instances)
	{
		return false;
	}

	// Load the instance array with data.
	for(int i = 0; i < numInstances; i++){
		instances[i].position.insert(posArray[i]);
	}
	// Set up the description of the instance buffer.
    instanceBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    instanceBufferDesc.ByteWidth = sizeof(MeshInstance) * m_instanceCount;
    instanceBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    instanceBufferDesc.CPUAccessFlags = 0;
    instanceBufferDesc.MiscFlags = 0;
	instanceBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the instance data.
    instanceData.pSysMem = instances;
	instanceData.SysMemPitch = 0;
	instanceData.SysMemSlicePitch = 0;

	// Create the instance buffer.
	result = device->CreateBuffer(&instanceBufferDesc, &instanceData, &m_instanceBuffer);
	if(FAILED(result))
	{
		return false;
	}

	// Release the instance array now that the instance buffer has been created and loaded.
	delete [] instances;
	instances = 0;

	return true;
}


void Instance::ShutdownBuffers()
{
	// Release the instance buffer.
	if(m_instanceBuffer)
	{
		m_instanceBuffer->Release();
		m_instanceBuffer = 0;
	}

	// Release the vertex buffer.
	return;
}


void Instance::RenderBuffers(ID3D11DeviceContext* deviceContext)
{

	return;
}

