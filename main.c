#include "space.h"
#include "input.h"
#include "isWinner.h"
#include "mine.h"
#include "gameOutput.h"




int main(void)
{
	//¥Ú”°≤‚ ‘
	outMineBox out [ROW][LINE] = { {0,1,2,3} };
	mineBoxIn in [ROW][LINE] = { {0,7} };
	putSpaceOut(in, out, ROW, LINE);

	// ‰»Î≤‚ ‘
	/*char fuck[20] = "\0";
	inputStrInformation(fuck, 20, "fuck", 19);
	puts(fuck);*/


	return 0;
}