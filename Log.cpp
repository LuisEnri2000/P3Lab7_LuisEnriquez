// Clase clase
#include <iostream>
#include <string.h>
#include <string>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

using namespace std;

#ifndef LOG_CPP
#define LOG_CPP

class Log {
	private:
		char usuario[50];
		char comando[50];
		int numero;
		
	public:
		
		Log(){
		}
		
		Log(string u, string c, int num) {
			setUsuario(u);
			setComando(c);
			numero = num;
		}
		
		string print() {
			string temp = comando;
			string temp2 = usuario;
			
			stringstream ss;
			
			ss << numero;
			
			string num;
			
			ss >> num;
			
			string yee = "Num: " + num;
			yee += " usuario: " + temp2 + " cmd: " + temp;
			
			return yee;
		}
		
		void setUsuario(string nombreCompleto)
        {
            const char *ptrNombreCompleto = nombreCompleto.data();
            int numeroCaracteres = nombreCompleto.size();
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            strncpy(usuario, ptrNombreCompleto, numeroCaracteres);
            usuario[numeroCaracteres] = '\0';
    	}
		
		void setComando(string nombreCompleto)
        {
            const char *ptrNombreCompleto = nombreCompleto.data();
            int numeroCaracteres = nombreCompleto.size();
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            strncpy(comando, ptrNombreCompleto, numeroCaracteres);
            comando[numeroCaracteres] = '\0';
    	}
		
		~Log() {}

};
#endif
