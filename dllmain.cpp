// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "il2cpp.h"
#include <Windows.h>
#include <iostream>
#include "IL2CPP/il2cpp_class.h"
using namespace std;
namespace signalis {
    void GetValueStringRoomName() {
        auto camera = il2cpp::camera_get_main();
        std::cout << camera->klass->static_fields << endl;
    }
}
DWORD WINAPI Thread() 
{
    FILE* fp;
    AllocConsole();
    freopen_s(&fp, "CONOUT$", "w", stdout);
    cout << "WELCOME TO MY NEW HACK FOR SIGNALIS!!!" << endl;
    PlayerState_StaticFields st{};
    signalis::GetValueStringRoomName();
    cout << "Sensivity: " << st.sensitivity << std::endl;
    il2cpp::sanity();
    return TRUE;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

