#ifndef CONST_H
#define CONST_H

#define I_DIR			0040000 //Les valeurs choisies n'importent pas mais on les conserve
#define I_REG			0100000 //pour eviter d'avoir des soucis après dans le cas ou
#define I_SBLOC			0060000 //Torvalds aurait utilisé directement les valeurs au lieu de
#define I_SCHAR 		0020000 //la constante
#define I_PIPE			0010000 //Definition : Fichier Repertoire,normaux,special_block,special_char,tunnels
#define I_SET_UID_BIT		0004000 //setuid
#define I_SET_GID_BIT		0002000 //setgid

//concerne la structure termios
//mode entree
#define IGNBRK	0000001 //ignore break
#define BRKINT	0000002 //vide le tampon d'entree
#define IGNPAR	0000004 //ignore parity
#define PARMRK	0000010 //parity error mask '\377' ou '\0'
#define INPCK	0000020
#define ISTRIP	0000040 //caractere sur 7 bits
#define INLCR	0000100 //newline -> '\n'
#define IGNCR	0000200 //ignore '\n'
#define ICRNL	0000400 //'\n' -> newline
#define IUCLC	0001000 //MAJ -> min
#define IXON	0002000 //CTRL + S -> stop ecriture terminal, CTRL + Q -> reprend ecriture
#define IXANY	0004000 //n'importe quel caractere reprend l'ecriture
#define IXOFF	0010000 //auto blocage-reprise du tampon des entree
#define IMAXBEL	0020000 //alarm sonore si tampon entree plein

//mode sortie
#define OPOST	0000001 //norme posix ou jsais pas trop
#define OLCUC	0000002 //min -> MAJ
#define ONLCR	0000004 //newline -> '\n'
#define OCRNL	0000010 //'\n' -> newline
#define ONOCR	0000020 //'\n' en debut de ligne non transmis = pas de ligne vide
#define ONLRET	0000040 //newline = '\n'
#define OFILL	0000100 //caractere de remplissage lors d'un delai
#define OFDEL	0000200 //pareil que OFILL mais avec del plutot que '\0'
#define NLDY	0000400 //valeur du delai apres newline
#define NL0	0000000
#define NL1	0000400
#define CRDLY	0003000 //'\n' delay
#define CR0	0000000
#define CR1	0001000
#define CR2	0002000
#define CR3	0003000
#define TABDLY	0014000 //Tab delay
#define TAB0	0000000
#define TAB1	0004000
#define TAB2	0010000
#define TAB3	0014000
#define XTABS	0014000
#define BSDLY	0020000 //BackSpace delay (retour arrière)
#define BS0	0000000
#define BS1	0020000
#define VTDLY	0040000 //Vertical TAB delay
#define VT0	0000000
#define VT1	0040000
#define FFDLY	0040000 //delay apres passage a une nouvelle page
#define FF0	0000000
#define FF1	0040000

//caractere de controle du terminal
#define VINTR		0 //en mode ISIG envois un signal SIGINT
#define VQUIT		1 //en mode ISIG envois un signal SIGQUIT
#define VERASE		2 //en mode ICANON efface le caractere precedant s'il est sur la derniere ligne
#define VKILL		3 //en mode ICANON efface tout les caractere en train d'etre tappe sur la ligne
#define VEOF		4 //indique une fin de fichier pour l'appel systeme read()
#define VTIME		5 //en mode local non ICANON : defini un interval de temps avant la lecture des caractères
#define VMIN		6 //en mode local non ICANON : defini nombre de caractere pour que le tampon de lecture soit accessible
#define VSWTC		7 //permet d'echapper au gestionnaire de couche du mecanisme des shell
#define WSTART		8 //en mode local IXON ou IXOFF, ce caractere autorise le defilement sur le terminal
#define WSTOP		9 //en mode local IXON ou IXOFF, ce caractere suspend le defilement sur le terminal
#define VSUSP		10 //en mode local ISIG provoque l'envois d'un signal SIGTSTP au groupe de processus en premier plan du term
#define VEOL		11 //(End Of Line) en mode ICANON ce caractere est equivalent au caractere fin de ligne
#define VREPRINT	12 //permet le reaffichage d'un caractere non lu
#define VDISCARD	13 //abandonne une sortie en attente
#define VWERASE		14 //en mode local ICANON efface le dernier mot tapé
#define VLNEXT		15
#define	VEOL2		16 //autre caractere de fin de ligne

define BLOCK_SIZE 1024 //Deux secteurs de 512 octets

typedef union my_buffer_block
{
	int a;				//inutile mais juste pour creer l'union
	char buf[1024];		//1024 octet, taille d'un bloc sous Linux et MINIX
}my_buffer_block;

#endif
