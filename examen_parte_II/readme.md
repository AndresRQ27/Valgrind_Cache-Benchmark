**Las pruebas fueron realizadas en Ubuntu 18.04 64-bits en una máquina virtual con 5120MB de RAM y 4 procesadores. El tipo de disco es VDI (dynamically allocated storage)

Para ejecutar el programa, se necesita valgrind, el cual se puede instalar con el comando:

	>> sudo apt-get install valgrind kcachegrind graphviz

Para visualizar las pruebas, se puede usar el script adjunto con el comando:
	
	>> cd Examen-Arquitectura_de_Computadores/examen_parte_II
	>> ./test_script
	*Puede observar que en el script contiene comandos para la compilación de la prueba con lista y vector y luego comandos de valgrind y massif
	*En caso que presente un problema como "bash: ./test_script: Permission denied.", ejecutar:
		>> chmod 755 test_script
