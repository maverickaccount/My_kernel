#ifndef MY_SCHED_H
#define MY_SCHED_H

#define NULL ((void *) 0)
#define PAGE_SIZE 4096 //4Ko
//Cette partie concerne le champs state de my_task_struct
#define TASK_RUNNING 0 //processus pret ou elu
#define TASK_INTERRUPTIBLE 2 //processus suspendu en attendant une evenement
#define TASK_UNINTERRUPTIBLE 3 //processus suspendu qui attend un evenement materiel
#define TASK_ZOMBIE 4 //processus terminé mais qui conserve son task_struct
#define TASK_STOPPED 5 //processus stoppé par un signal

#define MY_INIT_TASK \
	{0,15,15, \
	0,NULL, {(fn_ptr) 0,}, 0, \
	0,0,0,0, \
	0,-1,0,0, \
	0,0,0,0,0,0, \
	0,0,0,0,0,0, \
	0, \
	-1,0133,NULL,NULL,0,NULL, \
	{ \
	{0,0}, \
	{0x0000009f,0x00c0fa00}, \
	{0x0000009f,0x00c09200}, \
	}, \
	{0, (long) &my_init_task + 4096, 0x10,0,0,0,0, \
	&my_pg_dir,0,0,0,0,0,0,0,0,0,0, \
	0x17,0x17,0x17,0x17,0x17,0x17 \
	_LDT(0),0x80000000, \
	{0,0,0,0,0,0,0, {(long) 0,}, \
		}, \
	}, \
	}


void	my_sched_init(void);

typedef int (*my_fn_ptr)();

typedef struct my_desc_struct
{
	long first_desc_part; //4 octets
	long second_desc_part; //+ 4 otects car un descripteur occupe 8 octets
}my_desc_struct;

typedef struct my_i387_struct //sert a recuperer les registres du coprocesseur mathematique
{
	long control;
	long state;
	long tag;
	long offset_ip;
	long cs;
	long op_offset;
	long op_selector;
	long table[20]; //pour recuperer les nombres double
}my_i387_struct;

typedef struct my_tss_struct
{
	long backlink;
	long esp0;
	long ss0;
	long esp1;
	long ss1;
	long esp2;
	long ss2;
	long cr3;
	long eip;
	long eflags;
	long eax;
	long ecx;
	long edx;
	long ebx;
	long esp;
	long ebp;
	long esi;
	long edi;
	long es;
	long cs;
	long ss;
	long ds;
	long fs;
	long gs;
	long ldt; //retient l'addresse de la ldt
	long trace_bitmap;
	my_i387_struct i387;
}my_tss_struct;

typedef union my_task_union
{
	my_tss_struct tss;
	char page[4096];
}my_task_union;

static my_task_union my_init_task = {MY_INIT_TASK,};

typedef struct	my_task_struct
{
	long state; //determine l'etat du processus
	long counter; //determine le nombre de tops d'horloge restant (priorité dynamique)
	long priority; //determine le nombre de tops d'horloge en debut de periode

	long signal; //recois les signaux pas encore traités
	my_fn_ptr sig_restorer; //conserve l'addresse d'une fonction de restauration
	my_fn_ptr sig_fn[32]; //contient les fonctions de traitement des signaux
	int exit_code; //code a transmettre au processus pere a la fin de celui-ci;

	unsigned long end_code; //fin de zone de code
	unsigned long end_data; //fin de zone de données
	unsigned long end_bss; //fin de la zone BSS
	unsigned long start_stack; //debut de la stack

	long pid; //Processus ID
	long father; //PID du processus pere
	long pgrp; //Processus GRouP
	long session; //Numero de session
	long leader; //Booléen (indique si le processus est le chef de groupe ou de session)

	unsigned short uid; //uid de l'utilisateur
	unsigned short euid; //utilisateur effectif (cf setuid)
	unsigned short suid; //uid sauvegardé
	unsigned short gid; //gid de l'utilisateur
	unsigned short egid; //gid effectif (cf setgid)
	unsigned short sgid; //gid sauvegardé

	long alarm; //temps restant avant qu'une alarme se declenche
	long utime; //temps processeur consommé par le processus en mode user
	long stime; //temps processeur consommé par le processus en mode noyau
	long cutime; //temps processeur utilisé par les processus fils en mode user
	long cstime; //temps processeur utilisé par les processus fils en mode noyau
	long start_time; //contient la date et l'heure de creation en seconde

	unsigned short used_math; //booléen pour savoir si on a utilisé le coprocesseur maths

	int tty; //numero du terminal associé
	unsigned short umask; //protection par defaut des fichiers crées par ce processus
	struct m_inode *pwd; //utilisé pour se reperer par rapport aux chemins relatifs
	struct m_inode *root; //utilisé pour se reperer par rapport aux chemins absolus
	unsigned long close_on_exec; //pour les fichiers qui doivent etre fermer lors de exec
	struct file *flip[20] //20 pointeurs sur fichiers maximum

	my_desc_struct ldt[3]; //desc nul, desc code user et desc data user
	my_tss_struct tss; //defini les info du tss
}my_task_struct;

#endif
