/*****************************************************************************
 *
 *  PROJECT:     GninE
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/wasm/CWebAssemblyVariable.h
 *  PURPOSE:     Resource handler class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#pragma once

#ifndef C_WEB_ASSEMBLY_ARG_READER
#define C_WEB_ASSEMBLY_ARG_READER

#include "WebAssemblyImports.h"
#include "lua/CLuaFunctionParseHelpers.h"
#include "lua/CLuaMain.h"

class CWebAssemblyScript;

class CWebAssemblyArgReader
{
public:
    CWebAssemblyArgReader();
    CWebAssemblyArgReader(void* env, const CWebAssemblyValueVector* args, CWebAssemblyValueVector* results);
    ~CWebAssemblyArgReader() = default;

    bool NextIsInt32();
    bool NextIsUInt32();
    bool NextIsInt64();
    bool NextIsUInt64();
    bool NextIsFloat32();
    bool NextIsFloat64();
    bool NextIsString();
    bool NextIsPointer();
    bool NextIsBoolean();
    bool NextIsPointerAddress();
    bool NextIsUserData();

    void ReadInt32(int32_t& out, int32_t defaultValue = 0);
    void ReadUInt32(uint32_t& out, uint32_t defaultValue = 0);
    void ReadInt64(int64_t& out, int64_t defaultValue = 0);
    void ReadUInt64(uint64_t& out, uint64_t defaultValue = 0);
    void ReadFloat32(float32_t& out, float32_t defaultValue = 0.0f);
    void ReadFloat64(float64_t& out, float64_t defaultValue = 0);
    void ReadString(SString& out, SString defaultValue = "", intptr_t size = -1);
    void ReadBoolean(bool& out, bool defaultValue = false);
    void ReadPointerAddress(CWebAssemblyMemoryPointerAddress& out, CWebAssemblyMemoryPointerAddress defaultValue = WEB_ASSEMBLY_NULL_PTR);

    template<typename PTR>
    void ReadPointer(PTR*& out, PTR* defaultValue = NULL)
    {
        if (!Skip())
        {
            out = defaultValue;
            return;
        }

        CWebAssemblyValue arg = m_pArgs->data[m_iIndex];

        if (arg.kind != C_WASM_VARIABLE_TYPE_I32)
        {
            out = defaultValue;
            return;
        }

        CWebAssemblyMemoryPointerAddress ptr = arg.of.i32;

        if (ptr == WEB_ASSEMBLY_NULL_PTR)
        {
            out = defaultValue;
            return;
        }

        out = (PTR*)(m_pScript->GetMemory()->GetMemoryPhysicalPointer(ptr));
    }

    template<typename PTR>
    void ReadUserData(PTR*& out, PTR* defaultValue = NULL)
    {
        CWebAssemblyUserData userdata;

        #if IS_APP_ON_64_BIT_VERSION
            ReadInt64(userdata);
        #else
            ReadInt32(userdata);
        #endif

        if (!userdata)
        {
            out = defaultValue;
            return;
        }

        PTR* udata = (PTR*)(void*)userdata;

        // to use `UserDataCast` check how they did pass elements to luaVM!
        // i saw the pointer address and the element id is different
        // i need to pass the element data when pushing userdata with `ReturnUserData`
        /*lua_State* luaVM = m_pScript->GetStoreContext()->GetResource()->GetVirtualMachine()->GetVM();
        PTR* udata = (PTR*)UserDataCast(*((PTR**)(void*)userdata), luaVM);*/ 

        if (!udata)
        {
            out = defaultValue;
            return;
        }

        out = udata;
    }

    template<typename PTR>
    void WritePointer(void* ptr, PTR* value, intptr_t size = sizeof(PTR))
    {
        if (!ptr)
        {
            return;
        }

        if (!value)
        {
            return;
        }

        memcpy(ptr, (void*)value, size);
    }

    template <typename PTR>
    void WritePointer(CWebAssemblyMemoryPointerAddress ptr, PTR* value, intptr_t size = sizeof(PTR))
    {
        if (ptr == WEB_ASSEMBLY_NULL_PTR)
        {
            return;
        }

        if (!value)
        {
            return;
        }

        memcpy(m_pScript->GetMemory()->GetMemoryPhysicalPointer(ptr), (void*)value, size);
    }

    CWebAssemblyTrap* Return(const int32_t& value, SString errorMessage = "");
    CWebAssemblyTrap* Return(const uint32_t& value, SString errorMessage = "");
    CWebAssemblyTrap* Return(const int64_t& value, SString errorMessage = "");
    CWebAssemblyTrap* Return(const uint64_t& value, SString errorMessage = "");
    CWebAssemblyTrap* Return(const float32_t& value, SString errorMessage = "");
    CWebAssemblyTrap* Return(const float64_t& value, SString errorMessage = "");
    CWebAssemblyTrap* Return(const SString& value, SString errorMessage = "");
    CWebAssemblyTrap* Return(const bool& value, SString errorMessage = "");

    template<typename PTR>
    CWebAssemblyTrap* Return(PTR* ptr, intptr_t size = -1, SString errorMessage = "")
    {
        if (!ptr || size == 0)
        {
            m_pResults->data[0].kind = C_WASM_VARIABLE_TYPE_I32;
            m_pResults->data[0].of.i32 = WEB_ASSEMBLY_NULL_PTR;

            return CreateTrap(errorMessage);
        }

        if (size == -1)
        {
            size = sizeof(PTR);
        }

        void* realPtr = NULL;

        CWebAssemblyMemoryPointerAddress ptrAddress = m_pScript->GetMemory()->Malloc(size, &realPtr);

        if (!realPtr)
        {
            m_pResults->data[0].kind = C_WASM_VARIABLE_TYPE_I32;
            m_pResults->data[0].of.i32 = WEB_ASSEMBLY_NULL_PTR;

            return CreateTrap(errorMessage);
        }

        memcpy(realPtr, (void*)ptr, size);

        m_pResults->data[0].kind = C_WASM_VARIABLE_TYPE_I32;
        m_pResults->data[0].of.i32 = ptrAddress;

        return CreateTrap(errorMessage);
    }

    template<typename PTR>
    CWebAssemblyTrap* ReturnUserData(PTR* userData, SString errorMessage = "")
    {
        return Return((CWebAssemblyUserData)(void*)(CWebAssemblyUserData*)userData, errorMessage);
    }

    bool Skip();
    void Reset();

    bool CanContinue();

    CWebAssemblyTrap* CreateTrap(const SString& errorMessage);

    void                SetScript(CWebAssemblyScript* script);
    CWebAssemblyScript* GetScript();

    void    SetFunctionName(const SString& functionName);
    SString GetFunctionName();

    void    SetError(const SString& error);
    bool    HasError();
    SString GetError();

    void SetIndex(const int& index);
    int  GetIndex();

    CWebAssemblyValueVector* GetArguments();
    CWebAssemblyValueVector* GetResults();
    size_t                   GetArgumentCount();

    bool IsValid();

    operator bool();

private:
    CWebAssemblyScript* m_pScript;
    SString             m_strFunctionName;

    SString m_strError;

    int m_iIndex;

    CWebAssemblyValueVector* m_pArgs;
    CWebAssemblyValueVector* m_pResults;
};

#endif
