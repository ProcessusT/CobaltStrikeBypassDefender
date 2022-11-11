#include <iostream>
#include <Windows.h>

typedef int (__cdecl *main_pfn)(int argc, char *argv[]);


int main(int argc, char *argv[]) {
  HMODULE hMod = LoadLibrary("shellcode.dll");
  if (hMod == nullptr) {
    std::cout << "Failed to load shellcode.dll" << std::endl;
  }
  main_pfn MyMain = (main_pfn)
  GetProcAddress (hMod, "RunThatShit");

  if (MyMain != nullptr)
    return MyMain (argc, argv);
  return 0;
}
