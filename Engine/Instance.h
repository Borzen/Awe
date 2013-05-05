#ifndef _INSTANCE_H_
#define _INSTANCE_H_

//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dx10math.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: ModelClass
////////////////////////////////////////////////////////////////////////////////
class Instance
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
	    D3DXVECTOR2 texture;
	};

	struct InstanceType
	{
		D3DXVECTOR3 position;
	};

public:
	Instance();
	Instance(const Instance&);
	~Instance();

	bool Initialize(ID3D11Device*, WCHAR*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetVertexCount();
	int GetInstanceCount();
	
private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);


private:
	ID3D11Buffer* m_vertexBuffer;
	ID3D11Buffer* m_instanceBuffer;
	int m_vertexCount;
	int m_instanceCount;
};

#endif