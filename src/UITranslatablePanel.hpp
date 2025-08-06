#ifndef __UITRANSLATABLEPANEL__H__
#define __UITRANSLATABLEPANEL__H__
#include "UISelectablePanel.hpp"


/**
 * @brief A Panel allowing translation with mouse movement, when holding left mouse button.
 * This panel will always be anchored from top left, as it doesn't have any fixed position.
 */
class UITranslatablePanel : public UISelectablePanel {
public:


    /**
     * @brief Construct a new UITranslatablePanel object
     *
     * @param r rectangle of the object
     * @param normalStylebox
     * @param selectedStylebox
     */
    UITranslatablePanel(raylib::Rectangle r, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX) : UISelectablePanel(r, Anchor2{LEFT, TOP}, normalStylebox, selectedStylebox), translating(false), virtualRectangle(rect) {};


    bool inResizeZone = false;

protected:


    /**
     * @brief
     *
     * @param boundingBox needed to get rect absolute position
     * @return whether the translatable panel can be translated
     */
    bool canBeTranslated(raylib::Rectangle boundingBox);


    /**
     * @brief setup before translation
     *
     * @param boundingBox needed to get rect absolute position
     */
    void startTranslating(raylib::Rectangle boundingBox);


    /**
     * @brief Update variables during translation
     *
     * @param boundingBox
     */
    void updateTranslating(raylib::Rectangle boundingBox);


    /**
     * @brief Finalize translation.
     *
     */
    void stopTranslating();


    virtual void update(raylib::Rectangle boundingBox) override;


    // Rectangle not bounded by parents when the user is clicking.
    raylib::Rectangle virtualRectangle;

    bool translating;
    raylib::Vector2 offset;

};

#endif // !__UITRANSLATABLEPANEL__H__
