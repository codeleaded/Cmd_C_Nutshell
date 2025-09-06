#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

    DWORD prevMode;
    GetConsoleMode(hInput, &prevMode);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT);

    INPUT_RECORD input;
    DWORD numRead;
    
    while (1) {
        ReadConsoleInput(hInput, &input, 1, &numRead);

        if (numRead > 0) {
            if (input.EventType == MOUSE_EVENT) {
                MOUSE_EVENT_RECORD mouseEvent = input.Event.MouseEvent;

                if (mouseEvent.dwEventFlags & MOUSE_MOVED) {
                    // Mausbewegung
                    printf("Mausposition: X=%d, Y=%d\n", mouseEvent.dwMousePosition.X, mouseEvent.dwMousePosition.Y);
                }else{
                    printf("Bit: %d : %d : %d : %d\n",input.EventType,mouseEvent.dwButtonState,mouseEvent.dwControlKeyState,mouseEvent.dwEventFlags); 
                }
                if(mouseEvent.dwEventFlags & RI_MOUSE_BUTTON_1_UP){
                    printf("Up\n");  
                }
                if (mouseEvent.dwButtonState & 1) {
                    printf("Bit: 0\n");  
                }
                if (mouseEvent.dwButtonState & 2) {
                    printf("Bit: 1\n");  
                }
                if (mouseEvent.dwButtonState & 4) {
                    printf("Bit: 2\n");  
                }              
                
            } else if (input.EventType == KEY_EVENT && input.Event.KeyEvent.bKeyDown) {
                // Tastendruck
                printf("Taste gedrückt: %c\n", input.Event.KeyEvent.uChar.AsciiChar);

                if(toupper(input.Event.KeyEvent.uChar.AsciiChar)=='Q'){
                    break;
                }
            }
        }
    }
    SetConsoleMode(hInput, prevMode);
    return 0;
}