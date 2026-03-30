# tarea1-Candia-Lizana

## Integrantes

* Karen Lizana
* Matias Candia

## Descripción

Programa que modifica un arreglo, el cual puede aumentar o disminuir su tamaño según se le pida al sistema, este 
puede realizar las siguientes acciones:

- Agregar elementos
- Eliminar el último elemento
- Obtener un valor por índice
- Modificar un valor
- Ver el tamaño del arreglo

También permite leer datos desde un archivo y usar las funciones mediante una consola.

## Características técnicas

- Sistema operativo: Linux (Ubuntu 24.04.3 / WSL)
- Lenguaje: C++
- Compilador: g++ 13.3.0
- Estándar: C++11


## Cómo funciona

El programa una memoria dinámica para manejar un arreglo, usamos un arreglo inicial A el cual se encuentra en el interior de B, el tamaño del arreglo se agranda
cuando el arreglo B está lleno y se achica cuando se vacía. 

## Lectura de archivo

El nombre del archivo debe llamarse "entrada.txt"

## Compilación

g++ tarea1-Candia-Lizana.cpp -o tarea1 -Wall


