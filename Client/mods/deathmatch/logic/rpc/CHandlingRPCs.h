/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/rpc/CHandlingRPCs.h
 *  PURPOSE:     Header for handling RPC class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#pragma once

#include "CRPCFunctions.h"

class CHandlingRPCs : public CRPCFunctions
{
public:
    static void LoadFunctions();

    DECLARE_ELEMENT_RPC(SetVehicleHandling);
    DECLARE_ELEMENT_RPC(SetVehicleHandlingProperty);
    DECLARE_ELEMENT_RPC(RestoreVehicleHandlingProperty);
    DECLARE_ELEMENT_RPC(RestoreVehicleHandling);
};
