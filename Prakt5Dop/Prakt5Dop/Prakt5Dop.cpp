// Prakt5Dop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct EventSystem {
    void (*handlers[100])();
    int count = 0;
};
void onUserLogin() {
    std::cout << "Пользователь вошёл в систему" << std::endl;
};
void onUserLogout() {
    std::cout << "Пользователь вышел из системы" << std::endl;
};
void onError() {
    std::cout << "Произошла ошибка" << std::endl;
};
void registerHandler(EventSystem& system, void(*handler)()) {
    system.handlers[system.count] = handler;
    system.count += 1;
}
void triggerEvent(const EventSystem& system){
    for (int i = 0; i < 3; i++) {
        system.handlers[i]();
    }
}
int main()
{
    setlocale(0, "rus");
    EventSystem system;
    registerHandler(system, &onUserLogin);
    registerHandler(system, &onUserLogout);
    registerHandler(system, &onError);
    triggerEvent(system);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
