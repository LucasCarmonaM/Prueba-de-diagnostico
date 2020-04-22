#include <iostream>
#include<string>
#include <cctype>
#include <algorithm>

using namespace std;

void devContLetr(string palabra){


    std::for_each(palabra.begin(), palabra.end(), [](char & c){
	c = ::tolower(c);
    });


    bool continua = true;
    int i = 0;

    for(i=0;i<palabra.length();i++){
        if(continua == false){
            break;
        }
        if ((int(palabra[i])<97) || (int(palabra[i])>122)){
            continua = false;
            break;
        }
    }

    string resultado = "";
    int cantidad = 0;
    if(continua == true){
        for(i=0;i<palabra.length();i++){

            if((i!=0) && (palabra[i] == palabra[i-1])){
                cantidad += 1;

            }
            if((palabra[i] != palabra[i-1])&&(i!=0)){
                cantidad += 1;
                resultado += palabra[i-1] + to_string(cantidad);
                cantidad = 0;
            }
            if(i == (palabra.length()-1)){
                cantidad += 1;
                resultado += palabra[i] + to_string(cantidad);
            }
        }
    }
    if(continua == false){
        cout << "La palabra debe contener solo letras" << endl;
    }
    cout << resultado << endl;
}


int main()
{
    while(1==1){
        string Palabra;
        cout << "Ingrese la palabra a trabajar: ";
        cin >> Palabra;

        devContLetr(Palabra);
        system("pause");
        system("CLS");
    }
    return 0;
}
