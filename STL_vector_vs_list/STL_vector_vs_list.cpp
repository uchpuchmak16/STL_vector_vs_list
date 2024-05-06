#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

int main() {
    // c int
    std::vector<int> Vector_int;
    std::list<int> List_int;

    srand(time(NULL));

    for (int i = 0; i < 1000; ++i) {
        Vector_int.push_back(rand() % 1000 + 1); // Генерация чисел от 1 до 1000
    }
    for (int i = 0; i < 1000; ++i) {
        List_int.push_back(rand() % 1000 + 1); // Генерация чисел от 1 до 1000
    }

    //// Печать первых 10 элементов вектора для примера
    //for (int i = 0; i < 10; ++i) {
    //    //std::cout << Vector_int[i] << " " << std::endl;

    //}


    //int count = 0;
    //for (const auto& num : List_int) {
    //    if (count == 10) break;
    //    //std::cout << num << " " ;
    //    count++;
    //}
    std::cout << "Size of vector: " << Vector_int.size() << std::endl;
    std::cout << "Size of list: " << List_int.size() << std::endl;

    std::cout << "Estimated memory usage for vector int: " << sizeof(Vector_int) + sizeof(int) * Vector_int.size() << " bytes\n";
    std::cout << "Estimated memory usage for list int: " << sizeof(List_int) + sizeof(int) * List_int.size() + sizeof(void*) * List_int.size() * 2 << " bytes\n";


    // с double
    std::vector<double> Vector_double;
    std::list<double> List_double;

    srand(time(NULL));

    for (double j = 0; j < 1000; ++j) {
        Vector_double.push_back(rand() % 1000 + 1); // Генерация чисел от 1 до 1000
    }
    for (double j = 0; j < 1000; ++j) {
        List_double.push_back(rand() % 1000 + 1); // Генерация чисел от 1 до 1000
    }

    std::cout << "Estimated memory usage for vector double: " << sizeof(Vector_double) + sizeof(double) * Vector_double.size() << " bytes\n";
    std::cout << "Estimated memory usage for list double: " << sizeof(List_double) + sizeof(double) * List_double.size() + sizeof(void*) * List_double.size() * 2 << " bytes\n";
    return 0;
}
