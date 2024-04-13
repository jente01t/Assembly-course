

#include <iostream>
#include "XmmVal.h"

extern "C" void SsePackedInt16_Add(const XmmVal *a, const XmmVal *b, XmmVal c[2]); 
extern "C" void SsePackedInt32_Sub(const XmmVal *a, const XmmVal *b, XmmVal *c);
extern "C" void SsePackedInt32_Mul(const XmmVal *a, const XmmVal *b, XmmVal c[2]);

void SsePackedInt16_Add_Test(void);
void SsePackedInt32_Sub_Test(void);
void SsePackedInt32_Mul_Test(void);

int main()
{
	SsePackedInt16_Add_Test();
	SsePackedInt32_Sub_Test();
	SsePackedInt32_Mul_Test();
}

void SsePackedInt16_Add_Test(void) {
	_declspec(align(16)) XmmVal a;
	_declspec(align(16)) XmmVal b;
	_declspec(align(16)) XmmVal c[2];
	char buff[256];

	a.i16[0] = 10; b.i16[0] = 486;
	a.i16[1] = 210; b.i16[1] = 950;
	a.i16[2] = -890; b.i16[2] = 50;
	a.i16[3] = 234; b.i16[3] = 57;
	a.i16[4] = 46; b.i16[4] = 89;
	a.i16[5] = 67; b.i16[5] = 6;
	a.i16[6] = 86; b.i16[6] = 90;
	a.i16[7] = 1460; b.i16[7] = 920;

	SsePackedInt16_Add(&a, &b, c);

	printf("\nresult for SsePackedInt16_Add\n");
	printf("A: %s\n", a.ToString_i16(buff, sizeof(buff)));
	printf("B: %s\n", b.ToString_i16(buff, sizeof(buff)));
	printf("C: %s\n", c[0].ToString_i16(buff, sizeof(buff)));
	printf("\n");
	printf("A: %s\n", a.ToString_i16(buff, sizeof(buff)));
	printf("B: %s\n", b.ToString_i16(buff, sizeof(buff)));
	printf("C: %s\n", c[1].ToString_i16(buff, sizeof(buff)));
}

void SsePackedInt32_Sub_Test(void) {
	_declspec(align(16)) XmmVal a;
	_declspec(align(16)) XmmVal b;
	_declspec(align(8)) XmmVal c;
	char buff[256];

	a.i32[0] = 10;		b.i32[0] = 486;
	a.i32[1] = 210;		b.i32[1] = 950;
	a.i32[2] = -890;	b.i32[2] = 50;
	a.i32[3] = 234;		b.i32[3] = 57;


	SsePackedInt32_Sub(&a, &b, &c);

	printf("\nresult for SsePackedInt32_Sub\n");
	printf("A: %s\n", a.ToString_i32(buff, sizeof(buff)));
	printf("B: %s\n", b.ToString_i32(buff, sizeof(buff)));
	printf("C: %s\n", c.ToString_i32(buff, sizeof(buff)));

}

void SsePackedInt32_Mul_Test(void) {
	_declspec(align(16)) XmmVal a;
	_declspec(align(16)) XmmVal b;
	_declspec(align(8)) XmmVal c[2];
	char buff[256];

	a.i32[0] = 10;		b.i32[0] = 486;
	a.i32[1] = 210;		b.i32[1] = 950;
	a.i32[2] = -890;	b.i32[2] = 50;
	a.i32[3] = 234;		b.i32[3] = 57;


	SsePackedInt16_Add(&a, &b, c);

	printf("\nresult for SsePackedInt32_Mul\n");
	printf("A: %s\n", a.ToString_i32(buff, sizeof(buff)));
	printf("B: %s\n", b.ToString_i32(buff, sizeof(buff)));
	printf("C: %s\n", c[0].ToString_i32(buff, sizeof(buff)));
	printf("\n");
	printf("\nresult for SsePackedInt32_Mul\n");
	printf("A: %s\n", a.ToString_i32(buff, sizeof(buff)));
	printf("B: %s\n", b.ToString_i32(buff, sizeof(buff)));
	printf("C: %s\n", c[1].ToString_i32(buff, sizeof(buff)));

}