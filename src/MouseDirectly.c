#include <Windows.h>
#include <stdio.h>

int main() {
    // Variable, um den vorherigen Zustand der linken Maustaste zu speichern
    SHORT previousState = 0;

    while (1) {
        // Erstelle eine Struktur für den Mauszustand
        POINT p;
        GetCursorPos(&p);

        // Überprüfe den aktuellen Zustand der linken Maustaste
        SHORT currentState = GetAsyncKeyState(VK_LBUTTON);

        // Überprüfe auf Drücken der linken Maustaste (vom nicht gedrückten in den gedrückten Zustand)
        if ((currentState & 0x8001) && !(previousState & 0x8001)) {
            printf("Linke Maustaste gedrückt!\n");
        }

        // Überprüfe auf Loslassen der linken Maustaste (vom gedrückten in den nicht gedrückten Zustand)
        if (!(currentState & 0x8001) && (previousState & 0x8001)) {
            printf("Linke Maustaste losgelassen!\n");
        }

        // Speichere den aktuellen Zustand für den nächsten Durchlauf
        previousState = currentState;

        // Gib die aktuelle Mausposition aus
        //printf("Mausposition: x=%ld, y=%ld\n", p.x, p.y);

        // Hier kannst du weitere Maustasten oder Mausinformationen hinzufügen

        Sleep(10); // Kurze Pause, um die CPU nicht zu überlasten
    }

    return 0;
}
