#ifndef MY_FS_H
#define MY_FS_H

#include "my_sched.h"

#define SUPER_MAGIC 0x137f //valeur servant a indique un noeud d'information
#define NR_INODE 94 //nombre max de descripteur de noeud d'info, defini statiquement dans mon code

typedef struct my_m_inode
{
	unsigned short i_mode; //filetype (dir,regular,...), mode (set_uid,set_gid), acces (rwx)
	unsigned short i_uid; //uid du proprietaire
	unsigned long i_size; //taille du fichier
	unsigned long i_time; //temps ecoule depuis epoch
	unsigned char i_gid; //gid du proprietaire
	unsigned char n_links; //nombre de processus ou le fichier est utilise
	unsigned short i_zone[9]; //7 zone de donnees, 1 zone bloc d'identification simple, 1 zone bloc d'identification double

	my_task_struct * wait; //liste chainee processus en attente
	unsigned long atime; //date dernier acces au noeud
	unsigned long ctime; //date derniere modif du noeud
	unsigned short dev; //numero du disque
	unsigned short num; //numero du noeud d'info sur le disque
	unsigned short count; //indique combien de fois le fichier est ouvert
	unsigned char lock; //booleen, indique l'ecriture en cours sur le disque
	unsigned char dirt; //booleen, indique les modification
	unsigned char pipe; //booleen, indique que c'est un tube de communication
	unsigned char mount;
	unsigned char seek; //pour l'offset je suppose
	unsigned char update; //booleen pour dire si les données sont valides
}my_m_inode;

typedef struct my_data_inode //32 octets
{
	unsigned short i_mode; //filetype (dir,regular,...), mode (set_uid,set_gid), acces (rwx)
	unsigned short i_uid; //uid du propriétaire
	unsigned long i_size; //taille du fichier
	unsigned long i_time; //temps ecoulé depuis epoch
	unsigned char i_gid; //gid du propriétaire
	unsigned char n_links; //nombre de processus ou le fichier est utilisé
	unsigned short i_zone[9]; //7 zone de données, 1 zone bloc d'identification simple, 1 zone bloc d'identification double
}my_data_inone;

typedef struct my_struct_buffer_head
{
	char *data; //addresse d'un bloc de 1024 octet en memoire vive
	unsigned short dev; //identificateur du disque associé
	unsigned short blocknr; //numero du bloc sur le disque
	unsigned char uptodate; //le tampon a-t-il des données valides
	unsigned char dirt; //booléen utilisé pour savoir si le bloc est utilisé et donc a eccrire sur le disque
	unsigned char count; //incrementé avant une opération sur le tampon et decrementé apres
	unsigned char lock; //booléen pour savoir si le tampon est en train d'etre ecrit sur le disque
	my_task_struct *wait; //file d'attente des processus voulant utiliser ce tampon
	struct my_struct_buffer_head *prev; //Liste doublement chainée
	struct my_struct_buffer_head *next;
	struct my_struct_buffer_head *prev_free;
	struct my_struct_buffer_head *next_free;
	
}my_struct_buffer_head;

typedef struct my_super_bloc
{
	unsigned short n_idode; //nombre de noeuds d'info
	unsigned short n_izone; //nombre de zones
	unsigned short n_imap; //nombre de blocs de la table de bits des noeuds d'info
	unsigned short n_zmap; //nombre de blocs de la table de bits des zones
	unsigned short first_data_zone; //premier bloc de données
	unsigned short log_zone_size; //vaut 1 = (ln(2))/(ln(2))
	unsigned long max_size; //taille maximum des fichiers
	unsigned short magic; //
}my_super_bloc;

void	my_buffer_init(void);

#endif
