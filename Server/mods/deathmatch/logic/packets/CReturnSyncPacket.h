/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/packets/CReturnSyncPacket.h
 *  PURPOSE:     Player return sync packet class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#pragma once

#include "CPacket.h"

class CReturnSyncPacket final : public CPacket
{
public:
    CReturnSyncPacket(class CPlayer* pPlayer);

    ePacketID     GetPacketID() const { return PACKET_ID_RETURN_SYNC; };
    unsigned long GetFlags() const { return PACKET_HIGH_PRIORITY | PACKET_RELIABLE; };

    bool Write(NetBitStreamInterface& BitStream) const;
};
