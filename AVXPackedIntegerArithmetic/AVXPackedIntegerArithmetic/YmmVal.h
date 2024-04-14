#pragma once
#include "MiscDef.h"

union YmmVal {
	Int8 i8[32];		//mmx registers are 64-bit in length, abd can therefore hold 8 8bit values
	Int16 i16[16];	//mmx registers can hold 4 16bit values
	Int32 i32[8];	//mmx registers can hold 2 32bit values
	Int64 i64[4];		//mmx registers can hold 1 64bit value (no array)

	Uint8 u8[32];
	Uint16 u16[16];
	Uint32 u32[8];
	Uint64 u64[4];

	float r32[8];
	double r64[4];

	char* ToString_i8(char *s, size_t len, bool upper_half);
	char* ToString_i16(char *s, size_t len, bool upper_half);
	char* ToString_i32(char *s, size_t len, bool upper_half);
	char* ToString_i64(char *s, size_t len, bool upper_half);

	char* ToString_u8(char *s, size_t len, bool upper_half);
	char* ToString_u16(char *s, size_t len, bool upper_half);
	char* ToString_u32(char *s, size_t len, bool upper_half);
	char* ToString_u64(char *s, size_t len, bool upper_half);

	char* ToString_x8(char *s, size_t len, bool upper_half);
	char* ToString_x16(char *s, size_t len, bool upper_half);
	char* ToString_x32(char *s, size_t len, bool upper_half);
	char* ToString_x64(char *s, size_t len, bool upper_half);

	char* ToString_r32(char *s, size_t len, bool upper_half);
	char* ToString_r64(char *s, size_t len, bool upper_half);
};