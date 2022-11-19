#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string validar_nombre(){ 
  const char ESPACIO = ' ';
  string nombre;
  bool activo = true;
  while(activo){
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    if(nombre.empty()){
      cout << "Casilla vacia" << endl;
      continue;
    }else{
      for(int i=0;i<nombre.length();i++){
        if(!isalpha(nombre[i]) && nombre[i] != ESPACIO){
          cout << "*Nombre no valido*" << endl;
          activo = true;
          break;
        }else{
          activo = false;
          continue;
        }
      }
    }
  }
  return nombre;
}
//Nombre listo

string validar_correo(){
  const string COM = "com";
  bool activo = true;
  string correo;

  while(activo){
    cout << "Ingrese su correo: "; 
    getline(cin, correo);
    if(correo.empty()){
      cout << "Casilla vacia" << endl;
      continue;
    }else{
      string str = correo;
      bool arroba;
      for(int i=0;i<str.length();i++){
        if(str[i] ==  '@'){
          arroba = true;
          break;
        }else{
          continue;
        }
      }
      if(!arroba){
        cout << "Correo no valido (@)" << endl;
        continue;
      }else{
        str = str.substr(str.find('.')+1);
        if(str != COM){
          cout << "Correo no valido (.com)" << endl;
          continue;
        }else{
          activo = false;
        }
      }
    }
  }
  return correo;
}
//Correo listo

string validar_id(){
  const char ESPACIO = ' ';
  bool activo = true;
  string cedula;
  while(activo){
    cout << "Ingrese su cedula: ";
    getline(cin,cedula);
    if(cedula.empty()){
      cout << "Casilla vacia" << endl;
      continue;
    }else{
      int i=0;
      while(cedula[i]){
        if(!isdigit(cedula[i])  || cedula[i]== ESPACIO || (i>=10)){
          cout<< "Este numero de cedula es invalido"<< endl; 
          break;
        }else{
          i++;
        }
      }
      if (i==cedula.length()){
        return cedula;
      }
    }
  }
  return 0;
}
//Documento listo

string validar_fecha_nacimiento(){
    while(true){
    cout << "Ingrese su fecha de nacimiento DD MM AA (separelos con espacio): ";
    string D="";
    string M="";
    string A="";
    cin>> D >> M >> A;

    int AA=stoi(A);
    int MM= stoi(M);
    int DD= stoi(D);
    string DDMMAA = D+"/"+M+"/"+A;

    if (MM==2 && DD>28){
      if ( ((AA%4== 0 && (AA%100!=0 || AA%400==0))) && DD==29){ 
        return DDMMAA;
      }else{
        cout<< "Ingrese una fecha de nacimiento valida" << endl;
        continue;
      }
    }
    if ((MM== 4 || MM== 6 || MM==9 || MM==11) && DD>30){
        cout<< "Ingrese una fecha de nacimiento valida" << endl;
        continue;
    } else if(DD>31){
        cout<< "Ingrese una fecha de nacimiento valida" << endl;
        continue;
    }
    if (MM>12 || AA>2022){
        cout<< "Ingrese una fecha de nacimiento valida" << endl;
        continue;
    }
    return DDMMAA;
  }
}
//Fecha listo

void menu(){
  string nombre = validar_nombre();
  string correo = validar_correo();
  string documento = validar_id();
  string fecha = validar_fecha_nacimiento();
  cout << endl;
  cout << "------------------------------------------------------------" << endl;
  cout << "Nombre: " << nombre << " <Valido>" << endl;
  cout << "Correo: " << correo << " <Valido>" << endl;
  cout << "Documento: " << documento << " <Valido>" << endl;
  cout << "Fecha de nacimeinto (DD/MM/AA): " << fecha << " <Valido>" << endl;
  cout << "------------------------------------------------------------" << endl;
}

int main() {
  menu();
  return 0;
}