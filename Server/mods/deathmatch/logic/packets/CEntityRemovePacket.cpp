/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/packets/CEntityRemovePacket.cpp
 *  PURPOSE:     Entity remove packet class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#include "StdInc.h"
#include "CEntityRemovePacket.h"
#include "CElement.h"

bool CEntityRemovePacket::Write(NetBitStreamInterface& BitStream) const
{
    // Write each entity type then id to it
    std::vector<CElement*>::const_iterator iter = m_List.begin();
    for (; iter != m_List.end(); ++iter)
    {
        BitStream.Write((*iter)->GetID());
    }

    return m_List.size() > 0;
}
