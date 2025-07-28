#ifndef __CURSOR_H__
#define __CURSOR_H__
#include "raylib-cpp.hpp"


// state of the cursor for now
static int cursorState = MOUSE_CURSOR_DEFAULT;

// state of the cursor set during the frame
static int frameCursor = MOUSE_CURSOR_DEFAULT;


/**
 * For some obscure reason setting Mouse cursor in my code
 * seems to make my desktop lag, so I decided to limit it
 * to change it when needed.
 * This also serves the purpose of having the cursor only
 * set at the end of the frame so if multiple changes
 * occur only the last will take effect.
 */
void SetCursor(int cursortype);
void UpdateCursorState();


#endif