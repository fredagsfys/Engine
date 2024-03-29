#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include "Texture.h"

using namespace DirectX;

class Bitmap
{
private:
	struct VertexType{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	Bitmap();
	Bitmap(const Bitmap&);
	~Bitmap();

	bool Init(ID3D11Device*, int, int, WCHAR*, int, int);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, int, int);

	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

private: 
	bool InitBuffers(ID3D11Device*);
	void ShutdownBuffers();
	bool UpdateBuffers(ID3D11DeviceContext*, int, int);
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTexture(ID3D11Device*, WCHAR*);
	void ReleaseTexture();

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	Texture* m_Texture;

	int m_screenWidth, m_screenHeight;
	int m_bitmapWidth, m_bitmapHeight;
	int m_previousPosX, m_previousPosY;

};

