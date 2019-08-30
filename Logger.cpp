// Clase clase
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Log.cpp"

using namespace std;

#ifndef LOGGER_CPP
#define LOGGER_CPP

class Logger {
	private:
		char usuario[50];
		char nombre[50];
		int numero;
		vector<Log*> logs;
		
	public:
		
		Logger(string u, string n, int num) {
			setUsuario(u);
			setNombre(n);
			numero = num;
		}
		
		vector<Log*> getLogs() {
			return logs;
		}
		
		void setUsuario(string nombreCompleto)
        {
            const char *ptrNombreCompleto = nombreCompleto.data();
            int numeroCaracteres = nombreCompleto.size();
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            strncpy(usuario, ptrNombreCompleto, numeroCaracteres);
            usuario[numeroCaracteres] = '\0';
    	}
		
		void setNombre(string nombreCompleto)
        {
            const char *ptrNombreCompleto = nombreCompleto.data();
            int numeroCaracteres = nombreCompleto.size();
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            strncpy(nombre, ptrNombreCompleto, numeroCaracteres);
            nombre[numeroCaracteres] = '\0';
    	}
		
		~Logger() {}
		
		void agregar(Log * a){
			ifstream leer("./logs.bin", ios::in | ios::binary);
			fstream escribir("./logs.bin", ios::out | ios::binary | ios::app);	
			
			if(!escribir){
				cout<<"Problema al abrir el archivo"<<endl;
				system("pause");
				return ;
			}
			Log x = *a;
			
			
			escribir.seekp(0,ios::end); //seekp = seek put //recupere 0 bytes, se va al fin del archivo
			escribir.write(reinterpret_cast<char *>(&x), sizeof(x)); // escribir.write(conversion a char, tamanho del objeto);
			escribir.close();
		}
		
		int listar(){
			ifstream leer("./logs.bin", ios::in | ios::binary);
			fstream escribir("./logs.bin", ios::out | ios::binary | ios::app);
			
			Log y;
				
			if(!leer){
				cout<<"Problema al abrir el archivo"<<endl;
				system("pause");
				return 0;
			}
			
			leer.seekg(0,ios::beg); //beg = begin
			
			cout << "...:: COMANDOS ::..." << endl;
			
			//for (int i = 0; i < logs.size(); i++) {
				//logs.at(i)->print();
				//cout << endl;
			//}
			
			int x = 0;
			while( !leer.eof() ) {
				leer.read(reinterpret_cast<char*>(&y), sizeof(Log));
				cout << y.print() << endl;
				x++;
			}

			leer.close();
			return x;
		}

};
#endif
