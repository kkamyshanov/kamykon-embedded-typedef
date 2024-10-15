//==============================================================================
//! @file typedef.h
//!
//! @brief There is no .c file attached to this file 
//! Defining types and macros for working with variable types
//~
//! @copyright Copyright © 2024 Confidential Information of 
//! Kamykon Consumer Products. All rights reserved.
//!
//! TODO: Need to update 
//! - copyright template (c.h (kamykon-c-code-style))
//! - header of file (Need DOXYGEN format)
//!
//==============================================================================
#ifndef TYPEDEF_H
#define TYPEDEF_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

//==============================================================================
// Includes
//==============================================================================
#include <stdio.h>
#include <assert.h>

//==============================================================================
// Type Definitions
//==============================================================================
/* Unsigned */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

/* Signed */
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

/* Floating-point */
typedef float f32;

/* Characters */
typedef char c8;

/* Boolean */
#ifdef _STDBOOL_H
#error "Do not use stdbool.h"
#endif /* #ifdef _STDBOOL_H */
typedef u8 bool;

/* size_t */
#ifndef __SIZE_TYPE__ 
typedef u32 size_t;
#endif /* #ifndef __SIZE_TYPE__ */
static_assert(sizeof(size_t) == sizeof(u32), "Bad length for size_t");
/* TODO: Add callback for user configuration (app.h for example)*/

/* ptrdiff_t */
#ifndef __PTRDIFF_TYPE__ 
typedef s32 ptrdiff_t;
#endif /* #ifndef __PTRDIFF_TYPE__ */
static_assert(sizeof(ptrdiff_t) == sizeof(s32), "Bad length for ptrdiff_t");
/* TODO: Add callback for user configuration (app.h for example)*/

/* TODO: Need add another standart types (wchar_t, wint_t, ssize_t)*/

//==============================================================================
// Macros
//==============================================================================
/* Boolean */
#define false ((bool)0)
#define true ((bool)1)

/* Null pointer */
#ifndef NULL
#define NULL ((void *)0)
#endif /* #ifndef NULL */

/* End of string */
#ifdef EOS
#warning "End of line already defined"
#endif /* #ifdef EOS */
#undef EOS
#define EOS ((c8)'\0')

/* Getting size */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#ifdef __WEAK
#warning "__WEAK already define"
#undef __WEAK
#endif /* #ifdef __WEAK */
#ifndef __WEAK
#define __WEAK __attribute__((weak))
#endif

#ifdef __STATIC_FORCEINLINE
#warning "__STATIC_FORCEINLINE already define"
#undef __STATIC_FORCEINLINE
#endif /* #ifdef __STATIC_FORCEINLINE */
#ifndef __STATIC_FORCEINLINE
#define __STATIC_FORCEINLINE static inline __attribute__((always_inline))
#endif

//==============================================================================
// File End
//==============================================================================
#ifdef __cplusplus
} /* extern "C" { */
#endif /* #ifdef __cplusplus */

#endif /* #ifndef TYPEDEF_H */
