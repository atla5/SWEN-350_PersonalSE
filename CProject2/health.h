/*
* Health Monitoring System include file 
*
* DO NOT CHANGE THE CONTENTS OF THIS FILE!
*
*/

#ifndef HEALTH_H
#define HEALTH_H

#define MAXREADINGS 10
#define MAXTIME 8
#define MAXLINE 25+1

/* One health type reading: timestamp + actual value */
typedef struct{
	char timestamp[MAXTIME+1];
	int value;
}Element;

/* 
*   Health type readings: linked list of Circular buffers 
*/
typedef struct healthEntry* CBuffptr; /* pointer to a CircularBuffer */

typedef struct healthEntry{
	int type;		               /* health data type (1-5) */
	int start;	                   /* index of oldest reading */
	int end;		               /* index of most current reading */
	Element reading[MAXREADINGS];  /* fixed array of readings */
	CBuffptr next;		           /* pointer to next health type buffer */
}CircularBuffer;

/*
*   Patient's health chart: ID + linked list of  health type readings
*/
typedef struct chartEntry* Chartptr;   /* pointer to a Chart */

typedef struct chartEntry{
	int id;				/* patient ID */
	CBuffptr  buffer; 		/* pointer to first health type buffer */
	Chartptr  next;			/* pointer to next patient */
}Chart;

/* global declaration for start of the patient chart linked list */
extern Chartptr patientList;

//health_util function declarations
extern void addPatient( int patientID );
extern void addHealthType( int patientID, int newType );
extern Chartptr getChart( int patientID );
extern CBuffptr getHealthType( int patientID, int healthType ); 
extern void removePatient( int patientID );
extern void addHealthReading( CBuffptr buffer, char* timestamp, int value );

//own function declarations from health_util
extern int read_line( int *id, char *time[], int *type, float *val);
extern void printPatient(int id);
extern void resetPatient(int id);

#endif
