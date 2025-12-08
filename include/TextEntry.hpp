#ifndef __TEXT_ENTRY_HPP__
#define __TEXT_ENTRY_HPP__
#include "Panel.hpp"
#include "font.hpp"

namespace UIComponent {
    class TextEntry : public Panel
    {
    public:
        TextEntry(Modifier modifier, LayoutType layout, graphic::_Font* font);
        ~TextEntry() = default;
    protected:
        virtual void update() override;
        virtual void draw() override;

    private:
        std::string text;
        graphic::_Font* font;

    };

}



#endif //__TEXT_ENTRY_HPP__
