/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CHandlingManager.h
 *  PURPOSE:     Header file for vehicle handling manager class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

class CHandlingManager;

#pragma once

#include "CHandlingEntry.h"
#include "CCommon.h"

class CHandlingManager
{
public:
    CHandlingManager();
    ~CHandlingManager();

    CHandlingEntry* CreateHandlingData();

    bool ApplyHandlingData(eVehicleTypes eModel, CHandlingEntry* pEntry);

    const CHandlingEntry* GetModelHandlingData(eVehicleTypes eModel);
    const CHandlingEntry* GetOriginalHandlingData(eVehicleTypes eModel);

    eHandlingTypes GetHandlingID(eVehicleTypes eModel);

    // Helper functions
    eHandlingProperty GetPropertyEnumFromName(std::string strName);
    bool              HasModelHandlingChanged(eVehicleTypes eModel);
    void              SetModelHandlingHasChanged(eVehicleTypes eModel, bool bChanged);

    std::map<std::string, eHandlingProperty> m_HandlingNames;

private:
    void InitializeDefaultHandlings();

    // Original handling data unaffected by handling.cfg changes
    static SFixedArray<tHandlingData, HT_MAX> m_OriginalHandlingData;

    // Array with the original handling entries
    static SFixedArray<CHandlingEntry*, HT_MAX> m_pOriginalEntries;

    // Array with the model handling entries
    static SFixedArray<CHandlingEntry*, HT_MAX> m_pModelEntries;

    SFixedArray<bool, HT_MAX> m_bModelHandlingChanged;
};
