#ifndef __TEXT_ENTRY_HPP__
#define __TEXT_ENTRY_HPP__
#include "Panel.hpp"

namespace UIComponent {
    class TextEntry : public Panel 
    {
    public:
        TextEntry(Modifier modifier, LayoutType layout);
        ~TextEntry() = default;
    protected:
        virtual void update() override;
        virtual void draw() override;
    
    private:
        std::string text;
        
    };

}



#endif //__TEXT_ENTRY_HPP__
