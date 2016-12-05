#ifndef CONST_H
#define CONST_H

#define I_DIR			0040000 //Les valeurs choisies n'importent pas mais on les conserve
#define I_REG			0100000 //pour eviter d'avoir des soucis après dans le cas ou
#define I_SBLOC			0060000 //Torvalds aurait utilisé directement les valeurs au lieu de
#define I_SCHAR 		0020000 //la constante
#define I_PIPE			0010000 //Definition : Fichier Repertoire,normaux,special_block,special_char,tunnels
#define I_SET_UID_BIT		0004000 //setuid
#define I_SET_GID_BIT		0002000 //setgid

#define BLOCK_SIZE 1024 //Deux secteurs de 512 octets

typedef union my_buffer_block
{
	int a;				//inutile mais juste pour creer l'union
	char buf[1024];		//1024 octet, taille d'un bloc sous Linux et MINIX
}my_buffer_block;

#endif
