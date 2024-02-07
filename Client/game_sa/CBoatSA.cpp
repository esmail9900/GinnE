/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CBoatSA.cpp
 *  PURPOSE:     Boat vehicle entity
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#include "StdInc.h"
#include "CBoatSA.h"

CBoatSA::CBoatSA(CBoatSAInterface* pInterface)
{
    SetInterface(pInterface);
    Init();
}

CBoatHandlingEntry* CBoatSA::GetBoatHandlingData()
{
    return m_pBoatHandlingData;
}

void CBoatSA::SetBoatHandlingData(CBoatHandlingEntry* pBoatHandling)
{
    if (!pBoatHandling)
        return;
    m_pBoatHandlingData = static_cast<CBoatHandlingEntrySA*>(pBoatHandling);
    GetBoatInterface()->pBoatHandlingData = m_pBoatHandlingData->GetInterface();
}
