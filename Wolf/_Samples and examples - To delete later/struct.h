#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED


typedef struct Mouse {
    int MouseX;
    int MouseY;
    int MouseLeftClic;
    int MouseRightClic;
    int MouseWheelUp;
    int MouseWheelDown;
} Mouse;

typedef struct Keyboard {
    int ArrowUp;
    int ArrowLeft;
    int ArrowDown;
    int ArrowRight;
    int Keyz;
    int Keyq;
    int Keys;
    int Keyd;
    int KeySpace;
} Keyboard;

typedef struct User_Input {
    Mouse *pMouse;
    Keyboard *pKeyboard;
} User_Input;

#endif // STRUCT_H_INCLUDED
