/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        sdk/gui/CGUIWebBrowser.h
 *  PURPOSE:     Web browser widget interface
 *
 *  GninE is available from http://www.gnine.com/
 *
 *****************************************************************************/
#pragma once

#include "CGUIElement.h"
#include "CGUITexture.h"

class CGUIWebBrowser : public CGUIElement
{
public:
    virtual ~CGUIWebBrowser(){};

    virtual void LoadFromWebView(class CWebViewInterface* pWebView) = 0;

    virtual void SetFrameEnabled(bool bFrameEnabled) = 0;
    virtual bool IsFrameEnabled() = 0;

    virtual void Render() = 0;
};
