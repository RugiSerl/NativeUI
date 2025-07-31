#ifndef __UITRANSLATABLEPANEL__H__
#define __UITRANSLATABLEPANEL__H__
#include "UISelectablePanel.hpp"

/**
 * @brief A Panel allowing translation with mouse movement, when holding left mouse button.
 * This panel will always be anchored from top left, as it doesn't have any fixed position.
 */
class UITranslatablePanel : public UISelectablePanel {
public:
    bool allowedToBeTranslated = true;

    /**
     * @brief Construct a new UITranslatablePanel object
     *
     * @param r rectangle of the object
     * @param normalStylebox
     * @param selectedStylebox
     */
    UITranslatablePanel(raylib::Rectangle r, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX) : UISelectablePanel(r, Anchor2{LEFT, TOP}, normalStylebox, selectedStylebox), translating(false), translatedPosition(rect.GetPosition()) {};

protected:
    raylib::Vector2 translatedPosition; // position that is not restrained by boundingBox, ie panel true position
    bool translating;
    raylib::Vector2 offset;

    /**
     * @brief
     *
     * @param boundingBox needed to get rect absolute position
     * @return whether the translatable panel can be translated
     */
    bool canBeTranslated(raylib::Rectangle boundingBox);

    virtual void update(raylib::Rectangle boundingBox) override;

};

#endif // !__UITRANSLATABLEPANEL__H__
