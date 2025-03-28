#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <thread>
#include <filesystem>

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

#define NUM_PRUEBAS 1000
#define MIN_TAMANO 10
#define MAX_TAMANO 1000
#define INCREMENTO 10
#define NUM_ALGORITMOS 7

// Prototipos de funciones principales
void orden_insercion(int arr[], int n);   // 1
void orden_burbuja(int arreglo[], int longitud);      // 2
void orden_seleccion(int arreglo[], int longitud);   // 3
void orden_mezcla(int arreglo[], int longitud);       // 4
void orden_rapido(int arreglo[], int n);       // 5
void orden_monticulo(int arreglo[], int longitud);        // 6
void orden_shell(int arreglo[], int longitud);       // 7

// Prototipos de funciones auxiliares
void mezcla(int arreglo[], int izquierda, int medio, int derecha);
void ordmezcla(int arreglo[], int izquierda, int derecha);
void cambio(int* a, int* b);
int particion(int arreglo[], int inicio, int fin);
void ayuda_rapido(int arreglo[], int inicio, int fin);
void ayuda_heap(int arreglo[], int longitud, int indice);
void duplicar_arreglo(int arreglo[], int desordenado[], int longitud);


double tiempo_insercion[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double tiempo_burbuja[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double tiempo_seleccion[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double tiempo_mezcla[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double tiempo_rapido[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double tiempo_monticulo[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double tiempo_shell[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];

int main() {
    srand(time(NULL));
    const int longitud = MAX_TAMANO;
    int arreglo[longitud];
    int desordenado[longitud];
    int iteraciones = NUM_PRUEBAS+1;
    int contador_columna = 1;
    int contador_longitud = MIN_TAMANO;
    int por_iterar = (MAX_TAMANO/INCREMENTO+1);
    int tam = (MAX_TAMANO/INCREMENTO);
    double promedio_insercion = 0;
    double promedio_burbuja= 0;
    double promedio_seleccion = 0;
    double promedio_mezcla = 0;
    double promedio_rapido = 0;
    double promedio_monticulo = 0;
    double promedio_shell = 0;

    for (int j = 1; j < 101; j++) {
        cout << "Ejecutando algoritmos en longitud " << contador_longitud << "..." << endl;
        for (int i = 1; i < iteraciones; i++) {

            for (int k = 0; k < contador_longitud; k++) {
                arreglo[k] = 1 + rand() % 1000;
            }


                // Insercion
            duplicar_arreglo(arreglo, desordenado, contador_longitud);
            // Inicia el timer
            auto insertion_start = high_resolution_clock::now();
            orden_insercion(desordenado, contador_longitud);
            // Termina el timer
            auto insertion_end = high_resolution_clock::now();
            duration<double> insertion_duration = insertion_end - insertion_start;
            tiempo_insercion[i][contador_columna] = insertion_duration.count() * 1000;
            promedio_insercion += tiempo_insercion[i][contador_columna];

                // Burbuja
            duplicar_arreglo(arreglo, desordenado, contador_longitud);
            // Inicia el timer
            auto bubble_start = high_resolution_clock::now();
            orden_burbuja(desordenado, contador_longitud);
            // Termina el timer
            auto bubble_end = high_resolution_clock::now();
            duration<double> bubble_duration = bubble_end - bubble_start;
            tiempo_burbuja[i][contador_columna] = bubble_duration.count() * 1000;
            promedio_burbuja += tiempo_burbuja[i][contador_columna];

                // Seleccion
            duplicar_arreglo(arreglo, desordenado, contador_longitud);
            // Inicia el timer
            auto selection_start = high_resolution_clock::now();
            orden_seleccion(desordenado, contador_longitud);
            // Termina el timer
            auto selection_end = high_resolution_clock::now();
            duration<double> selection_duration = selection_end - selection_start;
            tiempo_seleccion[i][contador_columna] = selection_duration.count() * 1000;
            promedio_seleccion += tiempo_seleccion[i][contador_columna];

                // Mezcla
            duplicar_arreglo(arreglo, desordenado, contador_longitud);
            // Inicia el timer
            auto merge_start = high_resolution_clock::now();
            orden_mezcla(desordenado, contador_longitud);
            // Termina el timer
            auto merge_end = high_resolution_clock::now();
            duration<double> merge_duration = merge_end - merge_start;
            tiempo_mezcla[i][contador_columna] = merge_duration.count() * 1000;
            promedio_mezcla += tiempo_mezcla[i][contador_columna];

                // Rapido
            duplicar_arreglo(arreglo, desordenado, contador_longitud);
            // Inicia el timer
            auto quick_start = high_resolution_clock::now();
            orden_rapido(desordenado, contador_longitud);
            // Termina el timer
            auto quick_end = high_resolution_clock::now();
            duration<double> quick_duration = quick_end - quick_start;
            tiempo_rapido[i][contador_columna] = quick_duration.count() * 1000;
            promedio_rapido += tiempo_rapido[i][contador_columna];

                // Monticulo
            duplicar_arreglo(arreglo, desordenado, contador_longitud);
            // Inicia el timer
            auto heap_start = high_resolution_clock::now();
            orden_monticulo(desordenado, contador_longitud);
            // Termina el timer
            auto heap_end = high_resolution_clock::now();
            duration<double> heap_duration = heap_end - heap_start;
            tiempo_monticulo[i][contador_columna] = heap_duration.count() * 1000;
            promedio_monticulo += tiempo_monticulo[i][contador_columna];

                // Shell
            duplicar_arreglo(arreglo, desordenado, contador_longitud);
            // Inicia el timer
            auto shell_start = high_resolution_clock::now();
            orden_shell(desordenado, contador_longitud);
            // Termina el timer
            auto shell_end = high_resolution_clock::now();
            duration<double> shell_duration = shell_end - shell_start;
            tiempo_shell[i][contador_columna] = shell_duration.count() * 1000;
            promedio_shell += tiempo_shell[i][contador_columna];

        }
        cout << "Se han ejecutado los algoritmos con la longitud " << contador_longitud;
        cout << endl;
        cout << endl;

        tiempo_insercion[NUM_PRUEBAS+1][j-1] = promedio_insercion / 1000.0;
        promedio_insercion = 0;

        tiempo_burbuja[NUM_PRUEBAS+1][j-1] = promedio_burbuja / 1000.0;
        promedio_burbuja = 0;

        tiempo_seleccion[NUM_PRUEBAS+1][j-1] = promedio_seleccion / 1000.0;
        promedio_seleccion = 0;

        tiempo_mezcla[NUM_PRUEBAS+1][j-1] = promedio_mezcla / 1000.0;
        promedio_mezcla = 0;

        tiempo_rapido[NUM_PRUEBAS+1][j-1] = promedio_rapido / 1000.0;
        promedio_rapido = 0;

        tiempo_monticulo[NUM_PRUEBAS+1][j-1] = promedio_monticulo / 1000.0;
        promedio_monticulo = 0;

        tiempo_shell[NUM_PRUEBAS+1][j-1] = promedio_shell / 1000.0;
        promedio_shell = 0;


        contador_columna++;
        contador_longitud += INCREMENTO;

    }

    ofstream outFileInsertion("1_Insercion_Ordenamiento.csv");
    if (!outFileInsertion.is_open()) {
        cerr << "No se pudo escribir. Revise el estado del archivo en carpeta." << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    contador_longitud = 0;
    for (int i = 0; i < por_iterar; i++) {
        outFileInsertion << "Tama\361o " << contador_longitud << ",";
        contador_longitud += INCREMENTO;
    }
    for (int i = 0; i < iteraciones; i++){
        outFileInsertion << i << ",";
        for (int j = 1; j < por_iterar; j++){
            outFileInsertion <<  tiempo_insercion[i][j] << ",";
        }
        outFileInsertion << endl;
    }
    outFileInsertion << "Promedio:,";
    for (int i = 0; i < tam; i++) {
        outFileInsertion << tiempo_insercion[NUM_PRUEBAS+1][i] << ",";
    }
    outFileInsertion.close();


    ofstream outFileBubble("2_Burbuja_Ordenamiento.csv");
    if (!outFileBubble.is_open()) {
        cerr << "No se pudo escribir. Revise el estado del archivo en carpeta." << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    contador_longitud = 0;
    for (int i = 0; i < por_iterar; i++) {
        outFileBubble << "Tama\361o " << contador_longitud << ",";
        contador_longitud += INCREMENTO;
    }
    for (int i = 0; i < iteraciones; i++){
        outFileBubble << i << ",";
        for (int j = 1; j < por_iterar; j++){
            outFileBubble <<  tiempo_burbuja[i][j] << ",";
        }
        outFileBubble << endl;
    }
    outFileBubble << "Promedio:,";
    for (int i = 0; i < tam; i++) {
        outFileBubble << tiempo_burbuja[NUM_PRUEBAS+1][i] << ",";
    }
    outFileBubble.close();


    ofstream outFileSelection("3_Seleccion_Ordenamiento.csv");
    if (!outFileSelection.is_open()) {
        cerr << "No se pudo escribir. Revise el estado del archivo en carpeta." << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    contador_longitud = 0;
    for (int i = 0; i < por_iterar; i++) {
        outFileSelection << "Tama\361o " << contador_longitud << ",";
        contador_longitud += INCREMENTO;
    }
    for (int i = 0; i < iteraciones; i++){
        outFileSelection << i << ",";
        for (int j = 1; j < por_iterar; j++){
            outFileSelection <<  tiempo_seleccion[i][j] << ",";
        }
        outFileSelection << endl;
    }
    outFileSelection << "Promedio:,";
    for (int i = 0; i < tam; i++) {
        outFileSelection << tiempo_seleccion[NUM_PRUEBAS+1][i] << ",";
    }
    outFileSelection.close();

       
    ofstream outFileMerge("4_Mezcla_Ordenamiento.csv");
    if (!outFileMerge.is_open()) {
        cerr << "No se pudo escribir. Revise el estado del archivo en carpeta." << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    contador_longitud = 0;
    for (int i = 0; i < por_iterar; i++) {
        outFileMerge << "Tama\361o " << contador_longitud << ",";
        contador_longitud += INCREMENTO;
    }
    for (int i = 0; i < iteraciones; i++){
        outFileMerge << i << ",";
        for (int j = 1; j < por_iterar; j++){
            outFileMerge <<  tiempo_mezcla[i][j] << ",";
        }
        outFileMerge << endl;
    }
    outFileMerge << "Promedio:,";
    for (int i = 0; i < tam; i++) {
        outFileMerge << tiempo_mezcla[NUM_PRUEBAS+1][i] << ",";
    }
    outFileMerge.close();


    ofstream outFileQuick("5_Rapido_Ordenamiento.csv");
    if (!outFileQuick.is_open()) {
        cerr << "No se pudo escribir. Revise el estado del archivo en carpeta." << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    contador_longitud = 0;
    for (int i = 0; i < por_iterar; i++) {
        outFileQuick << "Tama\361o " << contador_longitud << ",";
        contador_longitud += INCREMENTO;
    }
    for (int i = 0; i < iteraciones; i++){
        outFileQuick << i << ",";
        for (int j = 1; j < por_iterar; j++){
            outFileQuick <<  tiempo_rapido[i][j] << ",";
        }
        outFileQuick << endl;
    }
    outFileQuick << "Promedio:,";
    for (int i = 0; i < tam; i++) {
        outFileQuick << tiempo_rapido[NUM_PRUEBAS+1][i] << ",";
    }
    outFileQuick.close();


    ofstream outFileHeap("6_Monticulos_Ordenamiento.csv");
    if (!outFileHeap.is_open()) {
        cerr << "No se pudo escribir. Revise el estado del archivo en carpeta." << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    contador_longitud = 0;
    for (int i = 0; i < por_iterar; i++) {
        outFileHeap << "Tama\361o " << contador_longitud << ",";
        contador_longitud += INCREMENTO;
    }
    for (int i = 0; i < iteraciones; i++){
        outFileHeap << i << ",";
        for (int j = 1; j < por_iterar; j++){
            outFileHeap <<  tiempo_monticulo[i][j] << ",";
        }
        outFileHeap << endl;
    }
    outFileHeap << "Promedio:,";
    for (int i = 0; i < tam; i++) {
        outFileHeap << tiempo_monticulo[NUM_PRUEBAS+1][i] << ",";
    }
    outFileHeap.close();


    ofstream outFileShell("7_Shell_Ordenamiento.csv");
    if (!outFileShell.is_open()) {
        cerr << "No se pudo escribir. Revise el estado del archivo en carpeta." << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    contador_longitud = 0;
    for (int i = 0; i < por_iterar; i++) {
        outFileShell << "Tama\361o " << contador_longitud << ",";
        contador_longitud += INCREMENTO;
    }
    for (int i = 0; i < iteraciones; i++){
        outFileShell << i << ",";
        for (int j = 1; j < por_iterar; j++){
            outFileShell <<  tiempo_shell[i][j] << ",";
        }
        outFileShell << endl;
    }
    outFileShell << "Promedio:,";
    for (int i = 0; i < tam; i++) {
        outFileShell << tiempo_shell[NUM_PRUEBAS+1][i] << ",";
    }
    outFileShell.close();

    cout << "Se han generado los archivos con extensi\242n .csv de todos los algoritmos." << endl;

    return 0;
}

void duplicar_arreglo(int arreglo[], int desordenado[], int longitud) {
    for (int i = 0; i < longitud; i++) {
        desordenado[i] = arreglo[i];
    }
}

void orden_insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
           arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

// Función Burbuja
void orden_burbuja(int arreglo[], int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        for (int j = 0; j < longitud - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }

}

// Función Selección
void orden_seleccion(int arreglo[], int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < longitud; j++) {
            if (arreglo[j] < arreglo[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Intercambio de elementos
            int temp = arreglo[i];
            arreglo[i] = arreglo[min_idx];
            arreglo[min_idx] = temp;
        }
    }
}

// Función Mezcla
void mezcla(int arreglo[], int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arreglo[izquierda + i];
    for (int j = 0; j < n2; j++)
        R[j] = arreglo[medio + 1 + j];

    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arreglo[k] = L[i];
            i++;
        } else {
            arreglo[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arreglo[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arreglo[k] = R[j];
        j++;
        k++;
    }
}

void ordmezcla(int arreglo[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int mid = izquierda + (derecha - izquierda) / 2;

        ordmezcla(arreglo, izquierda, mid);
        ordmezcla(arreglo, mid + 1, derecha);

        mezcla(arreglo, izquierda, mid, derecha);
    }
}

void orden_mezcla(int arreglo[], int longitud) {

    ordmezcla(arreglo, 0, longitud - 1);

}

// Función Rápido
void cambio(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arreglo[], int inicio, int fin) {
    int pivote = arreglo[fin]; // Selecciona el último elemento como pivote
    int i = inicio - 1; // Índice del elemento más pequeño

    for (int j = inicio; j <= fin - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arreglo[j] <= pivote) {
            i++; // Incrementa el índice del elemento más pequeño
            cambio(&arreglo[i], &arreglo[j]); // Intercambia arr[i] y arr[j]
        }
    }
    cambio(&arreglo[i + 1], &arreglo[fin]); // Intercambia el pivote con arr[i + 1]
    return i + 1; // Retorna el índice del pivote
}

void ayuda_rapido(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        // Obtiene el índice del pivote
        int pivote_idx = particion(arreglo, inicio, fin);

        // Ordena recursivamente los elementos antes y después de la partición
        ayuda_rapido(arreglo, inicio, pivote_idx - 1);
        ayuda_rapido(arreglo, pivote_idx + 1, fin);
    }
}

void orden_rapido(int arreglo[], int n) {

    ayuda_rapido(arreglo, 0, n - 1);


}

// Función Montículo
void ayuda_heap(int arreglo[], int longitud, int indice) {
    int largest = indice;
    int left = 2 * indice + 1;
    int right = 2 * indice + 2;

    if (left < longitud && arreglo[left] > arreglo[largest]) {
        largest = left;
    }

    if (right < longitud && arreglo[right] > arreglo[largest]) {
        largest = right;
    }

    if (largest != indice) {
        swap(arreglo[indice], arreglo[largest]);
        ayuda_heap(arreglo, longitud, largest);
    }
}

void orden_monticulo(int arreglo[], int longitud) {

    for (int i = longitud / 2 - 1; i >= 0; i--) {
        ayuda_heap(arreglo, longitud, i);
    }

    for (int i = longitud - 1; i > 0; i--) {
        swap(arreglo[0], arreglo[i]);
        ayuda_heap(arreglo, i, 0);
    }

}

// Función Shell
void orden_shell(int arreglo[], int longitud) {
    // Inicializar la secuencia de gaps (intervalos)
    for (int gap = longitud / 2; gap > 0; gap /= 2) {
        // Aplicar el insertion sort para cada gap
        for (int i = gap; i < longitud; i++) {
            int temp = arreglo[i]; // Almacena el valor actual
            int j;
            // Desplazar los elementos anteriores que son mayores que temp
            for (j = i; j >= gap && arreglo[j - gap] > temp; j -= gap) {
                arreglo[j] = arreglo[j - gap];
            }
            // Colocar temp en su posición correcta
            arreglo[j] = temp;
        }
    }

}
