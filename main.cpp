#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

int main() {
    
    std::cout << "Welcome to Plutonium Zombie Cheat, press any key when you're ready and the game has started \n";
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
        LPVOID health_address = (LPVOID)0x021C1568;
        LPVOID first_gun_address = (LPVOID)0x02342BCC;
        LPVOID second_gun_address = (LPVOID)0x02342BD4;
        LPVOID fov_address = (LPVOID)0x02A139C0;
        int second_gun_ammo = 999999;
        float fov = 120;
        int cash = 999999;
        int health = 999;
        int first_gun_ammo = 999999;
        DWORD first_gun_offset = sizeof(first_gun_ammo);
        DWORD second_gun_offset = sizeof(second_gun_ammo);
        DWORD health_offset = sizeof(health);
        DWORD fov_offset = sizeof(fov);
        DWORD cash_offset = sizeof(cash);
        
        if (WriteProcessMemory(hProc, cash_address, &cash, cash_offset, NULL) && WriteProcessMemory(hProc, fov_address, &fov, fov_offset, NULL)){
            std::cout << "Cash set to: " + std::to_string(cash) << std::endl;
            std::cout << "FOV set to: " + std::to_string(fov) << std::endl;
                    
            do
            {
                WriteProcessMemory(hProc, health_address, &health, health_offset, NULL);
                WriteProcessMemory(hProc, first_gun_address, &first_gun_ammo, first_gun_offset, NULL);
                WriteProcessMemory(hProc, second_gun_address, &second_gun_ammo, second_gun_offset, NULL);


            } while (hProc);
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
