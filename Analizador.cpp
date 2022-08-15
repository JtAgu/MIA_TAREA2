#include "analizador.h"

vector<string> Analizador::split_txt(string text){ // Split para separar tipo de comando y parametros
    stringstream text_to_split(text);
    string segment;
    vector<string> splited;

    while(std::getline(text_to_split, segment, ' ')){
       splited.push_back(segment);
    }
    return splited;
}

string Analizador::replace_txt(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

void Analizador::analizar(string entrada){
    string entradacmd = entrada;
    // Transformacion de toda la entrada a minusculas
    transform(entradacmd.begin(), entradacmd.end(), entradacmd.begin(), ::tolower);
    vector<string> cmdentrada = split_txt(entradacmd);
    vector<string> parametros;
    string comando = "";
    for(int i = 0; i< cmdentrada.size(); i++){
        if(i == 0){
            comando = cmdentrada.at(i);
        }else{
            parametros.push_back(cmdentrada.at(i));
        }
    }
    // Identificacion de comando, parametros y ejecucion
    identificarParametros(comando, parametros);
}

void Analizador::identificarParametros(string comando, vector<string> parametros){
    string param = "";
    if(comando == "mkdisk"){
        cmd.param.Comando = "mkdisk";
        cmd.identificacionCMD(cmd.param);
    } else if(comando == "rep"){
        cmd.param.Comando = "rep";
        // Ejecucion de metodo
        cmd.identificacionCMD(cmd.param);   
    } else if(comando == "exec"){
        cmd.param.Comando = "exec";

        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-path=") == 0){
                param = replace_txt(param, "-path=", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Direccion = param;
            } else {
                
            }
        }
        // Ejecucion de metodo
        cmd.identificacionCMD(cmd.param);   
    } 
}