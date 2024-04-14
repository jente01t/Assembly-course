

#include <iostream>
#include "YmmVal.h"

extern "C" void AVXPackedInt_16(YmmVal *a, YmmVal *b, YmmVal c[6]);
extern "C" void AVXPackedInt_32(YmmVal *a, YmmVal *b, YmmVal c[5]);

void AVXPackedInt_16_Test(void);
void AVXPackedInt_32_Test(void);

int main()
{
	AVXPackedInt_16_Test();
	AVXPackedInt_32_Test();

	return 0;
}

void AVXPackedInt_16_Test(void) {

	__declspec(align(32)) YmmVal a;
	__declspec(align(32)) YmmVal b;
	__declspec(align(32)) YmmVal c[6];

	a.i16[0] = 30;		b.i16[0] = 3000;
	a.i16[1] = 56;		b.i16[1] = 7809;
	a.i16[2] = 785;		b.i16[2] = 10;
	a.i16[3] = 90828;	b.i16[3] = 5;
	a.i16[4] = -908;	b.i16[4] = 100;
	a.i16[5] = 234;		b.i16[5] = 87;
	a.i16[6] = -785;	b.i16[6] = 900;
	a.i16[7] = 1111;	b.i16[7] = 2222;
	a.i16[8] = 54;		b.i16[8] = 3000;
	a.i16[9] = 536;		b.i16[9] = 7809;
	a.i16[10] = 785;	b.i16[10] = 10;
	a.i16[11] = 90828;	b.i16[11] = 5;
	a.i16[12] = -908;	b.i16[12] = 100;
	a.i16[13] = 234;	b.i16[13] = 87;
	a.i16[14] = -785;	b.i16[14] = 900;
	a.i16[15] = 1111;	b.i16[15] = 2222;

	AVXPackedInt_16(&a, &b, c);
	printf("\nResult for int 16\n");
	printf("a     b  vpaddw   vpaddsw   vpsubw  cpsubsw  vpminsw  vpmaxsw\n");
	printf("****************************************************************");

	for (int i = 0; i < 16; i++)
	{
		const char * fs = "%7d";
		printf(fs, a.i16[i]);
		printf(fs, b.i16[i]);

		printf(fs, c[0].i16[i]);
		printf(fs, c[1].i16[i]);
		printf(fs, c[2].i16[i]);
		printf(fs, c[3].i16[i]);
		printf(fs, c[4].i16[i]);
		printf(fs, c[5].i16[i]);

		printf("\n");
	}

}

void AVXPackedInt_32_Test(void) {
	__declspec(align(32)) YmmVal a;
	__declspec(align(32)) YmmVal b;
	__declspec(align(32)) YmmVal c[5];

	a.i32[0] = 3540;		b.i32[0] = 30060;
	a.i32[1] = 55646;		b.i32[1] = 782309;
	a.i32[2] = 76585;		b.i32[2] = 10213;
	a.i32[3] = 90828;		b.i32[3] = 3212;
	a.i32[4] = -932108;		b.i32[4] = 1030;
	a.i32[5] = 23324;		b.i32[5] = 8237;
	a.i32[6] = -73285;		b.i32[6] = 9030;
	a.i32[7] = 11511;		b.i32[7] = 22222;

	AVXPackedInt_32(&a, &b, c);
	printf("\nResult for int 32\n");
	printf("a     b  vpaddd   vphsubd   vpmulld  vpsllvd  vpsravd\n");
	printf("****************************************************************");

	for (int i = 0; i < 8; i++)
	{
		const char * fs = "%8d";
		printf(fs, a.i32[i]);
		printf(fs, b.i32[i]);

		printf(fs, c[0].i32[i]);
		printf(fs, c[1].i32[i]);
		printf(fs, c[2].i32[i]);
		printf(fs, c[3].i32[i]);
		printf(fs, c[4].i32[i]);

		printf("\n");
	}

}