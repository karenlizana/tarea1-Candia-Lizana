# tarea1-Candia-Lizana

# Tarea 1 - Estructuras de Datos

## Integrantes

* Karen Lizana
* (Nombre compañero/a)

---

## Descripción

Este programa implementa un arreglo extensible en C++.
Permite guardar números enteros y modificar el tamaño del arreglo durante la ejecución.

El programa puede:

* Agregar elementos
* Eliminar el último elemento
* Obtener un valor por índice
* Modificar un valor
* Ver el tamaño del arreglo

También permite leer datos desde un archivo y usar un menú por consola.

---

## Características técnicas

* Sistema operativo: Linux (Ubuntu / WSL)
* Lenguaje: C++
* Compilador: g++
* Estándar: C++11

---

## Cómo funciona

El programa usa memoria dinámica para manejar un arreglo.

Internamente:

* Se usa un arreglo base llamado B
* El tamaño del arreglo cambia automáticamente
* Cuando se llena, se agranda
* Cuando se vacía, se achica

Para esto se usa:

* `new[]` para crear memoria
* `delete[]` para liberar memoria

---

## Lectura de archivo

El programa lee números desde un archivo, uno por línea, hasta encontrar un -1.

Ejemplo:

```id="v1k3tp"
10
12
13
-1
```

---

## Compilación

```bash id="6cz2yj"
make
```

---

## Ejecución

```bash id="g9s0m3"
make run
```

---

## Limpieza

```bash id="8z6r8b"
make clean
```

---

## Observaciones

* No se usa STL (vector, etc.)
* Se trabaja con punteros y memoria dinámica
* El programa fue probado en Linux
