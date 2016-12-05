#ifndef MY_FS_H
#define MY_FS_H

#include "my_sched.h"

#define SUPER_MAGIC 0x137f //valeur servant a indique un noeud d'information
#define NR_INODE 94 //nombre max de descripteur de noeud d'info, defini statiquement dans mon code
#define NR_SUPER 8 //2 disque de 4 partitions max
#define NR_FILE 64 //nombre de descripteurs de fichier

#define MAJOR(a) (((unsigned) (a)) >> 8) //pour les fichiers de peripheriques
#define MINOR(a) ((a) & 0xff)

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

typedef struct my_super_block
{
	unsigned short n_idode; //nombre de noeuds d'info
	unsigned short n_izone; //nombre de zones
	unsigned short n_imap; //nombre de blocs de la table de bits des noeuds d'info
	unsigned short n_zmap; //nombre de blocs de la table de bits des zones
	unsigned short first_data_zone; //premier bloc de données
	unsigned short log_zone_size; //vaut 1 = (ln(2))/(ln(2))
	unsigned long max_size; //taille maximum des fichiers
	unsigned short magic; //sert a indiquer qu'il s'agit d'un noeud d'info
	my_struct_buffer_head *s_imap[8]; //indique les buffer_head qui pointent sur la table des noeuds d'info
	my_struct_buffer_head *z_imap[8]; //indique les buffer_head qui pointent sur la table des zones
	unsigned short dev; //numero du peripherique du super bloc
	my_m_inode *isup; //indique le descripteur du noeud d'info du systeme de fichier monté
	my_m_inode *imount; //indique le descripteur du noeud d'info sur lequel est monté eventuellement le fichier
	unsigned long time; //date derniere mise a jour
	unsigned char rd_only; //indique la lecture seule
	unsigned char dirt; //indique qu'il faut ecrire sur le disque le contenu
}my_super_block;

typedef struct file
{
	unsigned short f_mode; //indique lecture, ecriture ou lecture-ecriture
	unsigned short f_flags; //indique droit d'acces du fichier
	unsigned short f_count; //incremente si fork(), puis decremente a la fin d'un processus
	my_m_inode *f_inode; //adresse du desc de noeud d'info du fichier
	long f_pos; //position de l'index dans le fichier, depend du processus considéré
}file;

void	my_buffer_init(void);

#endif
