#ifndef __UIRESIZABLEPANEL_H__
#define __UIRESIZABLEPANEL_H__
#include "UITranslatablePanel.hpp"

enum resizableDirections {
    RESIZABLE_NORTH = 0,
    RESIZABLE_SOUTH = 1,
    RESIZABLE_EAST = 2,
    RESIZABLE_WEST = 4,
};


class UIResizablePanel : public UITranslatablePanel {

};


#endif // !__UIRESIZABLEPANEL_H__