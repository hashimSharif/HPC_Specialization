#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <upc_relaxed.h>

#define LOGORDER 8
#define ORDER (256)       // (1<<LOGORDER) 
#define GRIDSIZE (65536)  // (ORDER*ORDER)
#define BLOCK (1024)      // ((GRIDSIZE)/(BLKPERTHREAD*THREADS))
#define Imask 0x0000AAAA
#define Jmask 0x00005555
#define Zord(i,j) ( (expand((i))<<1) | expand((j)) )
#define ixtrct(K) (extract( ((K))>>1 ))
#define jxtrct(K) (extract( ((K))    ))
#define Ixpnd(k) (expand((k))<<1)
#define Jxpnd(k) (expand(k))
#define Iinc(I) ( (((I)|Jmask)+2) & Imask )
#define Jinc(J) ( (((J)|Imask)+1) & Jmask )
#ifndef BUPC_TEST_HARNESS
  #define NUMTIMESTEPS 100
#else
  #define NUMTIMESTEPS 1
#endif

int RandomSeed = 1;

shared int FishMassX, FishMassY;
shared int FishPop, SharkPop;
struct Fish {
    int age;     
    int vx;
    int vy;
    shared [BLOCK] struct OceanGrid *position;
    struct Fish *next;
    struct Fish *before;
    };

struct Shark {
    int age; 
    int hungry; 
    int vx;
    int vy;
    shared [BLOCK] struct OceanGrid *position;
    struct Shark *next;
    struct Shark *before;
    };

struct Fish * FishList = NULL;
struct Shark * SharkList = NULL;

struct Fish * CreateFish(int, int, int);
struct Shark * CreateShark(int, int, int);
#define InitFishPop (GRIDSIZE/16)
#define MaxFishPop  (GRIDSIZE/4)
#define FishLifeExp (12) 
#define FishDeathRate (50)
#define FishMature (5)
#define FishBirthRate (60)
#define MinFishVelocity (-2)
#define MaxFishVelocity (2)

#define FISHCALS (5) 

#define InitSharkPop (GRIDSIZE/128)
#define MaxSharkPop (GRIDSIZE/16)
#define SharkLifeExp (50) 
#define SharkDeathRate  (40)
#define SharkMature (5)
#define SharkBirthRate  (12)
#define MinSharkVelocity  (-4)
#define MaxSharkVelocity  (4)

struct OceanGrid{
    int positionX;     // dilated form for X coordinate
    int positionY;     // dilated form for Y coordinate
    int nfish; 
    int nsharks; 
    int FishSmell;
    int SharkSmell;
    int FishForceX; 
    int FishForceY; 
    int SharkForceX; 
    int SharkForceY; 
    };

shared[ BLOCK ] struct OceanGrid Ocean[GRIDSIZE];
upc_lock_t *centroidlock;
struct Fish* CreateFish(int a, int I, int J)
{
    struct Fish * fish;
    
    if( (fish = (struct Fish*) malloc (sizeof(struct Fish))) != NULL){
      fish->age =  a;
      fish->vx = 0;
      fish->vy = 0;
      fish->position = &Ocean[I+J]; 
    }
    return fish;
}

struct Shark* CreateShark(int a, int I, int J)
{
    struct Shark * shark;
          
    if( (shark = (struct Shark*) malloc (sizeof(struct Shark))) != NULL){
       shark->age = a;
       shark->vx = 0;
       shark->vy = 0;
       shark->hungry = (int)rand()%100;
       shark->position = &Ocean[I+J];
    }
    return shark;
}
int expand( int t )
{ 
    int u,v,w,x;
    u = ((t&0x0000FF00)<<8) | (t & 0x000000FF);
    v = ((u&0x00F000F0)<<4) | (u & 0x000F000F);
    w = ((v&0x0C0C0C0C)<<2) | (v & 0x03030303);
    x = ((w&0x22222222)<<1) | (w & 0x11111111);
    return(x);
}

int extract( int t )
{ 
    unsigned u,v,w,y,x;
    u = (t&0x55555555);
    v = ((u&0x44444444)>>1) | (u & 0x11111111);
    w = ((v&0x30303030)>>2) | (v & 0x03030303);
    x = ((w&0x0F000F00)>>4) | (w & 0x000F000F);
    y = ((x&0x00FF0000)>>8) | (x & 0x000000FF);
    return((int)y);
}
int ispoweroffour(int n)
{
   // only check to 4 ^ 15th, 
   // cause we want to avoid word size problems
   int i,p;
   p = 1; 
   for( i=0; i<15; i++){
     if( p == n) 
       return(1);
     p *= 4;
   }
   return(0);
} 

void printoceansmell()
{
 int i,j;
 printf("\nsmell\n");

 for(i=0; i<ORDER; i++){
 for(j=0; j<ORDER; j++){
    printf("%2d ", Ocean[Zord(i,j)].FishSmell);
 }
 printf("   ");
 for(j=0; j<ORDER; j++){
    printf("%2d ", Ocean[Zord(i,j)].SharkSmell);
 }
 printf("\n");
 }
 printf("\n-----------\n");
}
void printoceanforce()
{
 int i,j;
 printf("\nforce\n");

 for(i=0; i<ORDER; i++){
 for(j=0; j<ORDER; j++){
    printf("%2d ", Ocean[Zord(i,j)].FishForceX);
 }
 printf("   ");
 for(j=0; j<ORDER; j++){
    printf("%2d ", Ocean[Zord(i,j)].FishForceY);
 }
 printf("\n");
 }
 printf("\n");
 for(i=0; i<ORDER; i++){
 for(j=0; j<ORDER; j++){
    printf("%2d ", Ocean[Zord(i,j)].SharkForceX);
 }
 printf("   ");
 for(j=0; j<ORDER; j++){
    printf("%2d ", Ocean[Zord(i,j)].SharkForceY);
 }
 printf("\n");
 }
 printf("\n-----------\n");
}
void printocean()
{
 int i,j;
 printf("\nnfish and sharks  %d %d %d %d\n",
     FishMassX, FishMassY, FishPop, SharkPop);
 for(i=0; i<ORDER; i++){
   for(j=0; j<ORDER; j++)
      printf("%2d ", Ocean[Zord(i,j)].nfish);
   printf("   ");
   for(j=0; j<ORDER; j++)
      printf("%2d ", Ocean[Zord(i,j)].nsharks);
   printf("\n");
 }
 printf("\n-----------\n");
/*
 for(i=0; i<ORDER; i++){
 for(j=0; j<ORDER; j++){
    printf("%2d %2d: %4d %4d %4d %4d   %4d %4d %4d %4d\n",
    i,j,
    Ocean[i][j].nfish, 
    Ocean[i][j].FishSmell,
    Ocean[i][j].FishForceX, 
    Ocean[i][j].FishForceY, 
    Ocean[i][j].nsharks, 
    Ocean[i][j].SharkSmell,
    Ocean[i][j].SharkForceX, 
    Ocean[i][j].SharkForceY );
 } }
*/
}
int main(int args, char * argv[])
{
    int timesteps=NUMTIMESTEPS;
    long sec, usec;
    struct timeval stamps [2];

    
{
 int stoprun = 0;

 centroidlock = upc_all_lock_alloc();
 
 if ( !ispoweroffour( THREADS ) || THREADS > 16 ) {
    stoprun |= 1;
    fprintf(stderr,"check the number of THREADS\n");
 }
 if ( !ispoweroffour( BLOCK ) ) {
    stoprun |= 1;
    fprintf(stderr,"check the size of each block\n");
 }
 if( !ispoweroffour( GRIDSIZE ) ){
    stoprun |= 1;
    fprintf(stderr,"check the grid size\n");
 }
 if( stoprun ) 
     exit(1);
}
    
{ int i, K;
  struct Fish *fish;
  struct Shark *shark;
  
    srand(1+MYTHREAD);

    for(i=0; i<InitFishPop; i++)
    {
        fish = CreateFish(
                 (int)rand()%FishLifeExp, 
                 Ixpnd((int)rand()%ORDER), 
                 Jxpnd((int)rand()%ORDER));
        if(FishList != NULL){
            FishList->before = fish;
        }
        fish->next = FishList;
        fish->before = NULL;
        FishList = fish;
    }
    
    for(i=0; i<InitSharkPop; i++) {
        shark = CreateShark( (int)rand()%SharkLifeExp, 
                  Ixpnd((int)rand()%ORDER), 
                  Jxpnd((int)rand()%ORDER) );
        if(SharkList != NULL)
            SharkList->before = shark;
        shark->next = SharkList;
        shark->before = NULL;
        SharkList = shark;
    }

    upc_forall(K=0; K<GRIDSIZE; K++; &Ocean[K] ){
        Ocean[K].positionX = K&Imask;
        Ocean[K].positionY = K&Jmask;
    }
    upc_barrier;
}

    
do
{
    
    
{ int i,j,k;
  int myfishpop, mysharkpop;
  int myfishmassX, myfishmassY;
  struct Fish *fish;
  struct Shark *shark;

   myfishpop = 0;
   mysharkpop = 0;
   myfishmassX=0;
   myfishmassY=0;

   if(MYTHREAD == 0){
      FishPop = 0;
      SharkPop = 0;
      FishMassX = 0;
      FishMassY = 0;
   }
   upc_forall(k=0; k<GRIDSIZE; k++; &Ocean[k]){  // Clear the grid
        Ocean[k].nfish = 0;
        Ocean[k].nsharks = 0;
        Ocean[k].FishSmell = 0;
        Ocean[k].SharkSmell = 0;
   }
   upc_barrier;

   for(fish=FishList; fish!=NULL; fish=fish->next) {
        myfishpop++;
        fish->position->nfish +=1;           //WARNING: NO LOCKS
   }
   for(shark=SharkList; shark!=NULL; shark=shark->next) {
        mysharkpop++;
        shark->position->nsharks +=1;        //WARNING: NO LOCKS
   }
   upc_barrier;
   upc_forall(k=0; k<GRIDSIZE; k++; &Ocean[k]){
      myfishmassX += ixtrct(k)*Ocean[k].nfish;
      myfishmassY += jxtrct(k)*Ocean[k].nfish;
   } 

   upc_lock(centroidlock);
      FishPop += myfishpop;
      SharkPop += mysharkpop;
      FishMassX += myfishmassX;
      FishMassY += myfishmassY;
   upc_unlock(centroidlock);

   upc_barrier;
   if( (FishPop == 0) || (SharkPop == 0 ) ){
     exit(2);
   }

   if(MYTHREAD == 0){
      FishMassX = FishMassX/FishPop;
      FishMassY = FishMassY/FishPop;
   }
}
    
{ int I,J,K;
  int Im2,Ip2,Im1,Ip1,Jm2,Jp2,Jm1,Jp1,sharknum, fishnum;
    upc_forall(K=0; K<GRIDSIZE; K++; &Ocean[K]){
        fishnum = Ocean[K].nfish;
        sharknum = Ocean[K].nsharks;
        I = K&Imask;
        J = K&Jmask;

		Im2 = (I - 8) & Imask;
		Im1 = (I - 2) & Imask;
		Ip1 = ((I|Jmask)+2) & Imask;
		Ip2 = ((I|Jmask)+8) & Imask;
		Jm2 = (J - 4) & Jmask;
		Jm1 = (J - 1) & Jmask;
		Jp1 = ((J|Imask)+1) & Jmask;
		Jp2 = ((J|Imask)+4) & Jmask;

        Ocean[  I+  J].FishSmell += 3*fishnum;
        Ocean[Im1+Jm1].FishSmell += 2*fishnum;
        Ocean[Im1+  J].FishSmell += 2*fishnum;
        Ocean[Im1+Jp1].FishSmell += 2*fishnum;
        Ocean[  I+Jm1].FishSmell += 2*fishnum;
        Ocean[  I+Jp1].FishSmell += 2*fishnum;
        Ocean[Ip1+Jm1].FishSmell += 2*fishnum;
        Ocean[Ip1+  J].FishSmell += 2*fishnum;
        Ocean[Ip1+Jp1].FishSmell += 2*fishnum;
        Ocean[Im2+Jm2].FishSmell += fishnum;
        Ocean[Im2+Jm1].FishSmell += fishnum;
        Ocean[Im2+  J].FishSmell += fishnum;
        Ocean[Im2+Jp1].FishSmell += fishnum;
        Ocean[Im2+Jp2].FishSmell += fishnum;
        Ocean[Im1+Jm2].FishSmell += fishnum;
        Ocean[  I+Jm2].FishSmell += fishnum;
        Ocean[Ip1+Jm2].FishSmell += fishnum;
        Ocean[Im1+Jp2].FishSmell += fishnum;
        Ocean[  I+Jp2].FishSmell += fishnum;
        Ocean[Ip1+Jp2].FishSmell += fishnum;
        Ocean[Ip2+Jm2].FishSmell += fishnum;
        Ocean[Ip2+Jm1].FishSmell += fishnum;
        Ocean[Ip2+  J].FishSmell += fishnum;
        Ocean[Ip2+Jp1].FishSmell += fishnum;
        Ocean[Ip2+Jp2].FishSmell += fishnum;
        Ocean[  I+  J].SharkSmell += 3*sharknum;
        Ocean[Im1+Jm1].SharkSmell += 2*sharknum;
        Ocean[Im1+  J].SharkSmell += 2*sharknum;
        Ocean[Im1+Jp1].SharkSmell += 2*sharknum;
        Ocean[  I+Jm1].SharkSmell += 2*sharknum;
        Ocean[  I+Jp1].SharkSmell += 2*sharknum;
        Ocean[Ip1+Jm1].SharkSmell += 2*sharknum;
        Ocean[Ip1+  J].SharkSmell += 2*sharknum;
        Ocean[Ip1+Jp1].SharkSmell += 2*sharknum;
        Ocean[Im2+Jm2].SharkSmell += sharknum;
        Ocean[Im2+Jm1].SharkSmell += sharknum;
        Ocean[Im2+  J].SharkSmell += sharknum;
        Ocean[Im2+Jp1].SharkSmell += sharknum;
        Ocean[Im2+Jp2].SharkSmell += sharknum;
        Ocean[Im1+Jm2].SharkSmell += sharknum;
        Ocean[  I+Jm2].SharkSmell += sharknum;
        Ocean[Ip1+Jm2].SharkSmell += sharknum;
        Ocean[Im1+Jp2].SharkSmell += sharknum;
        Ocean[  I+Jp2].SharkSmell += sharknum;
        Ocean[Ip1+Jp2].SharkSmell += sharknum;
        Ocean[Ip2+Jm2].SharkSmell += sharknum;
        Ocean[Ip2+Jm1].SharkSmell += sharknum;
        Ocean[Ip2+  J].SharkSmell += sharknum;
        Ocean[Ip2+Jp1].SharkSmell += sharknum;
        Ocean[Ip2+Jp2].SharkSmell += sharknum;
    }
    upc_barrier;
}
    
{ int I,J,K;
  int Ineigh[5];
  int Jneigh[5];
  int di, dj;
  int MaxfishSmell, MaxsharkSmell;
  int MaxfishSmellPosX, MaxfishSmellPosY;
  int MaxsharkSmellPosX, MaxsharkSmellPosY;

  upc_forall(K=0; K<GRIDSIZE; K++; &Ocean[K]){
     I = K&Imask;
     J = K&Jmask;
     MaxfishSmell=0;
     MaxsharkSmell=0;
     MaxfishSmellPosX = 0;
     MaxfishSmellPosY = 0;
     MaxsharkSmellPosX = 0;
     MaxsharkSmellPosY = 0;

     Ineigh[0] = (I - 8) & Imask;
     Ineigh[1] = (I - 2) & Imask;
     Ineigh[2] = I;
     Ineigh[3] = ((I|Jmask)+2) & Imask;
     Ineigh[4] = ((I|Jmask)+8) & Imask;

     Jneigh[0] = (J - 4) & Jmask;
     Jneigh[1] = (J - 1) & Jmask;
     Jneigh[2] = J;
     Jneigh[3] = ((J|Imask)+1) & Jmask;
     Jneigh[4] = ((J|Imask)+4) & Jmask;

     for(di=0; di<5; di++){
     for(dj=0; dj<5; dj++){
          
          if(Ocean[Ineigh[di] + Jneigh[dj] ].FishSmell > MaxfishSmell) {
              MaxfishSmell= Ocean[Ineigh[di] + Jneigh[dj] ].FishSmell;
              MaxfishSmellPosX = di-2;
              MaxfishSmellPosY = dj-2;
          }
          if(Ocean[Ineigh[di] + Jneigh[dj] ].SharkSmell > MaxsharkSmell) {
              MaxsharkSmell=Ocean[ Ineigh[di] + Jneigh[dj] ].SharkSmell;
              MaxsharkSmellPosX = di-2;
              MaxsharkSmellPosY = dj-2;
          }
     } }

     if( MaxsharkSmell == 0 ){
          if ( MaxfishSmellPosX > 0 )
             Ocean[K].FishForceX = 1;
          else if( MaxfishSmellPosX < 0 )
             Ocean[K].FishForceX = -1;
          else
             Ocean[K].FishForceX = ((int)rand()%3)-1;
          if ( MaxfishSmellPosY > 0 )
             Ocean[K].FishForceY = 1;
          else if( MaxfishSmellPosY < 0 )
             Ocean[K].FishForceY = -1;
          else
             Ocean[K].FishForceY = ((int)rand()%3)-1;
     } else {
        if ( MaxsharkSmellPosX > 0 )
           Ocean[K].FishForceX = -1;
        else if( MaxsharkSmellPosX < 0 )
           Ocean[K].FishForceX = 1;
        else
           Ocean[K].FishForceX = 0;
        if ( MaxsharkSmellPosY > 0 )
           Ocean[K].FishForceY = -1;
        else if( MaxsharkSmellPosY < 0 )
           Ocean[K].FishForceY = 1;
        else
           Ocean[K].FishForceY = 0;
     }
     
     if( MaxfishSmell == 0 ) { // move to center of mass
        if( FishMassX - ixtrct(I) == 0 ) 
            Ocean[K].SharkForceX = 0;
        else 
            Ocean[K].SharkForceX = 
            ((FishMassX - ixtrct(I)) * (abs(2*(FishMassX-ixtrct(I)))-ORDER) > 0 ) ? -1 : 1;

        if( FishMassY - jxtrct(J) == 0 ) 
            Ocean[K].SharkForceY = 0;
        else 
            Ocean[K].SharkForceY = 
            ((FishMassY - jxtrct(J)) * (abs(2*(FishMassY-jxtrct(J)))-ORDER) > 0 ) ? -1 : 1;
     } else {
        Ocean[K].SharkForceX = MaxfishSmellPosX;
        Ocean[K].SharkForceY = MaxfishSmellPosY;
     }
  } 
  upc_barrier;
}
    
{ struct Fish *fish, *babyfish, *next;

    for(fish=FishList; fish!=NULL; fish=next)
    {
        next = fish->next; /* DOB: need to grab this here in case fish dies, to ensure correct linked list traversal */
        if 
( ( fish->position->nsharks > 0 ) ||
  ( (fish->age > FishLifeExp) &&  ( (rand()%100) < FishDeathRate ) ) 
)
                             
           
{
  if(fish->before==NULL){
        if(fish->next == NULL)   /* the only fish in the list */
            FishList = NULL;
        else{
            fish->next->before = NULL;
            FishList = fish->next;
        }
  } else {
        if(fish->next == NULL) /* at least one fish before him but none after */
            fish->before->next = NULL;
        else{
            fish->before->next = fish->next;
            fish->next->before = fish->before;
        }
  }
  free(fish);
}
        else 
           
{ int I,J,newI,newJ;
  int iforce,jforce;
  struct Fish *babyfish;

  I = fish->position->positionX;
  J = fish->position->positionY;

  fish->vx += fish->position->FishForceX;
  if( fish->vx > MaxFishVelocity )
      fish->vx = MaxFishVelocity;
  if( fish->vx < MinFishVelocity )
      fish->vx = MinFishVelocity;
  fish->vy += fish->position->FishForceY;
  if( fish->vy > MaxFishVelocity )
      fish->vy = MaxFishVelocity;
  if( fish->vy < MinFishVelocity )
      fish->vy = MinFishVelocity;

  if( fish->vx == -2 ) 
     I = (I - 8) & Imask;
  else if( fish->vx == -1 )
	 I = (I - 2) & Imask;
  else if( fish->vx == 1 )
	 I = ((I|Jmask)+2) & Imask;
  else if (fish->vx == 2 )
	 I = ((I|Jmask)+8) & Imask;
  else 
     ;
  if( fish->vy == -2 ) 
     J = (J - 4) & Jmask;
  else if( fish->vy == -1 )
	 J = (J - 1) & Jmask;
  else if( fish->vy == 1 )
	 J = ((J|Imask)+1) & Jmask;
  else if (fish->vy == 2 )
	 J = ((J|Imask)+4) & Jmask;
  else 
     ;
  fish->position = &Ocean[I+J];
  if( fish->age > FishMature && 
      ( FishPop < MaxFishPop ) && ((rand()%100) <= FishBirthRate ) ){
        switch( rand()%3 ) {
            case 1:
              newI = (I-2) & Imask; break;
            case 2:
              newI = ((I|Jmask)+2) & Imask; break;
            default:
              newI = I;
        };
        switch( rand()%3 ) {
            case 1:
              newJ = (J-1) & Jmask; break;
            case 2:
              newJ = ((J|Imask)+1) & Jmask; break;
            default:
              newJ = J;
        };
		babyfish = CreateFish(0, newI, newJ);
		babyfish->next = FishList;
		babyfish->before = NULL;
		FishList->before = babyfish;
		FishList = babyfish;
	}
	fish->age +=1;
}
     }
}
    
{ struct Shark *shark, *next;
  
    for(shark=SharkList; shark!=NULL; shark=next)
    {
        next = shark->next; /* DOB: need to grab this here in case fish dies, to ensure correct linked list traversal */
         if(
( shark->hungry >= 100 || 
  shark->age > SharkLifeExp ||
  ( (SharkPop > MaxSharkPop) && (rand()%100 < SharkDeathRate) )
)
                          )
              
{
if(shark->before==NULL){
    if(shark->next == NULL)        /* that was the only shark in the list */
        SharkList = NULL;
    else{                         /* there is at least one shark after him */
        shark->next->before = NULL;
        SharkList = shark->next;
    }
} else {
    if(shark->next == NULL){  /* at least one shark before him but none after */
        shark->before->next = NULL;
    } else{
        shark->before->next = shark->next;
        shark->next->before = shark->before;
    }
}
free(shark);
}
         else {
              
{ int I,J,newI,newJ;
  int Idil[5]={0,2,8,10,32};
  int Jdil[5]={0,1,4,5,16};

  struct Shark *babyshark;

  I = shark->position->positionX;
  J = shark->position->positionY;

  shark->vx += shark->position->SharkForceX;
  if( shark->vx > MaxSharkVelocity )
      shark->vx = MaxSharkVelocity;
  if( shark->vx < MinSharkVelocity )
      shark->vx = MinSharkVelocity;
  shark->vy += shark->position->SharkForceY;
  if( shark->vy > MaxSharkVelocity )
      shark->vy = MaxSharkVelocity;
  if( shark->vy < MinSharkVelocity )
      shark->vy = MinSharkVelocity;

  if( shark->vx < 0 )
     I = ( I -  Idil[(-1)*shark->vx] ) & Imask;
  if( shark->vx > 0 )
     I = ((I|Jmask) + Idil[shark->vx] ) & Imask;
  if( shark->vy < 0 )
     J =  (J - Jdil[(-1)*shark->vy])  & Jmask;
  if( shark->vy > 0 )
     J = ((J|Imask) + Jdil[shark->vy]) & Jmask;

  if( shark->position->nfish>0 )
     shark->hungry -= shark->position->nfish * FISHCALS;    

  shark->position = &Ocean[ I+J ];
  if( (shark->age > SharkMature) && (shark->hungry < 0) &&
     (rand()%100)<= SharkBirthRate ) {
        switch( rand()%3 ) {
            case 1:
              newI = (I-2) & Imask; break;
            case 2:
              newI = ((I|Jmask)+2) & Imask; break;
            default:
             newI = I;
        };
        switch( rand()%3 ) {
            case 1:
              newJ = (J-1) & Jmask; break;
            case 2:
              newJ = ((J|Imask)+1) & Jmask; break;
            default:
             newJ = J;
        };
        babyshark = CreateShark(0,newI,newJ); 
        babyshark->next = SharkList;
        babyshark->before = NULL;
        SharkList->before = babyshark;
        SharkList = babyshark;
    }    

    shark->hungry += 1;
    shark->age += 1;
}                
         }
    }
}
    
upc_barrier;
if(MYTHREAD == 0 )
{
#ifndef BUPC_TEST_HARNESS
 int i,j;
 for(i=0; i<ORDER; i++){
   for(j=0; j<ORDER; j++){
      if( (Ocean[Zord(i,j)].nfish != 0) || (Ocean[Zord(i,j)].nsharks != 0 ) )
         printf("%c%c%c%c", i&0xFF, j&0xFF ,
         Ocean[Zord(i,j)].nfish & 0x7F, Ocean[Zord(i,j)].nsharks & 0x7F );
   }
 }
 printf("%c%c%c%c",0x0,0x0,0x0,0xFF);
#else
 printf("%d timesteps remain\n", timesteps);
#endif
}
upc_barrier;
} while( timesteps-->0 );

printf("done.\n");
return 0;
}
