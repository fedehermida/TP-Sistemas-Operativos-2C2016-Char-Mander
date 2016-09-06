/*
 * entrenador.hs
 *
 */

#ifndef ENTRENADOR1_ENTRENADOR_H_
#define ENTRENADOR1_ENTRENADOR_H_

#include <pthread.h>
#include <semaphore.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "commons/log.h"
#include "commons/config.h"
#include "commons/collections/queue.h"
#include "conexiones.h"


typedef struct {
	int port_Mapa;
	char* ip_Mapa;
} t_conexion;

typedef struct {
<<<<<<< HEAD
	char* nombreMapa;
	char** objetivos;
	int puerto;
	char* ip;
=======
 char* nombreMapa;
 char** objetivos;
 char* ip;
 int puerto;
>>>>>>> 9efe9181423861d0a88fc1c73aa7622a19dca288
} t_mapa;



typedef struct {
 char* simbolo;
 char* nombre;
 char* rutaPokedex;
 int cantVidas;
 t_list* hojaDeViaje;
} t_entrenador;

//Logger
t_log* logEntrenador;

//Configuracion
t_config configEntrenador;

//Socket y Conexiones
int socketEntrenador;


//Obtiene los datos desde la metada del entrenador
void getMetadataEntrenador(t_entrenador* datosEntrenador, t_mapa* mapas);

t_posicion* avanzarPosicionInts(t_posicion* posicionActual,t_posicion* posicionDestino);

#endif /* ENTRENADOR1_ENTRENADOR_H_ */
