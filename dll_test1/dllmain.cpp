// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>


// This here is probably a complex example.
// Regarding refCount
static long refCount = 0;

void RefAdd() {
    InterlockedIncrement(&refCount);
}
void RefRemove() {
    InterlockedDecrement(&refCount);
}


BOOL WINAPI DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
) {
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::cout << "Process Attach!\n" << std::endl;
        RefAdd();
        break;
    case DLL_THREAD_ATTACH:
        std::cout << "Thread Attach!\n" << std::endl;
        RefAdd();
        break;


    case DLL_PROCESS_DETACH:
        std::cout << "Process Detach!\n" << std::endl;
        RefRemove();
        break;
    case DLL_THREAD_DETACH:
        std::cout << "Thread Detach!\n" << std::endl;
        RefRemove();
        break;
    }

    printf("refCount: %d\n", refCount);

    return TRUE;
}