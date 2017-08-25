#include<math.h>

unsigned long long int fact(int j)
{
	switch (j) {
		case 0: {return(1);}break;
		case 1: {return(1);}break;
		case 2: {return(2);}break;
		case 3: {return(6);}break;
		case 4: {return(24);}break;
		case 5: {return(120);}break;
		case 6: {return(720);}break;
		case 7: {return(5040);}break;
		case 8: {return(40320);}break;
		case 9: {return(362880);}break;
		case 10: {return(3628800);}break;
		case 11: {return(39916800);}break;
		case 12: {return(479001600);}break;
		case 13: {return(6227020800);}break;
		case 14: {return(87178291200);}break;
		case 15: {return(1307674368000);}break;
		case 16: {return(20922789888000); }break;
		case 17: {return(355687428096000); }break;
	}
	return(1);
}