<<<<<<< HEAD

=======
>>>>>>> 012153f5255401c33da65b3242a845d61ee3d747

#include <stdio.h>

char f0[][9]={"   *   \n",
	      "  ***  \n",
	      " ***** \n",
	      "*******\n",
	      " HHOHH \n",
	      " ZZZZZ "
	    };

int main(void){
 for(int i=0;i<6;i++){
  printf(*(f0+i));
 }
 return 0;
}

