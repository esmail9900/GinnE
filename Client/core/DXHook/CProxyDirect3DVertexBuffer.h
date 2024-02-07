/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:
 *  PURPOSE:
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

DEFINE_GUID(CProxyDirect3DVertexBuffer_GUID, 0x128A025E, 0x0100, 0x04F1, 0x40, 0x60, 0x53, 0x19, 0x44, 0x56, 0x59, 0x42);

class CProxyDirect3DVertexBuffer : public IDirect3DVertexBuffer9
{
public:
    /*** IUnknown methods ***/
    HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObj);
    ULONG __stdcall AddRef() { return m_pOriginal->AddRef(); }
    ULONG __stdcall Release();

    /*** IDirect3DResource9 methods ***/
    HRESULT __stdcall GetDevice(IDirect3DDevice9** ppDevice) { return m_pOriginal->GetDevice(ppDevice); }
    HRESULT __stdcall SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
    {
        return m_pOriginal->SetPrivateData(refguid, pData, SizeOfData, Flags);
    }
    HRESULT __stdcall GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData) { return m_pOriginal->GetPrivateData(refguid, pData, pSizeOfData); }
    HRESULT __stdcall FreePrivateData(REFGUID refguid) { return m_pOriginal->FreePrivateData(refguid); }
    DWORD __stdcall SetPriority(DWORD PriorityNew) { return m_pOriginal->SetPriority(PriorityNew); }
    DWORD __stdcall GetPriority() { return m_pOriginal->GetPriority(); }
    void __stdcall PreLoad() { return m_pOriginal->PreLoad(); }
    D3DRESOURCETYPE __stdcall GetType() { return m_pOriginal->GetType(); }

    /*** IDirect3DVertexBuffer9 methods ***/
    HRESULT __stdcall Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags);
    HRESULT __stdcall Unlock() { return m_pOriginal->Unlock(); }
    HRESULT __stdcall GetDesc(D3DVERTEXBUFFER_DESC* pDesc) { return m_pOriginal->GetDesc(pDesc); }

    // CProxyDirect3DVertexBuffer
    CProxyDirect3DVertexBuffer(IDirect3DDevice9* InD3DDevice9, IDirect3DVertexBuffer9* InOriginal, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool);
    virtual ~CProxyDirect3DVertexBuffer();

    IDirect3DVertexBuffer9* GetOriginal() { return m_pOriginal; }
    HRESULT                 DoLock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags);

protected:
    IDirect3DVertexBuffer9*                 m_pOriginal;
    uint                                    m_iMemUsed;
    DWORD                                   m_dwUsage;
    DWORD                                   m_dwFVF;
    D3DPOOL                                 m_pool;
    CProxyDirect3DDevice9::SResourceMemory& m_stats;
};
