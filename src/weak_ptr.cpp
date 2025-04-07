#include <iostream>
#include <memory>

class Data {
public:
    Data(int val) : value(val) {
        std::cout << "Data created: " << value << std::endl;
    }

    ~Data() {
        std::cout << "Data destroyed" << std::endl;
    }

    void print() const {
        std::cout << "Data: " << value << std::endl;
    }

private:
    int value;
};

class Cache {
    std::weak_ptr<Data> cached_;  // ссылка не продлевает жизнь Data
public:
    void remember(std::shared_ptr<Data> data) {
        cached_ = data;
    }

    void useIfAlive() {
        if (auto shared = cached_.lock()) {
            std::cout << "[Cache] data alive" << std::endl;
            shared->print();
        }
        else {
            std::cout << "[Cache] data dead((" << std::endl;
        }
    }
};

int main() {
    Cache cache;
    {
        auto data = std::make_shared<Data>(42);
        cache.remember(data);       // Кэшируем объект
        cache.useIfAlive();         // Должен сработать
    } // data уничтожается здесь

    cache.useIfAlive();             // Проверим, жив ли объект

    return 0;
}
