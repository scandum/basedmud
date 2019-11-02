#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>
#include <zlib.h>
#include <stdarg.h>


/*
	Utility macros.
*/

#define HAS_BIT(var, bit)       ((var)  & (bit))
#define SET_BIT(var, bit)	((var) |= (bit))
#define DEL_BIT(var, bit)       ((var) &= (~(bit)))
#define TOG_BIT(var, bit)       ((var) ^= (bit))

/*
	Update these to use whatever your MUD uses
*/

#define RESTRING(point, value) \
{ \
	STRFREE(point); \
	point = strdup(value); \
}

#define STRALLOC(point) \
{ \
	point = strdup(value); \
}

#define STRFREE(point) \
{ \
	free(point); \
	point = NULL; \
} 

/*
	Typedefs
*/
typedef struct mth_data           MTH_DATA;
typedef struct mud_data           MUD_DATA;
typedef struct descriptor_data    DESCRIPTOR_DATA;

//#define MUD_PORT                           4321
//#define MAX_SKILL                           269
//#define MAX_CLASS                             8
//#define MAX_RACE                             16
//#define MAX_LEVEL                            99

#define MAX_INPUT_LENGTH                   2000
#define MAX_STRING_LENGTH                 12000 // Must be at least 6 times larger than max input length.
#define COMPRESS_BUF_SIZE                 10000

#define FALSE                                 0
#define TRUE                                  1

/*
	Descriptor (channel)
*/
/* Descriptor (channel) structure. */
struct descriptor_data {
    DESCRIPTOR_DATA *next;
    DESCRIPTOR_DATA *snoop_by;
    void *character;
    void *original;
    MTH_DATA *mth; // MTH 1.5
    int ansi;
    char *host;
    short descriptor;
    short connected;
    int fcommand;
    char inbuf[MAX_INPUT_LENGTH];
    char incomm[MAX_INPUT_LENGTH];
    char inlast[MAX_INPUT_LENGTH];
    int repeat;
    char *outbuf;
    int outsize;
    int outtop;
    char *showstr_head;
    char *showstr_point;
    int lines_written; /* for the pager */
    void *pEdit;    /* OLC */
    char **pString; /* OLC */
    int editor;     /* OLC */
};

/*
	mud.c
*/

void        log_printf(char *fmt, ...);
void        log_descriptor_printf(DESCRIPTOR_DATA *d, char *fmt, ...);
void        descriptor_printf ( DESCRIPTOR_DATA *d, char *fmt, ...);

//int         write_to_descriptor(DESCRIPTOR_DATA *d, char *txt, int length);
int           write_to_descriptor (int desc, char *txt, int length);

char      * capitalize_all(char *str);
