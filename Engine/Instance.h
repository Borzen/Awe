#ifndef _INSTANCE_H_
#define _INSTANCE_H_

//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dx10math.h>
#include <vector>


////////////////////////////////////////////////////////////////////////////////
// Class name: ModelClass
////////////////////////////////////////////////////////////////////////////////
class Instance
{
private:
	struct MeshInstance{

		std::vector<D3DXMATRIX> position;

	};

public:
	Instance();
	Instance(const Instance&);
	~Instance();

	bool Initialize();
	bool Initialize(ID3D11Device*, int, D3DXVECTOR3*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);
	bool UpdatePos(D3DXMATRIX);
	int GetInstanceCount();
	int AddInstance(D3DXMATRIX);
	void setPosition(int, D3DXMATRIX);

	
private:
	bool InitializeBuffers();
	bool InitializeBuffers(ID3D11Device*,int,D3DXMATRIX*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);


private:
	ID3D11Buffer* m_instanceBuffer;
	int m_instanceCount;
};

#endif