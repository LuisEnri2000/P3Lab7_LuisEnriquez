#include <iostream>
#include <string>
#include "Consola.cpp"
#include "CmdError.cpp"


int main() {
	
	string user;
	
	cout << "Ingrese su usuario: ";
	cin >> user;
	
	Consola * consola = new Consola(user, "./logs.bin");
	

	consola->cmd();	
	
	
}


