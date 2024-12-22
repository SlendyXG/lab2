#include <iostream>
#include <ctime>
#include <chrono>
#include <time.h>
#include <math.h>

using namespace std;
using namespace chrono;
int promptMenuItem()
{

    int variant;
    cout << "Выберите вариант: " << endl;
    cout << "1. Создать несортированный массив из 100 элементов\n"
        << "2. Отсортировать заданный в пункте 1 массив\n"
        << "3. Найти максимальный и минимальный элемент\n"
        << "4. Найти средний элемент\n"
        << "5. Вывести количество элементов в отсортированном массиве, которые меньше числа num\n"
        << "6. Вывести количество элементов в отсортированном массиве, которые больше числа num\n"
        << "7. Бинарный поиск\n"
        << "8. Смена элементов массива\n"
        << "9. Shellsort" << endl;
    cout << ">>> ";
    cin >> variant;
    return variant;
}
void quicksort(int* arr, int  end, int begin)
{
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}
int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }
        return binarySearch(arr, value, mid + 1, end);
    }
    return -1;
}
int shellSort(int arr[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
    return 0;
}


int main(int argc, char* argv[])
{
    while (true) {
        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
        nanoseconds result1;
        setlocale(LC_ALL, "Russian");
        srand(time(0));
        int variant = promptMenuItem();
        const int N(100);
        int arr[N];
        int max(99), min(-99), maxEl, minEl, average, middle, k(0), cnt(0), flag(0);
        int maxx(-10000), minn(100000);
        int value, j;
        int end = N - 1, begin = 0;
        int num, count(0);
        for (int i = 0; i < N; i++)
        {
            arr[i] = rand() % (max - min + 1) + min;
        }
        int size = sizeof(arr) / sizeof(arr[0]);
        int result, random;
        switch (variant) {
        case 1: {
            cout << "Несортированный массив: ";
            for (int i = 0; i < N; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
              break;
        case 2: {
            cout << "Несортированный массив: ";
            for (int i = 0; i < N; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            auto start1 = steady_clock::now();
            quicksort(arr, end, begin);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << endl << "Отсортированный массив: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "Время, затраченное на сортировку массива : " << result1.count() << " nanoseconds" << endl;
        }
              break;
        case 3: {
            cout << "Несортированный массив: ";
            for (int i = 0; i < N; i++)
            {
                cout << arr[i] << " ";
            }
            auto start1 = steady_clock::now();
            for (int i = 0; i < N; i++) {
                if (arr[i] < minn) {
                    minn = arr[i];
                }
                if (arr[i] > maxx) {
                    maxx = arr[i];
                }
            }
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << endl;
            cout << endl;
            cout << "Реализация в неотсортированном массиве: \nМаксимальный элемент массива: " << maxx << " и минимальный элемент: " << minn << endl;
            cout << "Время: " << result1.count() << " nanoseconds" << endl;
            quicksort(arr, end, begin);
            auto start = steady_clock::now();
            minEl = arr[0];
            maxEl = arr[99];
            auto end = steady_clock::now();
            auto result = duration_cast<nanoseconds>(end - start);
            cout << "Реализация в отсортированном массиве: \nМаксимальный элемент массива: " << maxEl << " и минимальный элемент: " << minEl << endl;
            cout << "Время: " << result.count() << " nanoseconds" << endl;
        }
              break;
        case 4: {
            cout << "Несортированный массив: ";
            for (int i = 0; i < N; i++)
            {
                arr[i] = rand() % (max - min + 1) + min;
                cout << arr[i] << " ";
            }
            auto start2 = steady_clock::now();
            for (int i = 0; i < N; i++) {
                if (arr[i] < minn) {
                    minn = arr[i];
                }
                if (arr[i] > maxx) {
                    maxx = arr[i];
                }
            }
            middle = round((maxx - minn) / 2);
            auto end2 = steady_clock::now();
            auto result2 = duration_cast<nanoseconds>(end2 - start2);
            cout << endl;
            cout << "Среднее значение в неотсортированном массиве: " << middle << endl;
            for (int i = 0; i < N; i++) {
                if (arr[i] == middle) {
                    cout << "На позициии " << i << " находится элемент равный среднему значению " << endl;
                    k += 1;
                }
            }
            cout << "Количество элементов массива равных среднему значению " << k << " и время поиска " << result2.count() << " nanoseconds" << endl;
            cout << endl;
            quicksort(arr, end, begin);
            auto start1 = steady_clock::now();
            minEl = arr[0];
            maxEl = arr[N - 1];
            average = round((arr[N - 1] - arr[0]) / 2);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << "Среднее значение в отсортированном массиве: " << average << endl;
            for (int i = 0; i < N; i++) {
                if (arr[i] == average) {
                    cout << "На позициии " << i << " находится элемент равный среднему значению " << endl;
                    cnt += 1;
                }
            }
            cout << "Количество элементов массива равных среднему значению " << cnt << " и время поиска " << result1.count() << " nanoseconds" << endl;

        }
              break;

        case 5: {
            cout << "Введите число в промежутке от -99 до 99: " << endl;
            cin >> num;
            for (int i = 0; i < N; i++)
            {
                arr[i] = rand() % (max - min + 1) + min;
            }
            cout << endl;
            quicksort(arr, end, begin);
            cout << "Отсортированный массив: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
                if (num > arr[i]) {
                    count += 1;
                }
            }
            cout << endl;
            cout << "Количество элементов, которые меньше Вашего числа: " << count << endl;
        }
              break;

        case 6: {
            cout << "Введите число в промежутке от -99 до 99: " << endl;
            cin >> num;
            for (int i = 0; i < N; i++)
            {
                arr[i] = rand() % (max - min + 1) + min;
            }
            cout << endl;
            quicksort(arr, end, begin);
            cout << "Отсортированный массив: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
                if (num < arr[i]) {
                    count += 1;
                }
            }
            cout << endl;
            cout << "Количество элементов, которые больше Вашего числа: " << count << endl;
        }
              break;
        case 7: {
            cout << "Введите каким способом осуществить поиск: бинарный поиск(1) или перебор(2): ";
            cin >> j;
            cout << "Введите число, чтобы проверить есть ли оно в массиве: ";
            cin >> value;
            for (int i = 0; i < N; i++)
            {
                arr[i] = rand() % (max - min + 1) + min;
            }
            cout << endl;
            if (j == 1) {
                quicksort(arr, end, begin);
                cout << endl << "Отсортированный массив: ";
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                auto start1 = steady_clock::now();
                result = binarySearch(arr, value, 0, size - 1);
                auto end1 = steady_clock::now();
                auto result1 = duration_cast<nanoseconds>(end1 - start1);
                cout << endl;
                if (result == -1) {
                    cout << "Элемент не найден" << endl;
                }
                else {
                    cout << "Элемент находится в позиции: " << result + 1 << endl;
                }
                cout << "Время, затраченное на нахождения элемента бинарным поиском : " << result1.count() << " nanoseconds" << endl;
            }
            else if (j == 2) {
                quicksort(arr, end, begin);
                cout << endl << "Отсортированный массив: ";
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                auto start1 = steady_clock::now();
                for (int m = 0; m < N; m++) {
                    if (arr[m] == value) {
                        cout << "Элемент находится в позиции: " << m << endl;
                        flag += 1;
                        if (arr[m + 1] != value) {
                            break;
                        }
                        else {
                            cout << "2 элемент находится в позиции: " << m + 1 << endl;
                        }

                    }

                }
                if (flag == 0) {
                    cout << "Элемент не найден" << endl;
                }
                auto end1 = steady_clock::now();
                auto result1 = duration_cast<nanoseconds>(end1 - start1);
                cout << "Время, затраченное на нахождения элемента методом перебора : " << result1.count() << " nanoseconds" << endl;
            }
            else {
                cout << "Вы выбрали неверный вариант" << endl;
            }
        }
              break;
        case 8: {
            cout << "Введите два числа, которые будут отвечать, какие элементы массива нужно сменить: " << endl;
            cin >> j;
            cin >> num;
            cout << "Несортированный массив: ";
            for (int i = 0; i < N; i++)
            {
                arr[i] = rand() % (max - min + 1) + min;
                cout << arr[i] << " ";
            }
            auto start1 = steady_clock::now();
            swap(arr[j], arr[num]);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << endl;
            cout << "Измененный массив: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "Время, затраченное на смену местами элементов: " << result1.count() << " nanoseconds" << endl;

        }
              break;
        case 9: {
            cout << "Несортированный массив: " << endl;
            for (int i = 0; i < N; i++) {
                arr[i] = rand() % (max - min + 1) + min;
                cout << arr[i] << " ";
            }
            size = sizeof(arr) / sizeof(arr[0]);
            auto start1 = steady_clock::now();
            shellSort(arr, size);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << endl;
            cout << "Отсортированный массив: " << endl;
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "Время, затраченное на сортировку: " << result1.count() << " nanoseconds" << endl;
            cout << endl;
        }
              break;
        default:
            cerr << "Вы выбрали неверный вариант" << endl;
            exit(EXIT_FAILURE);
      }

      cout << endl;
  }
}