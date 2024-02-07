/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        sdk/game/CVisibilityPlugins.h
 *  PURPOSE:     Visibility plugins interface
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#pragma once

#define ATOMIC_ID_FLAG_TWO_VERSIONS_UNDAMAGED   1
#define ATOMIC_ID_FLAG_TWO_VERSIONS_DAMAGED     2

struct RpClump;
struct RwObject;

class CVisibilityPlugins
{
public:
    virtual void SetClumpAlpha(RpClump* pClump, int iAlpha) = 0;
    virtual int  GetAtomicId(RwObject* pAtomic) = 0;
};
