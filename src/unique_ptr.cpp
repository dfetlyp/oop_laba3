#include <iostream>
#include <memory>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// Класс, демонстрирующий RAII с unique_ptr
class FileResource {
    std::unique_ptr<std::FILE, decltype(&std::fclose)> file_;
public:
    explicit FileResource(const char* filename, const char* mode)
        : file_(std::fopen(filename, mode), &std::fclose) {
        if (!file_) {
            throw std::runtime_error("Failed to open file");
        }
        std::cout << "File opened successfully" << std::endl;
    }

    void write(const std::string& text) {
        fputs(text.c_str(), file_.get());
    }
};

void demonstrate_unique_ptr() {
    for (int i = 0; i < 10; ++i) {
        auto unique_int = std::make_unique<int>(42);
        std::cout << "Allocated: " << *unique_int << " at " << unique_int.get() << std::endl;
        // Память автоматически освободится при выходе из области видимости
    }

    // Пример RAII с файлом
    try {
        FileResource file("test.txt", "w");
        file.write("ndkfdjskk");
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    demonstrate_unique_ptr();
    std::cout << "end" << std::endl;
    return 0;
}
