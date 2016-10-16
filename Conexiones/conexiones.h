#ifndef SOCKET_H_
#define SOCKET_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <commons/string.h>
#include <pthread.h>
#include <assert.h>

#include "pkmn/battle.h"
#include <pkmn/factory.h>

typedef struct {
	int socketServer;
	int socketCliente;
} t_server;

typedef struct {
	int socketServer;
	int socketClient;
} t_datosConexion;

typedef struct{
	int operacion;
	int programCounter;
	int quantum;
} t_MensajeMapa_Entrenador;

typedef struct{
	char* nombreEntrenador;
	char id; //simbolo
	int operacion;
	char objetivoActual;
} t_MensajeEntrenador_Mapa;

typedef struct{
	int operacion;
	char* rutaArchivo;
	int offset;
	int cantidadDeBytes;
} t_MensajeLeerPokedexClient_PokedexServer;

typedef struct{
	int operacion;
	char* rutaArchivo;
	char* bufferAEscribir;
	int offset;
	int cantidadDeBytes;
} t_MensajeEscribirPokedexClient_PokedexServer;

typedef struct{
	int operacion;
	char* rutaDirectorioPadre;
	unsigned char nombreRuta[17];
} t_MensajeCrearDirectorioPokedexClient_PokedexServer;

typedef struct{
	int operacion;
	char* rutaDeArchivo;
	char* nuevoNombre;
} t_MensajeRenombrarArchivoPokedexClient_PokedexServer;

typedef struct{
	int operacion;
} t_MensajePokedexClient_PokedexServer;

typedef struct{
	int operacion;
} t_MensajePokedexServer_PokedexClient;

//IMPORTANTE --> Nomeclatura de Serializadores y Deserealizadores
//1) serializar<DesdeProceso>_<HastaProceso> ()
//2) deserialiar<HastaProceso>_<DesdeProceso> ()

void serializarEntrenador_Mapa(t_MensajeEntrenador_Mapa* value, char *buffer);
void deserializarMapa_Entrenador(t_MensajeEntrenador_Mapa* value, char *bufferReceived);

void serializarMapa_Entrenador(t_MensajeMapa_Entrenador *value, char *buffer);
void deserializarEntrenador_Mapa(t_MensajeMapa_Entrenador *value, char *bufferReceived);

void serializarPokedexClient_PokedexServer(t_MensajePokedexClient_PokedexServer *value, char *buffer);
void deserializarPokedexServer_PokedexClient(t_MensajePokedexClient_PokedexServer *value, char *bufferReceived);

void serializarPokedexServer_PokedexClient(t_MensajePokedexServer_PokedexClient *value, char *buffer);
void deserializarPokedexCliente_PokedexServer(t_MensajePokedexServer_PokedexClient *value, char * bufferReceived);

int ponerAEscuchar(char* ipServer, int puertoServidor);
int enviar(int* socketAlQueEnvio, void* envio,int tamanioDelEnvio);
int recibir(int* socketReceptor, void* bufferReceptor,int tamanioQueRecibo);
int conectarseA(char* ipDestino,int puertoDestino);
int escucharMultiplesConexiones(int* socketEscucha,int puertoEscucha);

void abrirConexionDelServer(char* ipServer, int puertoServidor,int* socketServidor);
void aceptarConexionDeUnCliente(int* socketCliente,int* socketServidor);
void aceptarConexionDeUnClienteHilo(t_server* parametro);

void enviarPokemon(int socketEntrenador, char* species, int level, t_pokemon_type type, t_pokemon_type second_type);
void serializarPokemon(t_pokemon* value, char* buffer, int valueSize);

t_pokemon* recibirPokemon(int socketMapa);
void deserializarPokemon(t_pokemon* datos, char* bufferReceived);



#endif /*SOCKET_H_*/
