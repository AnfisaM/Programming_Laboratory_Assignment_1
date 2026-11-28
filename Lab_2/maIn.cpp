#include <iostream>
#include <random>
#include <chrono>
#include <utility>
#include <cmath>
#include <limits>

void bubbleSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int N) {
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void copyArray(const int source[], int destination[], int N) {
    for (int i = 0; i < N; i++) {
        destination[i] = source[i];
    }
}

void selectionSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void gnomeSort(int arr[], int N) {
    int i = 0;

    while (i < N) {
        if (i == 0 || arr[i] >= arr[i - 1]) {
            i++;
        } else {
            std::swap(arr[i], arr[i - 1]);
            i--;
        }
    }
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int i = left;
    int j = right;
    int pivot = arr[left + (right - left) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }

    if (i < right) {
        quickSort(arr, i, right);
    }
}
void quickSortWrapper(int arr[], int N) {
    quickSort(arr, 0, N - 1);
}

void findMinMax(const int arr[], int N, int& minValue, int& maxValue){
    minValue=arr[0];
    maxValue=arr[0];

    for (int i=1; i<=N-1; i++){
        if (arr[i]<minValue){
            minValue=arr[i];
        }

        if (arr[i]> maxValue){
            maxValue=arr[i];
        }
    }

}

void findMinMaxSorted(const int arr[], int N, int& minValue, int& maxValue){
    minValue=arr[0];
    maxValue=arr[N-1];
}

int findAllMatches(const int arr[], int N, int average, int indices[]) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] == average) {
            indices[count] = i;
            count++;
        }
    }

    return count;
}

int lowerBound(const int arr[], int N, int x) {
    int left = 0;
    int right = N;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int upperBound(const int arr[], int N, int x) {
    int left = 0;
    int right = N;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int findAllMatchesSorted(const int arr[], int N, int average, int indices[]) {
    int first = lowerBound(arr, N, average);
    int last = upperBound(arr, N, average);

    int count = last - first;

    for (int i = 0; i < count; i++) {
        indices[i] = first + i;
    }

    return count;
}

void countElementsLinear(const int arr[], int N, int a, int b, int& lessCount, int& greaterCount) {
    lessCount = 0;
    greaterCount = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] < a) {
            lessCount++;
        }

        if (arr[i] > b) {
            greaterCount++;
        }
    }
}

void countElementsBinary(const int arr[], int N,
                         int a, int b,
                         int& lessCount, int& greaterCount) {
    lessCount = lowerBound(arr, N, a);
    greaterCount = N - upperBound(arr, N, b);
}

bool linearSearch(const int arr[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            return true;
        }
    }

    return false;
}

bool binarySearch(const int arr[], int N, int x) {
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return true;
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

void swapElements(int arr[], int index1, int index2) {
    std::swap(arr[index1], arr[index2]);
}

int replaceMultiplesOfThree(int arr[], int N) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] % 3 == 0 && arr[i] != 0) {
            arr[i] = 0;
            count++;
        }
    }

    return count;
}

void printArray(const int arr[], int N) {
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void fillRandom(int arr[], int N) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> d(-99, 99);

    for (int i = 0; i < N; i++) {
        arr[i] = d(gen);
    }
}
bool fillManual(int arr[], int N) {
    std::cout << "Введите " << N << " целых чисел:\n";

    for (int i = 0; i < N; i++) {
        std::cout << "arr[" << i << "] = ";

        if (!(std::cin >> arr[i])) {
            std::cout << "Ошибка ввода!\n";
            return false;
        }
    }

    return true;
}
void measureSort(const int arr[], int result[], int N,
                     void (*sortFunction)(int[], int),
                     const char* name){

        copyArray(arr, result, N);

        auto start = std::chrono::steady_clock::now();

        sortFunction(result, N);

        auto end = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<
            std::chrono::microseconds>(end - start).count();

        std::cout << "\n" << name << ":\n";

        printArray(result, N);

        std::cout << "Время сортировки: "
                << duration << " мкс\n";
}

void compareMinMax(const int arr[], const int sortedArr[],
                   int N) {
    int minValue, maxValue;

    auto start1 = std::chrono::steady_clock::now();

    findMinMax(arr, N, minValue, maxValue);

    auto end1 = std::chrono::steady_clock::now();

    auto time1 = std::chrono::duration_cast<
        std::chrono::nanoseconds>(end1 - start1).count();

    std::cout << "\nПоиск в неотсортированном массиве:\n";
    std::cout << "Минимальный элемент: " << minValue << "\n";
    std::cout << "Максимальный элемент: " << maxValue << "\n";
    std::cout << "Время поиска: " << time1 << " нс\n";

    int sortedMin, sortedMax;

    auto start2 = std::chrono::steady_clock::now();

    findMinMaxSorted(sortedArr, N, sortedMin, sortedMax);

    auto end2 = std::chrono::steady_clock::now();

    auto time2 = std::chrono::duration_cast<
        std::chrono::nanoseconds>(end2 - start2).count();

    std::cout << "\nПоиск в отсортированном массиве:\n";
    std::cout << "Минимальный элемент: " << sortedMin << "\n";
    std::cout << "Максимальный элемент: " << sortedMax << "\n";
    std::cout << "Время поиска: " << time2 << " нс\n";
}

void compareMatches(const int arr[], const int sortedArr[],
                    int N) {
    int minValue, maxValue;

    findMinMaxSorted(sortedArr, N, minValue, maxValue);

    int average = std::round((minValue + maxValue) / 2.0);

    std::cout << "\nСреднее значение минимума и максимума: "
              << average << "\n";

    int indices[100];

    auto start1 = std::chrono::steady_clock::now();

    int count = findAllMatches(arr, N, average, indices);

    auto end1 = std::chrono::steady_clock::now();

    auto time1 = std::chrono::duration_cast<
        std::chrono::nanoseconds>(end1 - start1).count();

    std::cout << "\nПоиск совпадений в неотсортированном массиве:\n";

    std::cout << "Индексы совпадений: ";
    printArray(indices, count);

    std::cout << "Количество совпадений: " << count << "\n";
    std::cout << "Время поиска: " << time1 << " нс\n";

    int sortedIndices[100];

    auto start2 = std::chrono::steady_clock::now();

    int sortedCount = findAllMatchesSorted(
        sortedArr, N, average, sortedIndices);

    auto end2 = std::chrono::steady_clock::now();

    auto time2 = std::chrono::duration_cast<
        std::chrono::nanoseconds>(end2 - start2).count();

    std::cout << "\nПоиск совпадений в отсортированном массиве:\n";

    std::cout << "Индексы совпадений: ";
    printArray(sortedIndices, sortedCount);

    std::cout << "Количество совпадений: "
              << sortedCount << "\n";

    std::cout << "Время поиска: " << time2 << " нс\n";
}

void compareCounts(const int arr[], const int sortedArr[],
                   int N) {
    int a, b;

    std::cout << "\nВведите число a: ";
    std::cin >> a;

    std::cout << "Введите число b: ";
    std::cin >> b;

    if (!std::cin) {
        std::cout << "Ошибка ввода!\n";
        return;
    }

    int lessCount, greaterCount;

    auto start1 = std::chrono::steady_clock::now();

    countElementsLinear(arr, N, a, b,
                        lessCount, greaterCount);

    auto end1 = std::chrono::steady_clock::now();

    auto time1 = std::chrono::duration_cast<
        std::chrono::nanoseconds>(end1 - start1).count();

    std::cout << "\nЛинейный подсчёт:\n";
    std::cout << "Количество элементов меньше a: "
              << lessCount << "\n";
    std::cout << "Количество элементов больше b: "
              << greaterCount << "\n";
    std::cout << "Время выполнения: " << time1 << " нс\n";

    int sortedLessCount, sortedGreaterCount;

    auto start2 = std::chrono::steady_clock::now();

    countElementsBinary(sortedArr, N, a, b,
                        sortedLessCount, sortedGreaterCount);

    auto end2 = std::chrono::steady_clock::now();

    auto time2 = std::chrono::duration_cast<
        std::chrono::nanoseconds>(end2 - start2).count();

    std::cout << "\nБинарный подсчёт:\n";
    std::cout << "Количество элементов меньше a: "
              << sortedLessCount << "\n";
    std::cout << "Количество элементов больше b: "
              << sortedGreaterCount << "\n";
    std::cout << "Время выполнения: " << time2 << " нс\n";
}

void compareSearch(const int arr[], const int sortedArr[],
                   int N) {
    const int searchCount = 5;

    long long totalLinearNs = 0;
    long long totalBinaryNs = 0;

    for (int i = 0; i < searchCount; i++) {
        int target;

        std::cout << "\nВведите число для поиска: ";

        if (!(std::cin >> target)) {
            std::cout << "Ошибка ввода!\n";
            return;
        }

        auto startLinear = std::chrono::steady_clock::now();

        bool foundLinear = linearSearch(arr, N, target);

        auto endLinear = std::chrono::steady_clock::now();

        totalLinearNs += std::chrono::duration_cast<
            std::chrono::nanoseconds>(
                endLinear - startLinear).count();

        auto startBinary = std::chrono::steady_clock::now();

        bool foundBinary = binarySearch(sortedArr, N, target);

        auto endBinary = std::chrono::steady_clock::now();

        totalBinaryNs += std::chrono::duration_cast<
            std::chrono::nanoseconds>(
                endBinary - startBinary).count();

        std::cout << "Линейный поиск: "
                  << (foundLinear ? "найдено" : "не найдено")
                  << "\n";

        std::cout << "Бинарный поиск: "
                  << (foundBinary ? "найдено" : "не найдено")
                  << "\n";
    }

    std::cout << "\nСреднее время линейного поиска: "
              << static_cast<double>(totalLinearNs) / searchCount
              << " нс\n";

    std::cout << "Среднее время бинарного поиска: "
              << static_cast<double>(totalBinaryNs) / searchCount
              << " нс\n";
}

void performSwap(int arr[], int N) {
    int index1, index2;

    std::cout << "\nВведите индекс первого элемента: ";
    std::cin >> index1;

    std::cout << "Введите индекс второго элемента: ";
    std::cin >> index2;

    if (!std::cin || index1 < 0 || index1 >= N ||
                     index2 < 0 || index2 >= N) {
        std::cout << "Ошибка: некорректные индексы!\n";
        return;
    }

    const int swapCount = 100000;

    int swapArr[100];
    copyArray(arr, swapArr, N);

    auto swapStart = std::chrono::steady_clock::now();

    for (int i = 0; i < swapCount; i++) {
        swapElements(swapArr, index1, index2);
    }

    auto swapEnd = std::chrono::steady_clock::now();

    auto totalSwapNs = std::chrono::duration_cast<
        std::chrono::nanoseconds>(
            swapEnd - swapStart).count();

    double averageSwapNs =
        static_cast<double>(totalSwapNs) / swapCount;

    std::cout << "\nСреднее время одного обмена: "
              << averageSwapNs << " нс\n";

    swapElements(arr, index1, index2);

    std::cout << "\nМассив после обмена:\n";
    printArray(arr, N);
}

void performIndividualTask(int arr[], int N) {
    int changedCount = replaceMultiplesOfThree(arr, N);

    std::cout << "\nИндивидуальное задание № 9\n";

    std::cout << "Массив после замены элементов "
              << "кратных трём, нулями:\n";

    printArray(arr, N);

    std::cout << "\nКоличество изменённых элементов: "
              << changedCount << "\n";
}

void printMenu() {
    std::cout << "\n========== ГЛАВНОЕ МЕНЮ ==========\n";
    std::cout << "1. Заполнить массив\n";
    std::cout << "2. Вывести массив\n";
    std::cout << "3. Сравнить алгоритмы сортировки\n";
    std::cout << "4. Найти минимум и максимум\n";
    std::cout << "5. Найти среднее значение и совпадения\n";
    std::cout << "6. Подсчитать элементы меньше a и больше b\n";
    std::cout << "7. Линейный и бинарный поиск\n";
    std::cout << "8. Поменять элементы местами\n";
    std::cout << "9. Индивидуальное задание № 9\n";
    std::cout << "0. Выход из программы\n";
    std::cout << "Ваш выбор: ";
}

bool fillArray(int arr[], int N) {
    int choice;

    std::cout << "\nВыберите способ заполнения массива:\n";
    std::cout << "1. Случайное заполнение\n";
    std::cout << "2. Ручное заполнение\n";
    std::cout << "Ваш выбор: ";

    if (!(std::cin >> choice)) {
        std::cout << "Ошибка ввода!\n";
        return false;
    }

    if (choice == 1) {
        fillRandom(arr, N);
        return true;
    }
    else if (choice == 2) {
        return fillManual(arr, N);
    }
    else {
        std::cout << "Некорректный выбор!\n";
        return false;
    }
}

void compareSorts(const int arr[], int N) {
    int result[100];

    measureSort(arr, result, N,
                bubbleSort, "Пузырьковая сортировка");

    measureSort(arr, result, N,
                insertionSort, "Сортировка вставками");

    measureSort(arr, result, N,
                selectionSort, "Сортировка выбором");

    measureSort(arr, result, N,
                gnomeSort, "Гномья сортировка");

    measureSort(arr, result, N,
                quickSortWrapper, "Быстрая сортировка");
}

void updateSortedArray(const int arr[], int sortedArr[],
                       int N) {
    copyArray(arr, sortedArr, N);
    quickSort(sortedArr, 0, N - 1);
}
int main() {
    const int N = 100;

    int arr[N];
    int quickArr[N];

    bool running = true;

    // Первоначальное заполнение массива
    fillRandom(arr, N);
    updateSortedArray(arr, quickArr, N);

    while (running) {
        printMenu();

        int choice;

        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                break;
            }

            std::cout << "Ошибка ввода!\n";

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n');

            continue;
        }

        switch (choice) {
            case 1: {
                int newArr[N];

                if (fillArray(newArr, N)) {
                    copyArray(newArr, arr, N);
                    updateSortedArray(arr, quickArr, N);
                    std::cout << "Массив успешно заполнен!\n";
                }
                break;
            }

            case 2:
                std::cout << "\nТекущий массив:\n";
                printArray(arr, N);
                break;

            case 3:
                compareSorts(arr, N);
                break;

            case 4:
                compareMinMax(arr, quickArr, N);
                break;

            case 5:
                compareMatches(arr, quickArr, N);
                break;

            case 6:
                compareCounts(arr, quickArr, N);
                break;

            case 7:
                compareSearch(arr, quickArr, N);
                break;

            case 8:
                performSwap(arr, N);
                updateSortedArray(arr, quickArr, N);
                break;

            case 9:
                performIndividualTask(arr, N);
                updateSortedArray(arr, quickArr, N);
                break;

            case 0:
                running = false;
                std::cout << "Завершение программы.\n";
                break;

            default:
                std::cout << "Некорректный выбор!\n";
        }

        if (std::cin.eof()) {
            break;
        }

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n');
        }
    }

    return 0;
}