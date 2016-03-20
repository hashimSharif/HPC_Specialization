



int main(){
	 		
	int a = 10;
	int b = 6;

/* 
    asm("mfence");
    asm("lock movl %%1, %%eax;" 
    	: "=r" (b) 
    	: "%eax"
    	);
   */
    
     int src = 1;
     int dst = 1;
     int d = src -dst;

     asm ("SUB %1, %0\n\t"
         "add $1, %0"
         : "=r" (dst)
         : "r" (src));


	/*asm ("movl %1, %%eax; 
	      movl %%eax, %0;"
	     :"=r"(b)        
	     :"r"(a)         
	     :"%eax"         
	     );
	 */


	int c = 4;

	return b;
 }