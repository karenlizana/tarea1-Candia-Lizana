#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

class arr_extensible {

private:

int* B;
int tamanioA;
int capacidadB;

public:

arr_extensible(){}

~arr_extensible(){
    delete[] B;
}

bool setValue(unsigned long i, int v);
int getValue(unsigned long i);
void append(int v);
void remove();
unsigned long size();


};

/* ****
* TipoFuncion : Bool
* NombreFuncion: SetValue
******
* Resumen Funcion: Retorna verdadero o falso dependiendo si la posición i existe dentro del arreglo, además si esta existe, le agrega 
el valor de la variable v.
******
* Input
* TipoParametro: Unsinged long, int
* NombreParametro : i,v
* DescripcionParametro: i: numero entero sin signo que marca una posición en el arreglo. v: valor entero que se agrega al arreglo.
* .......
******
* Returns
* TipoRetorno: Retorna un booleano
* Descripcion retorno: Retorna verdadero o falso dependiendo si la posición i existe dentro del arreglo, además si esta existe, le agrega 
el valor de la variable v.
**** */

bool arr_extensible::setValue(unsigned long i, int v){
int y = i; // ajustamos el tipo de parametro para que el if compare dos variables del mismo tipo.
if (y < tamanioA){
    B[y] = v;
    return true;
} else {
    return false;
}
}

/* ****
* TipoFuncion : Int 
* NombreFuncion: getValue
******
* Resumen Funcion: Recibe una posicion para el arreglo, evalua si esta p
******
* Input
* tipoParametro: Unsigned long
* NombreParametro : i
* Descripcion Parametro: Número entero positivo que marca la posicion en el arreglo.
* .......
******
* Returns 
* TipoRetorno: Retorna un entero
* Descripcion retorno: Retorna el valor de la posicion i en el arreglo.
**** */

int arr_extensible::getValue(unsigned long i){
    int y = i; // ajustamos el tipo de parametro para que el if compare dos variables del mismo tipo.
    if (tamanioA > y) {
        return B[y];
    } else {
        exit(1);
    }
}  

/* ****
* TipoFuncion : Void
* NombreFuncion: append
******
* Resumen Funcion: Agrega un valor entero v a la última posición, si esta está ocupada, entonces el arreglo se multiplica su espacio.
******
* Input
* tipoParametro: int
* NombreParametro : v
* Descripcion Parametro: Un valor entero que se le agrega al arreglo.
* .......
******
* Returns
* TipoRetorno: void/vacio
* Descripcion retorno: la función no retorna nada, solo realiza modificaciones.
**** */

void arr_extensible::append(int v){

int* Bcopia;

   if(tamanioA<capacidadB){  //Si el tamaño del arreglo B tiene espacio
    B[tamanioA] = v; 
    tamanioA++; 
   }else{
    int nuevacapacidadB = 1;
    while(nuevacapacidadB<=tamanioA){ // si no hay espacio, calculamos cuanto espacio necesitamos.
        nuevacapacidadB = nuevacapacidadB*2;
    };

    Bcopia = new int [capacidadB];
    
    for(int i=0; i<capacidadB;i++){ //hacemos una copia de B, para poder eliminar la información que tiene y agrandar el arreglo.
        Bcopia[i] = B[i];
    };
    
    delete[] B;
    B = new int [nuevacapacidadB];

    for(int i=0; i<tamanioA;i++){ //pasamos la copia al arreglo original, pero este ya tiene más espacios disponibles.
        B[i] = Bcopia[i];   
    };

    B[tamanioA] = v; //podemos asignar valor en la última casilla 
    tamanioA++;
    capacidadB = nuevacapacidadB; //guardamos la nueva capacidad de B, este valor se modifica en el TDA.
    delete[] Bcopia;
   };
}

/* ****
* TipoFuncion: void
* NombreFuncion: Remove
****** 
* Resumen Funcion: Elimina el contenido del arreglo en la posición de n-1.
******
* Input
* tipoParametro: No requiere
* NombreParametro: No requiere
* Descripcion Parametro: No recibe parametro debido a que las modificaciones se realizan mediante punteros.
* .......
******
* Returns : No retorna 
* TipoRetorno: No retorna
* Descripcion retorno: No retorna nada, ya que solo modifica el arreglo.
**** */

void arr_extensible::remove(){
    if (tamanioA == 0) return; // si no hay arreglo devueve nada.
    tamanioA--;
    if (tamanioA == 0) { // si no hay arreglo devueve nada.
        delete[] B;
        B = nullptr;
        capacidadB = 0;
        return;
    }
    int req = 1;
    while (req < tamanioA) { // Calcula el espacio de B.
        req *= 2;
    }
    if (req < capacidadB) { // Copiamos la información sin el último valor
        int* Bcopia = new int[req];
        for (int i = 0; i < tamanioA; ++i) {
            Bcopia[i] = B[i];
        }
        delete[] B;
        B = Bcopia;
        capacidadB = req;
    }
}   

/* ****
* TipoFuncion : Unsigned long
* NombreFuncion: Size
******
* Resumen Funcion: Función que se utiliza para acceder a la información privada del TDA, y poder utilizarla en la función main.
******
* Input 
* tipoParametro: No recibe parametros.
* NombreParametro: No recibe parametros.
* Descripcion Parametro: No recibe parametros, ya que la función solo es para acceder a información privada del TDA.
* .......
******
* Returns
* TipoRetorno: Unsigned long
* Descripcion retorno: Retorna el tamaño del arreglo A.
**** */

unsigned long arr_extensible::size(){
    return tamanioA;
}

/* ****
* TipoFuncion : Void
* NombreFuncion: leerArchivo
******
* Resumen Funcion: Lee el archivo donde se encuentra los datos del arreglo, y los almacena en un arreglo tipo arr_extensible.
******
* Input
* tipoParametro: const string / arr_extensible
* NombreParametro : nombreArchivo / arreglo
* Descripcion Parametro: nombreArchivo, es la dirección de memoria donde se encuentra el nombre del archivo a abrir
arreglo, es la dirección de memoria del arreglo donde se guardará la información.
* .......
******
* Returns
* TipoRetorno: No retorna
* Descripcion retorno: La función no retorna nada, solo crea un arreglo.
**** */

void leerArchivo(const string& nombreArchivo, arr_extensible& arreglo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    int valor;
    while (archivo >> valor) { //lee la información del archivo hasta que encuentre el -1.
        if (valor == -1) {
            break;
        }
        arreglo.append(valor);
    }

    archivo.close();
}

int main(){
arr_extensible* A = new arr_extensible();
leerArchivo("entrada.txt", *A);

cout << "=== MENU INTERACTIVO ===" << endl;
bool continuar = true;
while (continuar) { // Sale el menu de interacción hasta que se cumpla el 6.
    cout << "\nOpciones disponibles:" << endl;
    cout << "1. setvalue(i, v)" << endl;
    cout << "2. getvalue(i)" << endl;
    cout << "3. append(v)" << endl;
    cout << "4. remove()" << endl;
    cout << "5. size()" << endl;
    cout << "6. Salir" << endl;

    int opcion;
    cin >> opcion;
    if (opcion == 1) {
        unsigned long i;
        int v;
        cout << "Ingrese el indice i y el valor v: ";
        cin >> i >> v;
        if (A->setValue(i, v)) {
            cout << "Valor establecido correctamente." << endl;
        } else {
            cout << "Indice fuera de rango." << endl;
        }
    } else if (opcion == 2) {
        unsigned long i;
        cout << "Ingrese el indice i: ";
        cin >> i;
        try {
            int valor = A->getValue(i);
            cout << "Valor en el indice " << i << ": " << valor << endl;
        } catch (...) {
            cout << "Indice fuera de rango." << endl;
        }
    } else if (opcion == 3) {
        int v;
        cout << "Ingrese el valor v: ";
        cin >> v;
        A->append(v);
        cout << "Valor agregado correctamente." << endl;
    } else if (opcion == 4) {
        A->remove();
        cout << "Ultimo valor removido correctamente." << endl;
    } else if (opcion == 5) {
        cout << "Tamaño actual del arreglo: " << A->size() << endl;
    } else if (opcion == 6) {
        continuar = false;
    } else {
        cout << "Opcion no valida. Intente nuevamente." << endl;
    }
}
delete A;
return 0;
}
