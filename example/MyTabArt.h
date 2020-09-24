#ifndef EXAMPLE_MYTABART_H
#define EXAMPLE_MYTABART_H

#include "../tabart.h"

class MyTabArt: public wxAuiGenericTabArt {
public:
    wxColour GetFontColour(bool pageActive, const wxColour& back_color) wxOVERRIDE;
    wxAuiTabArt* Clone() wxOVERRIDE;
};

#endif //EXAMPLE_MYTABART_H
