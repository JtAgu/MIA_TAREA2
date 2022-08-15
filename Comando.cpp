
#include "comando.h"



void Comando::identificacionCMD(Parametros p){
    if(p.Comando=="mkdisk"){ // Se identifica el tipo de comando
        
            crearArchivo();
        
    }else if(p.Comando=="exec"){ // Se identifica el tipo de comando
        if(p.Direccion != " "){ // Se validan los parametros para el comando
        
           exec(p.Direccion);
        }else{
            cout << "Error escribiendo en Disco: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="rep"){ // Se identifica el tipo de comando
        vertodo();
    }
}

void Comando::crearArchivo(){
    // Calculo Tamaño del Archivo
    int size_file = 5*1024;
    

    // Preparacion Bloque
    char bloque[1024];
    for (int i = 0; i < 1024; i++)
    {
        bloque[i] = '\0';
    }

    // Escritura de Bloque en Archivo
    int limite = 0;
    FILE *archivo_binario;
    archivo_binario = fopen("Particion.dk", "w");
    while (limite != size_file)
    {
        fwrite(&bloque, 1024, 1, archivo_binario);
        limite++;
    }
    fclose(archivo_binario);
}


void Comando::vertodo(){
    FILE *archivo_binario;
    MBR ejm;
    int cont = 0;
    archivo_binario = fopen("Particion.dk", "rb+");
    while (!feof(archivo_binario)){
        // Movimiento de puntero y lectura de Struct en archivo binario 
        fseek(archivo_binario,cont*sizeof(MBR), SEEK_SET);
        fread(&ejm, sizeof(ejm), 1, archivo_binario);
        mostrar_struct(ejm);
        cont++;
    }
    cont = 0;
    fclose(archivo_binario);
}



void Comando::mostrar_struct(MBR ejm){
    if(ejm.id > 0 && ejm.Tamano != "" && ejm.time  != ""){
        cout << "ID: ";
        cout << ejm.id;
        cout << ", Tamaño: ";
        cout << ejm.Tamano;
        cout << ", Time: ";
        cout << ejm.time<< endl;
    }
}

void Comando::exec(string Direccion){
    
    FILE* archivo;
    archivo = fopen(Direccion.c_str(), "rb+");
    
}