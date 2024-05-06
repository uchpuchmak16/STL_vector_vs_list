#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <chrono>

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

    // Измерение времени для vector int
    auto start_vector = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < sizeof(Vector_int); ++i) {
        Vector_int.push_back(i);
    }
    for (int i = 0; i < sizeof(Vector_int); ++i) {
        Vector_int.erase(Vector_int.begin());
    }
    auto end_vector = std::chrono::high_resolution_clock::now();


    // Измерение времени для list int
    auto start_list = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < sizeof(List_int); ++i) {
        List_int.push_back(i);
    }
    for (int i = 0; i < sizeof(List_int); ++i) {
        List_int.erase(List_int.begin());
    }
    auto end_list = std::chrono::high_resolution_clock::now();

    // Вывод результатов дляint
    auto duration_vector_int = std::chrono::duration_cast<std::chrono::microseconds>(end_vector - start_vector).count();
    auto duration_list_int = std::chrono::duration_cast<std::chrono::microseconds>(end_list - start_list).count();

    std::cout << "Time for vector_int: " << duration_vector_int << " microseconds" << std::endl;
    std::cout << "Time for list_int: " << duration_list_int << " microseconds" << std::endl;

    // Измерение времени для vector double
    auto start_vector_d = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < sizeof(Vector_double); ++i) {
        Vector_double.push_back(i);
    }
    for (int i = 0; i < sizeof(Vector_double); ++i) {
        Vector_double.erase(Vector_double.begin());
    }
    auto end_vector_d = std::chrono::high_resolution_clock::now();


    // Измерение времени для list double
    auto start_list_d = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < sizeof(List_double); ++i) {
        List_double.push_back(i);
    }
    for (int i = 0; i < sizeof(List_double); ++i) {
        List_double.erase(List_double.begin());
    }
    auto end_list_d = std::chrono::high_resolution_clock::now();

    // Вывод результатов
    auto duration_vector_double = std::chrono::duration_cast<std::chrono::microseconds>(end_vector_d - start_vector).count();
    auto duration_list_double = std::chrono::duration_cast<std::chrono::microseconds>(end_list_d - start_list).count();

    std::cout << "Time for vector_double: " << duration_vector_double << " microseconds" << std::endl;
    std::cout << "Time for list_double: " << duration_list_double << " microseconds" << std::endl;
    return 0;


}
