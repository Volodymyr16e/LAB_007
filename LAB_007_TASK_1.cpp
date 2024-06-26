#include <iostream>
#include <cstring> // Потрібно для функції strcmp

// Шаблонна функція для знаходження мінімального елемента
template <typename T>
T minElement(T a, T b) {
    return (a < b) ? a : b;
}

// Шаблонна функція для знаходження максимального елемента
template <typename T>
T maxElement(T a, T b) {
    return (a > b) ? a : b;
}

// Специфікація шаблонної функції для типу char*
template <>
const char* minElement<const char*>(const char* a, const char* b) {
    // Використовуємо strcmp для порівняння рядків
    return (std::strcmp(a, b) < 0) ? a : b;
}

// Специфікація шаблонної функції для типу char*
template <>
const char* maxElement<const char*>(const char* a, const char* b) {
    // Використовуємо strcmp для порівняння рядків
    return (std::strcmp(a, b) > 0) ? a : b;
}

int main() {
    // Приклад використання шаблонних функцій з різними типами даних
    std::cout << "Min of 3 and 7: " << minElement(3, 7) << std::endl;
    std::cout << "Max of 3.5 and 2.1: " << maxElement(3.5, 2.1) << std::endl;

    // Приклад використання шаблонних функцій з char*
    const char* str1 = "apple";
    const char* str2 = "orange";
    std::cout << "Min of 'apple' and 'orange': " << minElement(str1, str2) << std::endl;
    std::cout << "Max of 'apple' and 'orange': " << maxElement(str1, str2) << std::endl;

    return 0;
}
