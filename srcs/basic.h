#define MEMO_SIZE			2000000
#define OP_INSERT 			0x00000001
#define OP_QUERY			0x00000002
#define OP_DESTROY 			0x00000003

#define CIRCLE_LENGTH		100
#define Radius				20
#define RECT_LENGTH_X		30
#define RECT_LENGTH_Y		30
#define RECT_GAP			30
#define UNIT_LENGTH_Y		50
#define UNIT_GAP			40
#define CENTRE_X			0
#define CENTRE_Y			30
#define PICTURE_X			1000
#define PICTURE_Y			1000
#define INFI				999999999
#define MARGIN_LEFT			100


#define RANDOM_CASE			0x00000000
#define ASCENDED_CASE		0x00000001
#define DESCENDED_CASE		0x00000002
#define TEST_SIZE			1100000

#define BOTTOM_X			50
#define RESULT_WIDTH		40
#define RESULT_GAP			100
#define NUM_GAP				10
int myrand()
{
	return rand() * 32760 + rand();
}

struct CirCle
{
	int x, y, key, key2;
}circle[CIRCLE_LENGTH];
int tot_ID;

vector< pair<int,int> > edge;
struct BtreeRect
{
	int x, y, size;
	int key[10], son[10];
	bool leaf;
}btreeRect[CIRCLE_LENGTH];


