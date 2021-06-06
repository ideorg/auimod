#pragma once

#ifdef wxOVERRIDE
    #define new_wxWidgets
#else
    #undef new_wxWidgets
    #define wxOVERRIDE override
#endif

#ifndef wxASCII_STR
    #define wxASCII_STR(s) wxString::FromAscii(s)
#endif

/* global */
#include "wx/propgrid/propgrid.h"
#include "wx/settings.h"
#include "wx/display.h"

enum NavigationKind
{
    Navigation_Tab,
    Navigation_Accel
};

static wxSize FromDIP(const wxSize& sz, const wxWindowBase* w)
{
#ifdef new_wxWidgets
    return w->FromDIP(sz);
#else
    return wxSize(sz.x, sz.y);
#endif
}

static wxPoint FromDIP(const wxPoint& pt, const wxWindowBase* w)
{
    const wxSize sz = FromDIP(wxSize(pt.x, pt.y), w);
    return wxPoint(sz.x, sz.y);
}
static int FromDIP(int d, const wxWindowBase* w)
{
    return FromDIP(wxSize(d, 0), w).x;
}

static double GetLuminance(const wxColour &c)
{
    return (0.299*c.Red() + 0.587*c.Green() + 0.114*c.Blue()) / 255.0;
}

static bool IsUsingDarkBackground()
{
    const wxColour bg = wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW);
    const wxColour fg = wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT);

    // The threshold here is rather arbitrary, but it seems that using just
    // inequality would be wrong as it could result in false positivies.
    return GetLuminance(fg) - GetLuminance(bg) > 0.2;
}

#undef new_wxWidgets