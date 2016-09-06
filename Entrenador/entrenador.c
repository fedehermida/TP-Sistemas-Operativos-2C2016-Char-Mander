/*
 * entrenador.c
 *
 */

#include "entrenador.h"

int main(int argc, char **argv) {


	t_entrenador* datosEntrenador = malloc(sizeof(t_entrenador));



	//datosEntrenador->nombre = NULL;
	//datosEntrenador->rutaPokedex = NULL;
	char *logFile = NULL;

	//assert(("ERROR - No se pasaron argumentos", argc > 1)); // Verifica que se haya pasado al menos 1 parametro, sino falla

	//Parametros
	int i;
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "") == 0) {
			datosEntrenador->nombre = argv[i + 1];
			printf("Nombre Entrenador: '%s'\n", datosEntrenador->nombre);
		}
		if (strcmp(argv[i], "") == 0) {
			datosEntrenador->rutaPokedex = argv[i + 1];
			printf("Ruta Pokedex: '%s'\n", datosEntrenador->rutaPokedex);
		}
		if (strcmp(argv[i], "") == 0) {
			logFile = argv[i + 1];
			printf("Log File: '%s'\n", logFile);
		}
	}

	//assert(("ERROR - No se paso el nombre del entrenador como argumento", datosEntrenador->nombre != NULL));

	//assert(("ERROR - No se paso el archivo de log como argumento", logFile != NULL));//Verifies if was passed the Log file as parameter, if DONT FAILS

	//Creo el archivo de Log
	//logEntrenador = log_create(logFile, "ENTRENADOR", 0, LOG_LEVEL_TRACE);

	t_mapa* mapas = malloc(sizeof(t_mapa));

	//Levanto los datos del metadata de Entrenador

	getMetadataEntrenador(datosEntrenador, mapas);
	//CONFIGURACION DEL ENTRENADOR


	//faltan los objetivos



	free(datosEntrenador);
	return EXIT_SUCCESS;

}


//Funcion que levanta los datos del entrenador

void getMetadataEntrenador(t_entrenador* datosEntrenador, t_mapa* mapa) {

<<<<<<< HEAD
 //t_entrenador* datosEntrenador = malloc(sizeof(t_entrenador));
 t_config* configEntrenador = malloc(sizeof(t_config));
 t_list* listaDeMapas = list_create();
  configEntrenador->path = string_from_format("/home/utnso/Pokedex/Entrenadores/%s/metadata","Red");
  configEntrenador = config_create(configEntrenador->path);

  datosEntrenador->nombre = config_get_string_value(configEntrenador, "nombre");
  datosEntrenador->simbolo = config_get_string_value(configEntrenador, "simbolo");
  datosEntrenador->cantVidas = config_get_int_value(configEntrenador, "vidas");
  char** hojaDeViaje = config_get_array_value(configEntrenador,
    "hojaDeViaje");

  printf("El nombre del Entrenador es: %s \n", datosEntrenador->nombre);
  printf("El simbolo que representa al Entrenador es: %s \n",
    datosEntrenador->simbolo);
  printf("La cantidad de vidas del Entrenador es: %d \n", datosEntrenador->cantVidas);

  int i = 0;
  while (hojaDeViaje[i] != NULL) {

   mapa->nombreMapa = hojaDeViaje[i];

   printf("El mapa que debe recorrer el datosEntrenador: %s \n",
     mapa->nombreMapa);

   char* strConcat = string_new();
   string_append(&strConcat, "obj[");
   string_append(&strConcat, mapa->nombreMapa);
   string_append(&strConcat, "]");

   //entrenador->mapa->objetivos=config_get_array_value(configEntrenador,"obj[PuebloPaleta]");

   mapa->objetivos = config_get_array_value(configEntrenador, strConcat);
   int j = 0;
   while (mapa->objetivos[j] != NULL) {

    if (mapa->objetivos[j + 1] != NULL) {
     printf("%s, ", mapa->objetivos[j]);

    } else {
     printf("%s \n", mapa->objetivos[j]);
    }

    j++;

   }

   t_config* configMapa = malloc(sizeof(t_config));

   configMapa->path = string_from_format("/home/utnso/Pokedex/Mapas/%s/metadata",mapa->nombreMapa);
   configMapa = config_create(configMapa->path);
   mapa->ip = config_get_string_value(configMapa, "IP");
   mapa->puerto = config_get_int_value(configMapa,"Puerto");
   printf("La IP del mapa %s es: %s \n", mapa->nombreMapa,mapa->ip);
   printf("El puerto del mapa %s es: %d \n", mapa->nombreMapa,mapa->puerto);

   list_add(listaDeMapas, (void*)mapa);

   i++;
  }

  printf("La cantidad de mapas a recorrer es: %d \n", listaDeMapas->elements_count);

  recorrerEPrintearLista(listaDeMapas);
=======
	//t_entrenador* datosEntrenador = malloc(sizeof(t_entrenador));
	t_config* configEntrenador = malloc(sizeof(t_config));
	t_list* listaDeMapas = list_create();
		configEntrenador->path = string_from_format("/home/utnso/Pokedex/Entrenadores/%s/metadata","Red");
		configEntrenador = config_create(configEntrenador->path);

		datosEntrenador->nombre = config_get_string_value(configEntrenador, "nombre");
		datosEntrenador->simbolo = config_get_string_value(configEntrenador, "simbolo");
		datosEntrenador->cantVidas = config_get_int_value(configEntrenador, "vidas");
		char** hojaDeViaje = config_get_array_value(configEntrenador,
				"hojaDeViaje");

		printf("El nombre del Entrenador es: %s \n", datosEntrenador->nombre);
		printf("El simbolo que representa al Entrenador es: %s \n",
				datosEntrenador->simbolo);
		printf("La cantidad de vidas del Entrenador es: %d \n", datosEntrenador->cantVidas);

		int i = 0;
		while (hojaDeViaje[i] != NULL) {

			mapa->nombreMapa = hojaDeViaje[i];

			printf("El mapa que debe recorrer el datosEntrenador: %s \n",
					mapa->nombreMapa);

			char* strConcat = string_new();
			string_append(&strConcat, "obj[");
			string_append(&strConcat, mapa->nombreMapa);
			string_append(&strConcat, "]");

			//entrenador->mapa->objetivos=config_get_array_value(configEntrenador,"obj[PuebloPaleta]");

			mapa->objetivos = config_get_array_value(configEntrenador, strConcat);
			int j = 0;
			while (mapa->objetivos[j] != NULL) {

				if (mapa->objetivos[j + 1] != NULL) {
					printf("%s, ", mapa->objetivos[j]);

				} else {
					printf("%s \n", mapa->objetivos[j]);
				}

				j++;

			}

			t_config* configMapa = malloc(sizeof(t_config));

			configMapa->path = string_from_format("/home/utnso/Pokedex/Mapas/%s/metadata",mapa->nombreMapa);
			configMapa = config_create(configMapa->path);
			mapa->ip = config_get_string_value(configMapa, "IP");
			mapa->puerto = config_get_int_value(configMapa,"Puerto");
			printf("La IP del mapa %s es: %s \n", mapa->nombreMapa,mapa->ip);
			printf("El puerto del mapa %s es: %d \n", mapa->nombreMapa,mapa->puerto);

			list_add(listaDeMapas, (void*)mapa);

			i++;
		}

		printf("La cantidad de mapas a recorrer es: %d \n", listaDeMapas->elements_count);

		recorrerEPrintearLista(listaDeMapas);
>>>>>>> 9efe9181423861d0a88fc1c73aa7622a19dca288


}

void recorrerEPrintearLista(t_list* unaLista){
 int i=0;
 t_mapa* unMapa=malloc(sizeof(t_mapa));
 while(unaLista->elements_count!=i){

 unMapa=(t_mapa*)list_get(unaLista,i);
 printf("%s \n",unMapa->nombreMapa);
 i++;
 }
}
//Cambia la posicion del entrenador segun determine el mapa.

char avanzarPosicion(char unaPosicion,char* posicionDestino){
 char* miPosicion=string_new();
 char* posicionQueQuieroLlegar=string_new();
 string_append(&miPosicion,unaPosicion);
 string_append(&posicionQueQuieroLlegar,posicionDestino);
 char** posicionXY;
 char** posicionDestinoXY;
 posicionXY=string_split(miPosicion,";");
 int posicionX=atoi(posicionXY[0]);
 int posicionY=atoi(posicionXY[1]);

 posicionDestinoXY=string_split(posicionQueQuieroLlegar,";");
 int posicionXDestino=atoi(posicionDestinoXY[0]);
 int posicionYDestino=atoi(posicionDestinoXY[1]);
 if(posicionX>posicionXDestino){
  posicionX--;
 }
 if(posicionX<posicionXDestino){
  posicionX++;
 }
 if(posicionY>posicionYDestino){
  posicionY--;
 }
 if(posicionY<posicionYDestino){
  posicionY++;
 }
 char* nuevaPosicion=string_new();
 string_append_with_format(&nuevaPosicion,"%i",posicionX);
 string_append(&nuevaPosicion,";");
 string_append_with_format(&nuevaPosicion,"%i",posicionY);
 strcpy(miPosicion,nuevaPosicion);
 return miPosicion;

}

void chequearVidas(t_entrenador* unEntrenador){
 if(unEntrenador->cantVidas==0){
  printf("Te quedaste sin vidas \n");
  //borrarDirectorioDeBill();
  shutdown(socketEntrenador,2);
 }else{
  unEntrenador->cantVidas--;
  printf("Perdiste una vida, te queda:%i \n",unEntrenador->cantVidas);
 }
}




