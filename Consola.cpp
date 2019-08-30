
// Clase consola
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Logger.cpp"
#include "CmdError.cpp"

using namespace std;

#ifndef CONSOLA_CPP
#define CONSOLA_CPP

class Consola {
	private:
		char usuario[50];
		Logger* logger;
		int cont;
		
	public:
		
		Consola(string u, string n) {
			setUsuario(u);
			logger = new Logger(usuario, n, 0);
			cont = logger->listar();
		}
		
		void setUsuario(string nombreCompleto)
        {
            const char *ptrNombreCompleto = nombreCompleto.data();
            int numeroCaracteres = nombreCompleto.size();
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            strncpy(usuario, ptrNombreCompleto, numeroCaracteres);
            usuario[numeroCaracteres] = '\0';
    	}
    	
    	void cmd() {
    		
    		
    		string comando = "LIT FAM";
    		
    		while (comando != "exit") {
    			
 
	    			cout << "Comando: ";
	    			cin >> comando;
	    			if (comando != "listar") {
	    				validarComando(comando);
	    				system(comando.c_str());
	    				logger->agregar(new Log(usuario, comando, cont));
	    				//logger->getLogs().push_back(new Log(usuario, comando, logger->getLogs().size() - 1));
	    				cout << "Listo." << endl;
	    				cont++;
	    			}else{
	    				cont = logger->listar();
					}			
			}	
		}
		
		void validarComando(string cmd) {
	
			int err = system(cmd.c_str());
			
			if (err == 1) {
				char mensaje[] = "Error! Ese comando no existe. \n";
				throw CmdError (mensaje);
			}
		}
		
		~Consola() {}

};




#endif

