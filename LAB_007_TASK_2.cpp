#include <iostream>

// Шаблонна функція для сортування методом "Вставки"
template <typename T>
void insertionSort(T arr[], int n) {
    // Перебираємо всі елементи масиву, починаючи з другого
    for (int i = 1; i < n; ++i) {
        T key = arr[i]; // Зберігаємо поточний елемент
        int j = i - 1;

        // Переміщуємо всі більші елементи вправо від key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Вставляємо key у відповідне місце
    }
}

// Виведення масиву на екран
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " "; // Виводимо кожен елемент масиву
    }
    std::cout << std::endl;
}

int main() {
    // Приклад використання з різними типами даних

    // Масив цілих чисел
    int intArr[] = { 12, 11, 13, 5, 6 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]); // Обчислюємо розмір масиву
    std::cout << "Original integer array: ";
    printArray(intArr, intSize); // Виводимо початковий масив
    insertionSort(intArr, intSize); // Сортуємо масив
    std::cout << "Sorted integer array: ";
    printArray(intArr, intSize); // Виводимо відсортований масив

    // Масив дійсних чисел
    double doubleArr[] = { 3.1, 2.2, 1.3, 5.4, 4.5 };
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]); // Обчислюємо розмір масиву
    std::cout << "Original double array: ";
    printArray(doubleArr, doubleSize); // Виводимо початковий масив
    insertionSort(doubleArr, doubleSize); // Сортуємо масив
    std::cout << "Sorted double array: ";
    printArray(doubleArr, doubleSize); // Виводимо відсортований масив

    return 0;
}
