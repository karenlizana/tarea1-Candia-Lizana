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

bool arr_extensible::setValue(unsigned long i, int v){
int y = i;
if (y < tamanioA){
    B[y] = v;
    return true;
} else {
    return false;
}
}

int arr_extensible::getValue(unsigned long i){
    int y = i;
    if (tamanioA > y) {
        return B[y];
    } else {
        exit(1);
    }
}    
void arr_extensible::append(int v){

int* Bcopia;

   if(tamanioA<capacidadB){
    B[tamanioA] = v;
    tamanioA++;
   }else{
    int nuevacapacidadB = 1;
    while(nuevacapacidadB<=tamanioA){
        nuevacapacidadB = nuevacapacidadB*2;
    };

    Bcopia = new int [capacidadB];
    
    for(int i=0; i<capacidadB;i++){
        Bcopia[i] = B[i];
    };
    
    delete[] B;
    B = new int [nuevacapacidadB];

    for(int i=0; i<tamanioA;i++){
        B[i] = Bcopia[i];   
    };

    B[tamanioA] = v;
    tamanioA++;
    capacidadB = nuevacapacidadB;
    delete[] Bcopia;
   };
}

void arr_extensible::remove(){
    if (tamanioA == 0) return;
    tamanioA--;
    if (tamanioA == 0) {
        delete[] B;
        B = nullptr;
        capacidadB = 0;
        return;
    }
    int req = 1;
    while (req < tamanioA) {
        req *= 2;
    }
    if (req < capacidadB) {
        int* Bcopia = new int[req];
        for (int i = 0; i < tamanioA; ++i) {
            Bcopia[i] = B[i];
        }
        delete[] B;
        B = Bcopia;
        capacidadB = req;
    }
}   

unsigned long arr_extensible::size(){
    return tamanioA;
}

void leerArchivo(const string& nombreArchivo, arr_extensible& arreglo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    int valor;
    while (archivo >> valor) {
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
while (continuar) {
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
