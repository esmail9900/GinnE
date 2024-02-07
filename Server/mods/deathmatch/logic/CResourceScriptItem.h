/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CResourceScriptItem.h
 *  PURPOSE:     Resource server-side script item class
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/

#pragma once

#include "CResourceFile.h"

class CResourceScriptItem : public CResourceFile
{
public:
    CResourceScriptItem(class CResource* resource, const char* szShortName, const char* szResourceFileName, CXMLAttributes* xmlAttributes);
    ~CResourceScriptItem();

    bool Start();
    bool Stop();

private:
};
