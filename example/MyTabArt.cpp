#include "MyTabArt.h"

wxColour MyTabArt::GetFontColour(bool pageActive, const wxColour& back_color) {
    return wxColour(255,50,50);
}

wxAuiTabArt *MyTabArt::Clone() {
    return new MyTabArt(*this);
}
