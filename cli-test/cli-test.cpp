#include <iostream>
#include <thread>
#include <windows.h>


void task1()
{
    HINSTANCE DLL_TO_TEST = LoadLibrary(L"dll_test1.dll");
}

int main()
{
    HINSTANCE DLL_TO_TEST = LoadLibrary(L"dll_test1.dll");

    std::thread t1(task1);

    // Pause
    system("pause");

    t1.join();
}