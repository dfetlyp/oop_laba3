#include <iostream>
#include <memory>
#include <vector>

class SharedResource {
public:
    int value;
    SharedResource(int v) : value(v) {
        std::cout << "Resource created: " << value << std::endl;
    }
    ~SharedResource() {
        std::cout << "Resource destroyed: " << value << std::endl;
    }
};

void demonstrate_shared_ptr() {
    auto shared1 = std::make_shared<SharedResource>(42);
    std::cout << "outside block: " << shared1.use_count() << std::endl;
    {
        auto shared2 = shared1;
        std::cout << "inside block: " << shared1.use_count() << std::endl;
        // use_count увеличился до 2
    }
    // После выхода из блока use_count уменьшился до 1

    std::cout << "outside block: " << shared1.use_count() << std::endl;
}

int main() {
    demonstrate_shared_ptr();
    std::cout << "end" << std::endl;
    return 0;
}
