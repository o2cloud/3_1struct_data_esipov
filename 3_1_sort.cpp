#include <cstdlib>
#include <cstring>
#include <iostream>
#include <istream>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;


const int ESC_KEY = 27;
int quicksortCounter = 0;
int extraQuicksortCounter = 0;
int compareCount = 0;
size_t allocatedMemory=0;



void codeExit();

template <typename T>
void printArray(T* arr, int n);

template <typename T>
void BubbleSort(T* arr, int n);

template <typename T>
void BubbleSortUpgraded(T* arr, int n);

template <typename T>
void ShakerSort(T* arr, int n);

template <typename T>
void QuickSort(T* arr, int n);

template <typename T>
void ReverseQuickSort(T* arr, int n);

int main(){
  
  setlocale(LC_ALL, "Russian");

  string filename = "test_numbers.txt"; 

  ifstream file(filename);
  
  if (!file.is_open()){
    cout << "Error open file" << endl;
    cout << "Завершение работы программы...";
    exit(0);                          //в случае, если файл не удалось открыть, программа досрочно завершается
  }


  for (int n=1; n<=4; n++){  
    int startTime, endTime;
    int size;
    if (n>1){
      codeExit();
    }
    cout << "Введите число N" << n <<": ";
    cin >> size;
    int *numbers = new int[size];
    
    for (int i=0;i<size;i++){
      int value;
      file >> value;
      numbers[i]=value;
    }
    
    
    cout << "--------------------------------------------------------------------\n";
    cout << "ПУЗЫРЬКОВАЯ СОРТИРОВКА (" << size << " элементов):\n";
    
    cout << "\n\n* * * Применение функции для неотсортированного массива * * *\n";
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n--------------------------------------------------------------------";
    BubbleSort(numbers,size);
    cout << "+-------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива после сортировки: ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для отсортированного массива * * *\n";
    cout << "\n--------------------------------------------------------------------";
    BubbleSort(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для массива, отсортированного в обратном порядке * * *\n";
    ReverseQuickSort(numbers,size);
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n-------------------------------------------------------------------";
    BubbleSort(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива после сортировки: ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    file.clear();
    file.seekg(0);
    system("cls");
    
    for (int i=0;i<size;i++){
      int value;
      file >> value;
      numbers[i]=value;
    }


    cout << "--------------------------------------------------------------------\n";        
    cout << "ПУЗЫРЬКОВАЯ СОРТИРОВКА C ФИКСАЦИЕЙ МЕСТА ОБМЕНА (" << size << " элементов):\n";
    
    cout << "\n\n* * * Применение функции для неотсортированного массива * * *\n";
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n--------------------------------------------------------------------";
    BubbleSortUpgraded(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива после сортировки: ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для отсортированного массива * * *\n";
    cout << "\n--------------------------------------------------------------------";
    BubbleSortUpgraded(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для массива, отсортированного в обратном порядке * * *\n";
    ReverseQuickSort(numbers,size);
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n-------------------------------------------------------------------";
    BubbleSortUpgraded(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива после сортировки: ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    file.clear();
    file.seekg(0);    
    system("cls");
    
    for (int i=0;i<size;i++){
      int value;
      file >> value;
      numbers[i]=value;
    }
    
    
    cout << "--------------------------------------------------------------------\n";
    cout << "ШЕЙКЕРНАЯ СОРТИРОВКА (" << size << " элементов):\n";
    
    cout << "\n\n* * * Применение функции для неотсортированного массива * * *\n";
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n--------------------------------------------------------------------";
    ShakerSort(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива после сортировки:  ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для отсортированного массива * * *\n";
    cout << "\n--------------------------------------------------------------------";
    ShakerSort(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для массива, отсортированного в обратном порядке * * *\n";
    ReverseQuickSort(numbers,size);
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n-------------------------------------------------------------------";
    ShakerSort(numbers,size);
    cout << "--------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    file.clear();
    file.seekg(0);
    system("cls");
    
    for (int i=0;i<size;i++){
      int value;
      file >> value;
      numbers[i]=value;
    }
    
    cout << "--------------------------------------------------------------------\n";        
    cout << "БЫСТРАЯ СОРТИРОВКА (" << size << " элементов):\n";    
    
    cout << "\n\n* * * Применение функции для неотсортированного массива * * *\n";
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n--------------------------------------------------------------------\n";
    startTime = clock();
    QuickSort(numbers,size);
    endTime = clock();
    cout << "\nВремя выполнения алгоритма: " << endTime - startTime << " мс\n";
    cout << "Выделенная память: " << allocatedMemory << " байт\n";
    cout << "Количество сравнений: " << quicksortCounter << endl;
    cout << "Количество вспомогательных сравнений: " << extraQuicksortCounter << endl;
    quicksortCounter = 0;
    cout << "--------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива после сортировки: ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для отсортированного массива * * *\n";
    cout << "\n--------------------------------------------------------------------\n";
    startTime = clock();
    QuickSort(numbers,size);
    endTime = clock();
    cout << "\nВремя выполнения алгоритма: " << endTime - startTime << " мс\n";
    cout << "Выделенная память: " << allocatedMemory << " байт\n";
    cout << "Количество сравнений: " << quicksortCounter << endl;
    cout << "Количество вспомогательных сравнений: " << extraQuicksortCounter << endl;
    quicksortCounter = 0;
    cout << "--------------------------------------------------------------------\n";
    cout << endl;
    system("Pause");
    
    
    cout << "\n\n* * * Применение функции для массива, отсортированного в обратном порядке * * *\n";
    ReverseQuickSort(numbers,size);
    cout << "\nПервые 8 элементов массива до сортировки: ";
    printArray(numbers,8);
    cout << "\n-------------------------------------------------------------------\n";
    startTime = clock();
    QuickSort(numbers,size);
    endTime = clock();
    cout << "\nВремя выполнения алгоритма: " << endTime - startTime << " мс\n";
    cout << "Выделенная память: " << allocatedMemory << " байт\n";
    cout << "Количество сравнений: " << quicksortCounter << endl;
    cout << "Количество вспомогательных сравнений: " << extraQuicksortCounter << endl;

    quicksortCounter = 0;
    cout << "-------------------------------------------------------------------\n";
    cout << "Первые 8 элементов массива после сортировки: ";
    printArray(numbers,8);
    cout << endl << endl;
    system("Pause");
    file.clear();
    file.seekg(0);
    system("cls");

    delete [] numbers;
  }
  
  file.close();     //закрытие файла
  return 0;
}

template <typename T>
void printArray(T* arr, int n){
  for (int i=0; i<n;i++){
    cout << arr[i] << " ";
  } 
}


template <typename T>
void BubbleSort(T* arr,int n){
  int startTime, endTime;

  startTime = clock();
  
  int assignmentCount=0, extraAssignmentCount = 0;
  for (int i=1;i<n;i++){
    extraAssignmentCount++;
    for (int j=n-1;j>=i;j--){
      extraAssignmentCount++;
      assignmentCount++;
      if(arr[j]>arr[j-1]){
        T temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
    }
  }
  endTime = clock();
  
  size_t allocatedMemory;
  allocatedMemory = sizeof(int)*2 + sizeof(T); //память, выделенная под массив + доп переменные (в данном случае - i, j и temp)
  
  cout << "\nВремя выполнения алгоритма: " << endTime - startTime << " мс\n";
  cout << "Выделенная память: " << allocatedMemory << " байт\n";
  cout << "Количество сравнений: " << assignmentCount << endl;
  cout << "Количество вспомогательных сравнений: " << extraAssignmentCount << endl;
}


template <typename T>
void BubbleSortUpgraded(T* arr, int n){
  int startTime, endTime;
  
  startTime = clock();
  
  int i=1,k;
  int assignmentCount=0, extraAssignmentCount = 0;
  do{
    k=0;
    for (int j=n-1;j>=i;j--){
      extraAssignmentCount++;
      
      assignmentCount++;
      if(arr[j]>arr[j-1]){
        T temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        k = j;      //запоминаем место последнего обмена
      }
    }
    i = k;         //запоминаем место последнего обмена как левую границу
  }while(k);
  
  endTime = clock();
  
  size_t allocatedMemory;
  allocatedMemory = sizeof(int)*3 + sizeof(T); //память, выделенная под массив + доп переменные (в данном случае - i, j, k и temp)

  cout << "\nВремя выполнения алгоритма: " << endTime - startTime << " мс\n";
  cout << "Выделенная память: " << allocatedMemory << " байт\n";
  cout << "Количество сравнений: " << assignmentCount << endl;
  cout << "Количество вспомогательных сравнений: " << extraAssignmentCount << endl;
}

template <typename T>
void ShakerSort(T* arr, int n){
  int startTime, endTime;
  
  startTime = clock();
  
  int left = 1,right = n-1,k = n-1;
  int assignmentCount=0, extraAssignmentCount = 0;
  do{
    
    for(int j=right;j>=left;j--){
      extraAssignmentCount++;
      assignmentCount++;
      
      if(arr[j]>arr[j-1]){
        T temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        k=j;
      }
    }
    left = k+1;
    for(int j=left;j<=right;j++){
      extraAssignmentCount++;
      assignmentCount++;
      
      if(arr[j]>arr[j-1]){
        T temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        k=j;
      }
    }
    right = k-1;
    extraAssignmentCount++;
  }while (left<=right);
  
  endTime = clock();
  
  size_t allocatedMemory;
  allocatedMemory = sizeof(int)*4 + sizeof(T); //память, выделенная под массив + доп переменные (в данном случае - i, j и temp)

  cout << "\nВремя выполнения алгоритма: " << endTime - startTime << " мс\n";
  cout << "Выделенная память: " << allocatedMemory << " байт\n";
  cout << "Количество сравнений: " << assignmentCount << endl;
  cout << "Количество вспомогательных сравнений: " << extraAssignmentCount << endl;
  
}

template <typename T>
void QuickSort(T* arr, int n){
  
  int i = 0,j = n-1;
  T pivot = arr[n/2];
  do
  {
    while (arr[i]>pivot) {
      i++;
      quicksortCounter++;
    }
    while (pivot>arr[j]){
      j--;
      quicksortCounter++;
    }
    extraQuicksortCounter++;
    if (i<=j){
      T temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++; 
      j--;
    }
    extraQuicksortCounter++;
  } while (i<j);
  
  extraQuicksortCounter++;
  if (j>0) QuickSort(arr,j+1);
  
  extraQuicksortCounter++;
  if (i<n-1) QuickSort(arr+i,n-i);

  allocatedMemory += sizeof(int)*2 + sizeof(T)*2;
}

template <typename T>
void ReverseQuickSort(T* arr, int n){  //функция для сортировки массива в обратном порядке относительно условия
  int i,j;
  T pivot = arr[n/2];
  i=0;
  j = n-1;
  do
  {
    while (arr[i]<pivot) i++;
    while (pivot<arr[j]) j--;
    if (i<=j){
      T temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++; 
      j--;
    }
  } while (i<j);
  if (j>0) ReverseQuickSort(arr,j+1);
  if (i<n-1) ReverseQuickSort(arr+i,n-i);
}

void codeExit(){
  cout << "Для досрочного завершения программы нажмите клавишу esc. Для продолжения работы нажмите любую другую клавишу." << endl;
  if (getch()==ESC_KEY){                    //если пользователь нажал на клавишу esc, выполнение программы завершается
    cout << "Досрочное завершение работы программы...";
    exit(0);
  } 
}