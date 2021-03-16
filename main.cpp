#include <Windows.h>
#include <iostream>
#include <stdio.h>

int main() {
    
    printf("Welcome to Plutonium Zombie Cheat, press any key when you're ready and the game has started \n");
    system("pause");
    LPCUWSTR gameWindow = L"bin\\plutonium-bootstrapper-win32.exe";
    HWND hWnd = FindWindow(0, gameWindow);
    DWORD pId;
    if (hWnd == 0) {
        std::cout << "Cannot find window." << std::endl;
        system("pause");
        exit(-1);
    }
    GetWindowThreadProcessId(hWnd, &pId);
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
    if (hProc) {
        
        LPVOID cash_address = (LPVOID)0x02347D68;
        DWORD offset = sizeof(999999);
        int gay = 999999;
        if (WriteProcessMemory(hProc, cash_address, &gay, offset, NULL)){
            std::cout << "based\n";
        }
        else {
            std::cerr << "Couldn't read process memory:" << GetLastError() << std::endl;
        }
        
    }
    else {
        std::cerr << "Couldn't open process " << pId << ": " << GetLastError() << std::endl;
    }

    std::getchar();
    


    
}