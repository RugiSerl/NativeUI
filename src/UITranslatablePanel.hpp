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
    UITranslatablePanel(raylib::Rectangle r, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX) : UISelectablePanel(r, Anchor2{LEFT, TOP}, normalStylebox, selectedStylebox), translating(false), translatedPosition(rect.GetPosition()) {};


    // Do children class allow translation ? can be modified at each frame.
    bool allowedToBeTranslated = true;

protected:


    /**
     * @brief
     *
     * @param boundingBox needed to get rect absolute position
     * @return whether the translatable panel can be translated
     */
    bool canBeTranslated(raylib::Rectangle boundingBox);


    /**
     * @brief setup before translation.
     * 
     * @param boundingBox needed to get rect absolute position.
     */
    void beginTranslation(raylib::Rectangle boundingBox);
    

    /**
     * @brief Update variables during translation.
     * 
     * @param boundingBox needed to get rect absolute position.
     */
    void updateTranslation(raylib::Rectangle boundingBox);
    
    
    /**
     * @brief Finalize translation.
     * 
     */
    void endTranslation();


    virtual void update(raylib::Rectangle boundingBox) override;


    raylib::Vector2 translatedPosition; // position that is not restrained by boundingBox, ie panel true position
    bool translating;
    raylib::Vector2 offset;

};

#endif // !__UITRANSLATABLEPANEL__H__
