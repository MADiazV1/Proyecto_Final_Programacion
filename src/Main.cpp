#include <iostream>
#include <string>
#include <ctype.h>
#include <regex>
using namespace std;

/*
 * Jacobo Rodriguez Ochoa
 * Miguel Angel Diaz Valencia
 */

string validar_nombre(){
  const regex verificar("([a-z]+|[A-Z]+)(\\w+)( )([a-z]+|[A-Z]+)(\\w+)( )?([a-z]+|[A-Z]+)?(\\w+)?( )?([a-z]+|[A-Z]+)?(\\w+)?( )?");
  while (true){
  string nombre;
    cout<< "Ingrese su nombre completo: ";
    getline(cin,nombre);
    bool valido = regex_match(nombre,verificar);
    if (valido){
      return nombre;
    } else{
      cout<<"Nombre invalido"<< endl;
    }  
  }
}
//Nombre listo

string validar_correo(){
  const regex verificar("([a-z]+|[A-Z]+)(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  while (true){
  string email;
    cout<< "Ingrese su correo: ";
    getline(cin,email);
    bool valido = regex_match(email,verificar);
    if (valido){
      return email;
    } else{
      cout<<"Correo invalido"<< endl;
    } 
  }
}
//Correo listo

string validar_id(){
  const regex verificar("([0-9]){6,10}");
  
  while(true){
  string cedula;
    cout<< "Ingrese su cedula: ";
    getline(cin,cedula);
    bool valido = regex_match(cedula,verificar);
    if (valido){
      return cedula;
    } else{
      cout<<"Cedula invalida"<< endl;
    }  
  }
}
//Documento listo

void menu(){
  string nombre = validar_nombre();
  string correo = validar_correo();
  string documento = validar_id();
  cout << endl;
  cout << "------------------------------------------------------------" << endl;
  cout << "Nombre: " << nombre << " <Valido>" << endl;
  cout << "Correo: " << correo << " <Valido>" << endl;
  cout << "Documento: " << documento << " <Valido>" << endl;
  cout << "------------------------------------------------------------" << endl;
}

int main() {
  menu();
  return 0;
}