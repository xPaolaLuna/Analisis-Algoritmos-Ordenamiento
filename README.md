# Analisis de Algoritmos de Ordenamiento

Es un programa que corre diferentes algoritmos en diferentes condiciones, de las cuales recupera el tiempo de ejecución de estos. Los algoritmos utilizados son los siguientes:

- **Ordenamiento por Inserción**
- **Ordenamiento de Burbuja**
- **Ordenamiento por Selección**
- **Ordenamiento por Mezcla**
- **Ordenamiento Rápido**
- **Ordenamiento por Montículos**
- **Ordenamiento de Shell**

## Requisitos para ejecutar el programa
- **GCC** (GNU Compiler Collection)

## ¿Cómo instalar?
**Desde la terminal:**
1. Clone el repositorio (o bien descarge el documento algoritmos.cpp de este repositorio):
   ```sh
   git clone https://github.com/vacota/algoritmos_de_ordenamiento.git
   ```
2. Entre al directorio del proyecto (o bien, donde haya descargado el documento):
   ```sh
   cd algoritmos_de_ordenamiento
   ```
3. Compile el código:
   ```sh
   g++ algoritmos.cpp -o algoritmos -std=c++20
   ```
4. Ejecute el código
   ```sh
   ./algoritmos
   ```

## Explicación de algoritmos
Se creó este programa para calcular el tiempo de ejecución de algoritmos para comparar un arreglo de cierta longitud con números aleatorios con los de demás longitudes, que van aumentando de 10 en 10 (por defecto) cada vez que se ejecuten estos mismos un total de 1000 veces (por defecto).

  #### Vector que ordenaremos
Definiremos un arreglo con una cantidad estática de elementos, que a su vez se le asignarán de manera aleatoria. Los algoritmos de ordenamiento solo tendrán acceso a la cantidad de numeros aleatorios que se generaron en la iteración y a su vez la cantidad de estos se generarán a partir del valor mínimo y el incremento que se le asigne (por defecto 10 y 10, respectivamente).

  #### Acceso a los algoritmos
Tienen ubicación al final del archivo y en forma de funciones. Como argumentos tiene el vector a ordenar y la cantidad de elementos a ordenar.

  #### Guardado de tiempos
El tiempo pasado durante la ejecución de un algoritmo se guarda en un cronómetro activado previo a la ejecución de este y se para en cuanto acabe. Una vez se ejecute, el tiempo se pasa a una matriz que posteriormente utilizaremos para exportar los datos al archivo .csv. El promedio de las ejecuciones se guarda en la misma columna con la longitud y en la última fila.
