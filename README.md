# tarea1-Candia-Lizana

## Integrantes

* Karen Lizana
* Matias Candia

## Descripción

Este programa implementa un arreglo extensible en C++.
Permite guardar números enteros y modificar el tamaño del arreglo durante la ejecución.

El programa puede:

- Agregar elementos
- Eliminar el último elemento
- Obtener un valor por índice
- Modificar un valor
- Ver el tamaño del arreglo

También permite leer datos desde un archivo y usar un menú por consola.


## Características técnicas

- Sistema operativo: Linux (Ubuntu 24.04.3 / WSL)
- Lenguaje: C++
- Compilador: g++ 13.3.0
- Estándar: C++11


## Cómo funciona

El programa usa memoria dinámica para manejar un arreglo.
Se usa un arreglo base llamado B, wl tamaño del arreglo cambia automáticamente y cuando se llena, se agranda y cuando se vacía, se achica.

## Lectura de archivo

El nombre del archivo debe llamarse "entrada.txt"

## Compilación

g++ tarea1-Candia-Lizana.cpp -o tarea1 -Wall


