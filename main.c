#include "space.h"
#include "isWinner.h"
#include "mine.h"
#include "gameOutput.h"
#include "gameInput.h"




int main(void)
{
	// ‰»Î≤‚ ‘
	mineBoxIn space[ROW][LINE] = { {0,8} };
	outMineBox outSpace[ROW][LINE] = { {0,0} };
	lineAxis line = 2;
	rowAxis row = 0;
	inputKind kind = 0;
	playerInput(outSpace, "what", 10, ROW, LINE);
	putSpaceOut(space, outSpace, ROW, LINE);

	//¥Ú”°≤‚ ‘
	/*outMineBox out [ROW][LINE] = { {0,1,2,3} };
	mineBoxIn in [ROW][LINE] = { {0,7} };
	putSpaceOut(in, out, ROW, LINE);*/

	
	


	return 0;
}