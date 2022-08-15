#include "analizador.cpp"

int main(){
    Analizador analisis;
    // Ejemplos de comandos reconocidos
    // crear -t->5 -d->"m" // Crea archivo binario con los parametros especificados.
    // escribir -id->1 -nombre->"abc" -telefono->123 -direccion->"def" -x->10 // Escribe en archivo binario un struct con los datos especificados la cantidad de veces que fue definido.
    // vertodo // Muestra todos los registros registrados en el archivo binario.
    // verx -x->5 // Muestra el registro en la posicion X del archivo binario.
    // eliminarx -x->3 // Elimina el registro en la posicion X del archivo binario.
    string entradacmd = "";
    /*while(entradacmd != "exit"){
        cout << "*----------------------------------------------------------*" << endl;
        cout << "*                      [MIA] HT 2                     *" << endl;
        cout << "*----------------------------------------------------------*" << endl;
        cout << "[MIA]@Ejemplo3:~$ ";
        getline(cin,entradacmd);
        analisis.analizar(entradacmd);
    }*/
    
    getline(cin,entradacmd);
    
    ifstream archivo(entradacmd.c_str());
    string linea="";
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
        cout << "Una línea: ";
        cout << linea << endl;
    }
    getline(cin,entradacmd);
    return 0;
}