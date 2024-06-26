#include <iostream>
#include <locale> // Для setlocale

// Клас для вузла однозв'язного списку
template <typename T>
class Node {
public:
    T data;         // Дані, які зберігаються у вузлі
    Node* next;     // Вказівник на наступний вузол

    // Конструктор для ініціалізації даних і вказівника на NULL
    Node(T value) : data(value), next(nullptr) {}
};

// Клас для однозв'язного списку
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;  // Вказівник на перший елемент списку
    int size;       // Розмір списку

public:
    // Конструктор за замовчуванням, який ініціалізує пустий список
    SinglyLinkedList() : head(nullptr), size(0) {}

    // Деструктор для звільнення пам'яті, якщо потрібно
    ~SinglyLinkedList() {
        clear(); // Викликаємо метод очищення списку перед знищенням об'єкта
    }

    // Метод, що додає елемент в кінець списку
    void pushBack(T value) {
        Node<T>* newNode = new Node<T>(value); // Створюємо новий вузол
        if (head == nullptr) {
            head = newNode; // Якщо список порожній, новий вузол стає першим
        }
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next; // Шукаємо останній елемент списку
            }
            current->next = newNode; // Додаємо новий вузол в кінець
        }
        size++; // Збільшуємо розмір списку
    }

    // Метод, що видаляє всі елементи списку
    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current; // Видаляємо поточний вузол
            current = next; // Переходимо до наступного вузла
        }
        head = nullptr; // Встановлюємо вказівник на початок списку в NULL
        size = 0; // Скидаємо розмір списку до 0
    }

    // Метод для виведення елементів списку на екран
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next; // Переходимо до наступного вузла
        }
        std::cout << std::endl;
    }

    // Метод для отримання розміру списку
    int getSize() const {
        return size;
    }
};

int main() {
    // Встановлення української локалізації
    setlocale(LC_CTYPE, "Ukrainian");

    // Приклад використання класу однозв'язного списку з різними типами даних

    // Створення та заповнення списку цілими числами
    SinglyLinkedList<int> list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);
    std::cout << "Список цілих чисел: ";
    list1.display(); // Вивід: 1 2 3
    std::cout << "Розмір списку: " << list1.getSize() << std::endl; // Вивід: 3

    // Створення та заповнення списку рядками
    SinglyLinkedList<std::string> list2;
    list2.pushBack("яблуко");
    list2.pushBack("банан");
    list2.pushBack("вишня");
    std::cout << "Список рядків: ";
    list2.display(); // Вивід: яблуко банан вишня
    std::cout << "Розмір списку: " << list2.getSize() << std::endl; // Вивід: 3

    // Звільнення пам'яті, коли об'єкти list1 та list2 виходять з області видимості

    return 0;
}
