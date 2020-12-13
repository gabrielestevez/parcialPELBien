#include <iostream>
#include <fstream>

using namespace std;

int cp;
string municipio;
int poblacion;
int altura;
int superficie;

string archivo = "../avila.tsv";

//ifstream fin("../avila.tsv");//Declaramos fin como variable de entrada

void nMunicipios() {
    ifstream fin(archivo);//Declaramos fin como variable de entrada
    try {
        int numeroMun = 0;
        while(!fin.eof()){
            fin>>cp>>municipio>>poblacion>>altura>>superficie;
            numeroMun ++;
        }
        cout << "\n" << "El numero de municipios es : " << numeroMun;
    }
    catch (...) {
        fin.close();
        cout << "FIN DE ARCHIVO" << endl;
    }
}

void promedioAltura(){
    ifstream fin(archivo);//Declaramos fin como variable de entrada
    try{
        int alturaTotal;
        int alturaMedia;
        while(!fin.eof()){
            fin>>cp>>municipio>>poblacion>>altura>>superficie;
            alturaTotal = alturaTotal + altura;
        }
        alturaMedia = alturaTotal / 248;
        cout<< "\n"<<"La altura media es: " << alturaMedia;
    }
    catch (...) {
        fin.close();
        cout << "FIN DE ARCHIVO" << endl;
    }
}
void alturaMax(){
    ifstream fin(archivo);//Declaramos fin como variable de entrada
    try{
        int alturaMaxima = 0;
        while(!fin.eof()){
            fin>>cp>>municipio>>poblacion>>altura>>superficie;
            if (altura > alturaMaxima ){
                alturaMaxima = altura;
            }
        }
        cout << "\n" << "La altura maxima es: " << alturaMaxima;
    }
    catch(...){
        fin.close();
        cout << "FIN DE ARCHIVO" << endl;
    }
}

void alturaMin(){
    ifstream  fin(archivo);
    try{
        int alturaMinima;
        while(!fin.eof()){
            fin>>cp>>municipio>>poblacion>>altura>>superficie;
            if(altura <= alturaMinima){
                alturaMinima = altura;
            }
        }
        cout << "\n" << "La altura minima es: " << alturaMinima;
    }
    catch(...){
        fin.close();
        cout << "FIN DE ARCHIVO" << endl;
    }
}

void masPoblada(){
    ifstream fin(archivo);//Declaramos fin como variable de entrada
    try{
        int poblacionMaxima = 0;
        string nombreMunicipio;
        while(!fin.eof()){
            fin>>cp>>municipio>>poblacion>>altura>>superficie;
            if (poblacion > poblacionMaxima ){
                poblacionMaxima = poblacion;
                nombreMunicipio = municipio;
            }
        }
        cout << "\n" << "La poblacion maxima es: " << nombreMunicipio << " con "<< poblacionMaxima;
    }
    catch(...){
        fin.close();
        cout << "FIN DE ARCHIVO" << endl;
    }
}

void menosPoblada(){
    ifstream fin(archivo);//Declaramos fin como variable de entrada
    try{
        int poblacionMin;
        string nombreMunicipio;
        while(!fin.eof()){
            fin>>cp>>municipio>>poblacion>>altura>>superficie;
            if (poblacion <= poblacionMin ){
                poblacionMin = poblacion;
                nombreMunicipio = municipio;
            }
        }
        cout << "\n" << "La poblacion minima es: " << nombreMunicipio << " con "<< poblacionMin << "\n";
    }
    catch(...){
        fin.close();
        cout << "FIN DE ARCHIVO" << endl;
    }
}


void habYAltura(){ //municipios con mas de 40 hab y 900 metros de altura
    ifstream fin("../avila.tsv");//Declaramos fin como variable de entrada
   try{
       cout<< "Los municipios con más de 40 hab y a +900 m son: " << "\n";
       string nombreMun;
       while(!fin.eof()){
           fin>>cp>>municipio>>poblacion>>altura>>superficie;
           if (poblacion > 40){
               if(altura > 900){
                   nombreMun = municipio;
                   cout<< nombreMun << "\n";
               }
           }
       }
   }
   catch (...) {
       fin.close();
       cout << "FIN DE ARCHIVO" << endl;
   }
}



int main(){
    nMunicipios();
    promedioAltura();
    alturaMax();
    alturaMin();
    masPoblada();
    menosPoblada();
   // habYAltura();
    return 0;
}