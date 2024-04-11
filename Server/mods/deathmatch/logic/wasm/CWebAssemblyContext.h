/*****************************************************************************
 *
 *  PROJECT:     GninE
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/wasm/CWebAssemblyContext.h
 *  PURPOSE:     Resource handler class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#pragma once

#ifndef C_WEB_ASSEMBLY_CONTEXT_HEADER
#define C_WEB_ASSEMBLY_CONTEXT_HEADER

#include <vector>

#include "CResource.h"

#include "WebAssemblyImports.h"

#define C_WASM_EXTERN_TYPE_FUNCTION WASM_EXTERN_FUNC
#define C_WASM_EXTERN_TYPE_GLOBAL   WASM_EXTERN_GLOBAL
#define C_WASM_EXTERN_TYPE_TABLE    WASM_EXTERN_TABLE
#define C_WASM_EXTERN_TYPE_MEMORY   WASM_EXTERN_MEMORY

typedef wasm_engine_t*       CWebAssemblyEngineContext;
typedef wasm_store_t*        CWebAssemblyStoreContext;
typedef wasm_func_callback_t CWebAssemblyCFunction;
typedef wasm_trap_t          CWebAssemblyTrap;
typedef wasm_module_t*       CWebAssemblyModuleContext;
typedef wasm_instance_t*     CWebAssemblyInstanceContext;
typedef wasm_extern_t*       CWebAssemblyExternContext;

typedef std::vector<CWebAssemblyCFunction> CWebAssemblyCFunctionList;
typedef std::vector<CWebAssemblyExternContext>        CWebAssemblyImports;

class CWebAssemblyScript;
typedef std::vector<CWebAssemblyScript*> CWebAssemblyScriptList;

enum class CWebAssemblyLoadState
{
    Succeed,
    Failed
};

struct CWebAssemblyExtern
{
    CWebAssemblyExternContext context;
    wasm_externkind_t         kind;
};

typedef CFastHashMap<SString, CWebAssemblyExtern> CWebAssemblyExternMap;

class CWebAssemblyEngine
{
public:
    CWebAssemblyEngine();
    CWebAssemblyEngine(const CWebAssemblyEngineContext& context);
    ~CWebAssemblyEngine();

    void Build();
    void Destroy();

    void                      SetContext(const CWebAssemblyEngineContext& context);
    CWebAssemblyEngineContext GetContext();

    operator bool();

private:
    CWebAssemblyEngineContext m_pContext;
};

class CWebAssemblyStore
{
public:
    CWebAssemblyStore();
    CWebAssemblyStore(const CWebAssemblyStoreContext& context);
    CWebAssemblyStore(CWebAssemblyEngine* engine);
    ~CWebAssemblyStore();

    void Build(CWebAssemblyEngine* engine);
    void Build();
    void Destroy();

    void                     SetContext(const CWebAssemblyStoreContext& context);
    CWebAssemblyStoreContext GetContext();

    void                SetEngine(CWebAssemblyEngine* engine);
    CWebAssemblyEngine* GetEngine();

    operator bool();

private:
    CWebAssemblyStoreContext m_pContext;

    CWebAssemblyEngine* m_waEngine;
};

class CWebAssemblyContext
{
public:
    CWebAssemblyContext();
    CWebAssemblyContext(CResource* resource);
    ~CWebAssemblyContext();

    void Destroy();

    CWebAssemblyLoadState LoadScriptBinary(const char* binary, const size_t& binarySize);

    CWebAssemblyScriptList& GetScripts();
    void                    ClearScripts();

    void       SetResource(CResource* resource);
    CResource* GetResource();

    CWebAssemblyStore* GetStore();

    static void                InitializeWebAssemblyEngine();
    static void                DeleteWebAssemblyEngine();
    static CWebAssemblyEngine* GetWebAssemblyEngine();

    static bool IsWebAssemblyBinary(const char* binary);

private:
    CResource*         m_pResource;
    CWebAssemblyStore* m_pStore;

    CWebAssemblyScriptList m_lsScripts;
};

class CWebAssemblyScript
{
public:
    CWebAssemblyScript();
    CWebAssemblyScript(CWebAssemblyContext* context);
    ~CWebAssemblyScript();

    void Destroy();

    void CallMainFunction(int32_t argc = 0, char** argv = NULL);

    CWebAssemblyLoadState LoadBinary(const char* binary, const size_t& binarySize);

    CWebAssemblyModuleContext   GetModule();
    CWebAssemblyInstanceContext GetInstance();

    CWebAssemblyExternMap& GetExports();

    CWebAssemblyExtern GetExport(const SString& exportName);

    bool DoesExportExist(const SString& exportName);

    static bool IsExternValid(const CWebAssemblyExtern& waExtern);

private:
    CWebAssemblyContext* m_pContextStore;

    CWebAssemblyModuleContext m_pModule;
    CWebAssemblyInstanceContext m_pInstance;

    CWebAssemblyExternMap m_mpExports;
};

#endif