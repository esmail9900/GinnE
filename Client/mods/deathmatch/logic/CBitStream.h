/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/Packets.h
 *  PURPOSE:     Header for bit stream class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#pragma once

#include "..\CClient.h"
extern CNet* g_pNet;

class CBitStream
{
public:
    CBitStream() { pBitStream = g_pNet->AllocateNetBitStream(); };
    ~CBitStream() { g_pNet->DeallocateNetBitStream(pBitStream); };

    NetBitStreamInterface* pBitStream;
};
