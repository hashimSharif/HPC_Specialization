
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <upc_relaxed.h>

/*--------- structure.h --------*/
#ifdef BUG1578_WORKAROUND
struct _noeud
{
        shared struct noeud *pere;      
        shared struct noeud *fils;
        int gx;         
        shared struct coordonnees *c;
};
#define noeud struct _noeud
struct _coordonnees
{
        int developpe;
        int x;
        int y;
        int valeur;
        int nx;
        int ny;
        shared struct coordonnees *next;
};
#define coordonnees struct _coordonnees
#else
struct _noeud;
typedef struct _noeud noeud;

struct _coordonnees;
typedef struct _coordonnees coordonnees;

struct _noeud
{
        shared noeud *pere;     /*Noeud père*/
        shared noeud *fils;
        int gx;         /*cout du noeud initial au noeud courant*/
        shared coordonnees *c; /*coordonnées des coups possible*/
};

struct _coordonnees
{
        int developpe;
        int x;
        int y;
        int valeur;
        int nx;
        int ny;
        shared coordonnees *next;
};
#endif
/*-----------------*/
#define BUFFER_SIZE 3
#define CHIFFRE_SIZE 4

#define VIDE 0
#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 2

/*Variable en méoire partagé nécessaire pour le choix du donneur*/

/*Variable pour la distribution du travail*/
shared int target = 0;
/*Variable pour la taille du tableau*/
shared int N;
/*Variable tableau solution*/
shared coordonnees *Solution;
/*Variable tableau du début*/
shared coordonnees *begin;
/*Variable qui contient un tableau de pointeurs vers les différents arbres*/
shared noeud *shared arbre[THREADS];
/*Variable qui contient le nombre de noeuds non dévelloppé*/
shared int numberNoeuds[THREADS];



void chargementfichier (char *nom, coordonnees **tab, coordonnees **sol);
void getCoordonnees (int *x, int *y, int rech, coordonnees *tab);
int getValeur (int x, int y, coordonnees *tab, int taille);
int getDistanceManhattan (int i, int j, int k, int l);
int hx (coordonnees *tab, coordonnees *sol, int taille);
void getAllhoop (int x, int y, int oldval, coordonnees *tab, int taille, shared noeud *n);
int move (int taille, coordonnees *tab, coordonnees *sol,int c);
void getNexthoop(shared noeud *n, int *x, int *y);
void exchangeCase(int x, int y, int i, int j, coordonnees *tab, int taille);
void printTableau(coordonnees * tab, int taille);
void getLasthoop(shared noeud *n, int *x, int *y, int *i, int *j, int *valeur);
void printSolution(shared noeud* arbre, coordonnees *tab, int taille);
void getWork();

int main (int argc, char** argv)
{	
	coordonnees* tab;
	coordonnees* sol;
	int taille, res, test, number,i;
	
	test = 1;
	
	if(MYTHREAD == 0)
	{
		if (argc != 2)
		{
			printf ("USAGE n2-1-puzzle <tableau_a_trier>\n");
			exit (1);
		}
		/*on charge les données ligne par ligne si c'est le thread 0*/
		chargementfichier (argv[1],&tab,&sol);
	}
	/*On synchronise tous les threads pour attendre que le threads 0 est fini de tous initialiser*/
	upc_barrier;
	
	taille = N;
	number = taille * taille;
	
	/*On alloue les tableaux*/
        begin = (shared coordonnees *) upc_all_alloc (number, sizeof(coordonnees));
        Solution = (shared coordonnees *) upc_all_alloc (number, sizeof(coordonnees));

        if(MYTHREAD == 0)
        {
                /*On met les tableaux disposition*/
                for(i=0;i<number;i++)
                {
                        begin[i] = tab[i];
                        Solution[i] = sol[i];
                }
        }

        upc_barrier;

        if(MYTHREAD != 0)
        {
                tab = (coordonnees *) calloc (number, sizeof(coordonnees));
                sol = (coordonnees *) calloc (number, sizeof(coordonnees));

                /*On va recopier les tableaux*/
                for(i=0;i<number;i++)
                {
                        tab[i] = begin[i];
                        sol[i] = Solution[i];
                }
        }

        upc_barrier;

	
	printf("THREAD : %d : Tableau de depart :\n",MYTHREAD);
	printTableau (tab, taille); 
	printf("THREAD : %d : Tableau de solution :\n",MYTHREAD);
	printTableau (sol, taille);
	
	/*On affiche la taille et la distance de Manathan*/
	printf ("THREAD : %d : La taille est de : %d\n",MYTHREAD ,taille);
	res = hx (tab, sol, taille);
	printf("THREAD : %d : h(x) somme des distances de Manhattan = %d\n", MYTHREAD, res);
	
	/*On éxécute la fonction move jusqu'à ce que la valeur de retour soit 1*/
	while(test != 0)
	{
		/*On affiche la valeur de C utilisée par le programme*/
		printf("Valeur de C : %d\n",res);
		/*On appelle la fonction qui va tenter de résoudre le problème*/
		test = move(taille,tab,sol,res);
		/*On augmente C*/
		res = test;
	}

	return EXIT_SUCCESS;
}

void chargementfichier (char *nom, coordonnees  **tab, coordonnees **sol)
{
	FILE* fichier;
	int tailler, valeur, number,i ,j;
	coordonnees *tableau;
        coordonnees *solution;
	coordonnees *c;
	char *buffer;
	char n[CHIFFRE_SIZE];
	char buffer_t[2];

	i = 0;
	
	/*On ouvre le fichier passé en argument en lecture*/
	fichier = fopen (nom,"r");
	
	/*Si le fichier n'existe pas on affiche une erreur et on quitte*/
	if (fichier == NULL)
	{                                       
		perror ("fopen :");       
	}
	
	/*On récupère la taille du tableau, sur la premiere ligne*/
	fgets (buffer_t, 2, fichier);
	sscanf (buffer_t, "%d", &tailler);
	N = tailler;

	
	/*On calcule la taille du tableau*/
	number = N * N;
	
	/*On alloue les tableaux*/
	tableau = (coordonnees*) calloc (number, sizeof(coordonnees));
        solution = (coordonnees*) calloc (number, sizeof(coordonnees));
	
	/*+1 pour \0*/
	buffer = (char *) calloc (N*CHIFFRE_SIZE+1, sizeof(char));
	
	/*BEGIN A VOIR*/
	/*on saute les 2 premières lignes du fichier*/
	fgets (buffer, N+N*CHIFFRE_SIZE+1, fichier);
	fgets (buffer, N+N*CHIFFRE_SIZE+1, fichier);
	/*END A VOIR*/
	
	i = 0;
		
	while (i < number)
	{
		fgets (buffer, tailler+tailler*CHIFFRE_SIZE+1, fichier);
		
		for (j = 0 ; j < tailler ; j++)
		{
			if (j == 0) 
			{
				strncpy (n ,strtok (buffer, " \n"), CHIFFRE_SIZE);
			} 
			else 
			{
				strncpy (n ,strtok (NULL, " \n"), CHIFFRE_SIZE);
			}
			valeur = strtol (n, NULL, 10);
			c = (coordonnees *) calloc (1, sizeof(coordonnees));
			c->y = i / tailler;
			c->x = i - (c->y * tailler);
			c->valeur = valeur;
			c->developpe = FALSE;
			tableau[valeur] = *c;
			free (c);
			i++;
		}
	}
	fgets (buffer, tailler+tailler*CHIFFRE_SIZE+1, fichier);

	i = 0;
	while(i < tailler*tailler)
	{
		fgets (buffer, tailler+tailler*CHIFFRE_SIZE+1, fichier);
		
		for (j = 0 ; j < tailler ; j++)
		{
			if (j == 0) 
			{
				strncpy (n ,strtok (buffer, " \n"), CHIFFRE_SIZE);
			} 
			else 
			{
				strncpy (n ,strtok (NULL, " \n"), CHIFFRE_SIZE);
			}
			valeur = strtol (n, NULL, 10);
			
			c = (coordonnees *) calloc (1, sizeof(coordonnees));
			c->y = i / tailler;
			c->x = i - (c->y * tailler);
			c->valeur = valeur;
			c->developpe = FALSE;
			solution[valeur] = *c;
			free (c);
			
			i++;
		}
	}

	free (buffer);
	*tab = tableau;
	*sol = solution;		
}


void getCoordonnees (int *x, int *y, int rech, coordonnees *tab)
{
	  *y = tab[rech].y;
	  *x = tab[rech].x;	  
}

int getValeur (int x, int y, coordonnees *tab, int taille)
{
	int i;
	
	for (i = 0 ; i < taille*taille ; i++)
	{
		if (tab[i].x == x)
			if (tab[i].y == y)
				return i;
	}
	
	return -1;
			
}

int getDistanceManhattan (int i, int j, int k, int l)
{
	return abs (i - k) + abs (j - l);
}

int hx (coordonnees *tab, coordonnees *sol, int taille)
{
	int x0, x, y0, y, res, i, number;
	
	number = taille * taille;
	
	res = 0;
	
	for ( i = 0 ; i < number ; ++i )
	{
		getCoordonnees (&x0, &y0, tab[i].valeur, tab);
		getCoordonnees (&x, &y, tab[i].valeur,sol);
		res += getDistanceManhattan (x0, y0, x, y);
	}

	return res;
}

void getAllhoop (int x, int y, int oldval, coordonnees *tab, int taille, shared noeud *n)
{
	shared coordonnees *temp, *temp1;
	/*Quatre déplacement possible possible : HAUT BAS DROITE GAUCHE*/
	
	/*HAUT*/
	if( (y-1) >= 0 && getValeur(x,y-1,tab,taille) != oldval)
	{
		/*Si aucune coordonnée on insère*/
		if(n->c == NULL)
		{
			n->c = (shared coordonnees*) upc_alloc(sizeof (coordonnees));	
			n->c->next=NULL;
			n->c->x = x;
			n->c->y = y-1;
			n->c->nx = x;
			n->c->ny = y;
			n->c->valeur=getValeur(x,y-1,tab,taille);
			n->c->developpe = FALSE;
		}
		else
		{
			temp = n->c;
			temp1 = n->c;
			while(temp->next != NULL)
			{
				temp = temp->next;
				temp1 = temp;
			}
			temp = (shared coordonnees*) upc_alloc (sizeof (coordonnees));
			temp1->next =temp;
			temp->next = NULL;
			temp->x = x;
			temp->y = y-1;
			temp->nx = x;
			temp->ny = y;						
			temp->valeur = getValeur(x,y-1,tab,taille);
			temp->developpe = FALSE;
		}
	}
	
	/*BAS*/
	if( (y+1) < taille  && getValeur(x,y+1,tab,taille) != oldval )
	{
		if(n->c == NULL)
		{
			n->c = (shared coordonnees*) upc_alloc (sizeof (coordonnees));
			n->c->next=NULL;
			n->c->x = x;
			n->c->y = y+1;
			n->c->nx = x;
			n->c->ny = y;	
			n->c->valeur=getValeur(x,y+1,tab,taille);
			n->c->developpe = FALSE;
		}
		else
		{
			temp = n->c;
			temp1 = n->c;
			while(temp->next != NULL)
			{
				temp = temp->next;
				temp1 = temp;
			}
			temp = (shared coordonnees*) upc_alloc (sizeof (coordonnees));
			temp1->next =temp;
			temp->next = NULL;
			temp->x = x;
			temp->y = y+1;
			temp->nx = x;
			temp->ny = y;						
			temp->valeur = getValeur(x,y+1,tab,taille);
			temp->developpe = FALSE;

		}
	}
	
	/*GAUCHE*/
	if( (x-1) >= 0  && getValeur(x-1,y,tab,taille) != oldval )
	{
		if(n->c == NULL)
		{
			n->c = (shared coordonnees*) upc_alloc (sizeof (coordonnees));
			n->c->next=NULL;
			n->c->x = x-1;
			n->c->y = y;
			n->c->nx = x;
			n->c->ny = y;			 
			n->c->valeur=getValeur(x-1,y,tab,taille);
			n->c->developpe = FALSE;
		}
		else
		{
			temp = n->c;
			temp1 = n->c;
			while(temp->next != NULL)
			{
				temp = temp->next;
				temp1 = temp;
			}
			temp = (shared coordonnees*) upc_alloc (sizeof (coordonnees));
			temp1->next = temp;
			temp->next = NULL;
			temp->x = x-1;
			temp->y = y;
			temp->nx = x;
			temp->ny = y;					
			temp->valeur = getValeur(x-1,y,tab,taille);
			temp->developpe = FALSE;
		}								
	}
	
	/*DROITE*/
	if( (x+1) < taille && getValeur(x+1,y,tab,taille) != oldval )
	{
		if(n->c == NULL)
		{
			n->c = (shared coordonnees*) upc_alloc (sizeof (coordonnees));
			n->c->next=NULL;
			n->c->x = x+1;
			n->c->y = y;
			n->c->nx = x;
			n->c->ny = y;
			n->c->valeur=getValeur(x+1,y,tab,taille);
			n->c->developpe = FALSE;
		}
		else
		{
			temp = n->c;
			temp1 = n->c;
			while(temp->next != NULL)
			{
				temp = temp->next;
				temp1 = temp;
			}
			temp = (shared coordonnees*) upc_alloc (sizeof (coordonnees));
			temp1->next =temp;
			temp->next = NULL;
			temp->x = x+1;
			temp->y = y;
			temp->nx = x;
			temp->ny = y;
			temp->valeur = getValeur(x+1,y,tab,taille);
			temp->developpe = FALSE;

		}
	}
	
	return;
}

void getNexthoop(shared noeud *n, int *x, int *y)
{
	shared coordonnees *temp;
	
	/*Si plus de coordonnées dispo on retourne -1 -1 pour remonter dans l'arbre*/
	if(n->c == NULL)
	{
		*x = -1;
		*y = -1;
		return ;
	}
	
	temp = n->c;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->developpe = TRUE;
	*x = temp->x;
	*y = temp->y;

	return;
}

void exchangeCase(int x, int y, int i, int j, coordonnees *tab, int taille)
{
	coordonnees temp;
	int a,b;
	
	a = getValeur (x, y, tab, taille);
	b = getValeur (i, j, tab, taille);
	temp = tab[a];

	tab[a] = tab[b];
	tab[b] = temp;

	return;
}

void printTableau(coordonnees * tab, int taille)
{
	int i, number;
	int *print;

	number = taille * taille;

	print = (int *) calloc (taille*taille, sizeof(int));
	for (i = 0 ; i < number ; i++)
	{
		print[ tab [i].y*taille + tab[i].x ] = i;
	}

	for (i=1;i<=number;i++)
	{
		printf(" %d",print[i-1]);
		
		if(i%taille == 0)
		{
			printf("\n");
		}
	}
	
	printf("\n");
	/*free (print);*/
}
 
void getLasthoop(shared  noeud *n, int *x, int *y, int *i, int *j, int *valeur)
{
	shared coordonnees *temp, *temp1;
	int k=0;
	
	temp1 = NULL;
	temp = n->c;
	
	while(temp->developpe != TRUE)
	{
		k++;
		temp1 = temp;
		temp = temp->next;
	}
	
	/*Cas 1 coordonnées*/
	if(temp1 != NULL)
	{
		temp1->next = NULL;
	}
	
	*x = temp->x;
	*y = temp->y;
	*i = temp->nx;
	*j = temp->ny;
	*valeur = temp->valeur;
	upc_free(temp);
	
	if(k == 0)
	{
		n->c = NULL;
	}
}

void printSolution(shared noeud* arbre, coordonnees *tab, int taille)
{
	/*Coordonnées 0*/
	int x,y;
	/*Coordonnées Point*/
	int i,j;
	shared noeud *temp;

	printTableau(tab,taille);	
	temp = arbre;
	
	while(temp != NULL)
	{
		getCoordonnees(&x, &y, VIDE, tab);
		getNexthoop(temp,&i,&j);
		exchangeCase(x,y,i,j,tab,taille);
		printTableau(tab,taille);
		printf("\n");
		temp = temp->fils;
	}
}

void getWork()
{
	upc_lock_t *lock;
	int from;
	
	/*A voir si pas mieux dans move*/
	lock = upc_all_lock_alloc();

	/*On bloque l'accès à la variable globale target*/
	upc_lock(lock);
	/*On récupère la machine à laquelle on va adresser une demande de travail*/
	from = target;
	/*On incrémente target*/
	target = (target+1)%THREADS;
	/*On débloque l'accès à la varialbe globale target*/
	upc_unlock(lock);

	
}

int move (int taille, coordonnees *tab, coordonnees *sol, int c)
{
	int x, y, i, j, oldval, ret, test, val, number, newc;
	coordonnees *sauv;
	shared noeud *res, *delete, *pere, *arbre;
	int m;
	ret = 0; 
	oldval = -1;
	test = 1;
	newc = 65000;
	number = taille * taille;
	
	/*Allocation du tableau de départ, nécessaire pour l'affichage à la fin*/
	sauv = (coordonnees*) calloc (number, sizeof(coordonnees));
	
	/*On recopie le tableau pour afficher à la fin*/
	for(i=0;i<number;i++)
	{
		sauv[i] = tab[i];
	}

	getCoordonnees (&x, &y, VIDE, tab);

	/*Début de la résolution du problème*/
	while(test != 0)
	{
		
		/*Si le premier coups, racine de l'arbre*/
		if(oldval == -1)
		{
			res = (shared noeud*) upc_alloc (sizeof(noeud));
			arbre = res;
			res->pere = NULL;
			res->fils = NULL;
			res->gx = 0;
		}
		/*Sinon on "s'accroche" à l'arbre, si pas de retour en arrière effectué*/
		else if(ret == 0)
		{
			res = (shared noeud*) upc_alloc (sizeof(noeud));
			res->pere = pere;
			pere->fils = res;
			res->gx = pere->gx+1;
		}
		
		/*Si pas de retour en arrière dans l'arbre*/
		if(ret == 0)
		{
			/*Permet de récupérer tous les coups jouables depuis la position de la case vide*/
			getAllhoop (x, y, oldval, tab, taille,res);
		}
	
		/*On récupère le prochain coups à jouer*/
		getNexthoop (res, &i , &j);
		/*Si getNexthoop renvoie -1 -1 alors il n'y a plus de coups a jouer, il faut donc remonter dans l'arbre*/
		while(i == -1 && j == -1)
		{
			/*On regarde la valeur du pointeur père si il est différent de nul, on remonte d'un noeud*/
			if(res->pere != NULL)
			{
				delete = res;
				res = res->pere;
				upc_free(delete);
			}
			/*Sinon on est dans le premier noeud, il n'y a plus de coups à jouer, on recommence en augmentant C*/
			else
			{
				return newc;
			}
			/*Permet de récupérer le dernier coups JOUE*/
			getLasthoop(res, &i, &j, &x, &y, &val);
			/*On recherche les coordonnées du dernier coups à l'aide de la valeur NON NECESSAIRE*/
			/*getCoordonnees (&x, &y, val, tab, taille);*/
			/*On échange les deux cases pour revenir au tableau initiale*/
			exchangeCase(x, y, i, j,tab,taille);
			/*On récupère le prochain coups a jouer*/
			getNexthoop (res, &i , &j);
		}
		
		/*On stocke la valeur de la case qu'on joue, pour eviter de la rejouer nécessaire pour getAllhoop*/
		oldval = getValeur(i,j,tab,taille);
		
		/*On échange les deux cases, pour avoir le tableau avec le nouveau déplacement*/
		exchangeCase(x, y, i, j,tab,taille);
			
		/*On met la varialbe retour à 0*/
		ret = 0;
		/*On regarde si le chemin emprunter est bon*/
		test = hx(tab,sol,taille);
		if(c < test + res->gx)
		{
			if(newc > test + res->gx)
			{
				newc = test + res->gx;
			}
			/*On récupère le dernier coups JOUE*/
			getLasthoop(res, &i, &j,&m, &m,&val);
			/*On échange les cases pour annuler le dernier coups*/
			exchangeCase(x, y, i, j,tab,taille);
			/*On met la valeur retour à 1 pour signifier que l'on remonte*/
			ret = 1;
		}
		else
		{
			/*Sinon on stacke le noeud*/
			pere = res;
			x = i;
			y = j;
		}
	}
	/*On affiche la solution puis on remonte*/
	//printSolution(arbre,sauv,taille);
	printf("Nombre de coups mini :%d\n",res->gx+1);
	return 0;		
}
