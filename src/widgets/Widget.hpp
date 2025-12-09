#pragma once

namespace widget {
    class Widget {
    public:
        Widget();

    protected:
        /**
         * Update logic
         */
        void update();

        /**
         * Draw on screen
         */
        void draw();

    private:

    };
}
