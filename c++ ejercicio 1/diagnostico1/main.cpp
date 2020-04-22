#include <iostream>
#include<string>
#include <cctype>
#include <algorithm>

using namespace std;

void devContLetr(string palabra){

    //Se pasa toda la palabra a minusculas
    std::for_each(palabra.begin(), palabra.end(), [](char & c){
	c = ::tolower(c);
    });

    //se inicializa un booleano para que en caso de tener caracteres que no sean letras no continue
    bool continua = true;
    int i = 0;
	
    //ciclo for para comprobar que los caracteres se encuentren en el rango ascii de las letras
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
    
    //condicion para continuar si solo contiene letras
    if(continua == true){
        for(i=0;i<palabra.length();i++){
	   
            //si el ciclo va en la segunda letra o mas, y ademas es igual a la anterior se suma 1 a la cantidad de veces que se repite
            if((i!=0) && (palabra[i] == palabra[i-1])){
                cantidad += 1;
            }
	    //si la letra es distinta de la anterior y ademas no corresponde a la primera letra de la palabra se suma esta misma y se agrega al string resultado
            if((palabra[i] != palabra[i-1])&&(i!=0)){
                cantidad += 1;
                resultado += palabra[i-1] + to_string(cantidad);
	        //se vuelve la cantidad a 0
                cantidad = 0;
            }
	    //Este if es para cuando este en la ultima letra ya que el primer if no sirve debido a que se pasaria el tope y apuntaria fuera del "arreglo" palabra
            if(i == (palabra.length()-1)){
                cantidad += 1;
                resultado += palabra[i] + to_string(cantidad);
            }
        }
    }
    if(continua == false){
        cout << "La palabra debe contener solo letras" << endl;
    }
    //Imprime el resultado que serian las letras+cantidad de veces que se encuentran formato LetraCantidadLCLCLCLCLC....
    cout << resultado << endl;
}


int main()
{
    while(1==1){
        string Palabra;
	//palabra a trabajar se pide por teclado
        cout << "Ingrese la palabra a trabajar: ";
        cin >> Palabra;
	
        devContLetr(Palabra);
        system("pause");
        system("CLS");
    }
    return 0;
}
