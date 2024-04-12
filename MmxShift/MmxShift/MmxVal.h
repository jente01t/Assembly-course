#pragma once
#include "MiscDef.h"

union MmxVal {
	Int8 i8[8];		//mmx registers are 64-bit in length, abd can therefore hold 8 8bit values
	Int16 i16[4];	//mmx registers can hold 4 16bit values
	Int32 i32[2];	//mmx registers can hold 2 32bit values
	Int64 i64;		//mmx registers can hold 1 64bit value (no array)

	Uint8 u8[8];
	Uint16 u16[4];
	Uint32 u32[2];
	Uint64 u64;

	char* ToString_i8(char *s, size_t len);
	char* ToString_i16(char *s, size_t len);
	char* ToString_i32(char *s, size_t len);
	char* ToString_i64(char *s, size_t len);

	char* ToString_u8(char *s, size_t len);
	char* ToString_u16(char *s, size_t len);
	char* ToString_u32(char *s, size_t len);
	char* ToString_u64(char *s, size_t len);

	char* ToString_x8(char *s, size_t len);
	char* ToString_x16(char *s, size_t len);
	char* ToString_x32(char *s, size_t len);
	char* ToString_x64(char *s, size_t len);
};