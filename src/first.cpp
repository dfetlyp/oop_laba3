#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    for (int i = 0; i < 10; ++i) {
        int* a = new int(42);  // Выделяем память
        std::cout << "Allocated: " << *a << " at " << a << std::endl;
    }
}
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    for (int i = 0; i < 10; ++i) {
        int* a = new int(42);  // Выделяем память
        std::cout << "Allocated: " << *a << " at " << a << std::endl;
    }
}
