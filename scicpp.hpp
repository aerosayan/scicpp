///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                                                           //
//               .|'''||            .|'''', '||'''|, '||'''|,                //
//               ||             ''  ||       ||   ||  ||   ||                //
//               `|'''|, .|'',  ||  ||       ||...|'  ||...|'                // 
//                .   || ||     ||  ||       ||       ||                     // 
//               ||...|' `|..' .||. `|....' .||      .||                     //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
/// @file    scicpp.hpp
/// @version 0.0.1 (alpha)
/// @brief   Scientific coding standard and library for C++.
/// @author  Sayan Bhattacharjee (aerosayan)
/// @email   aero.sayan@gmail.com
/// @license DEFAULT. Will be made Open-Source after development is completed.
///////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER :
/// This is the intellectual property of the author Sayan Bhattacharjee.
/// Currently this is not being distributed since development is incompmlete.
/// In future proper licensing will be done and this coding standard and 
/// library will be made Open-Source. We do not give any guarantee for the 
/// correct operation of the library, neither are we to be held responsible
/// for any kind of damage caused by the use of this software.
///////////////////////////////////////////////////////////////////////////////
/// Thank you for your understanding, support and patience.
///////////////////////////////////////////////////////////////////////////////

#ifndef __SCICPP_HPP__
#define __SCICPP_HPP__
///////////////////////////////////////////////////////////////////////////////
// Header file includes
///////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>

//---------------------------------------------------------------------------//
// Should the debugging be in cerr/cout/clog ?
// Default : std::cerr
//---------------------------------------------------------------------------//
#define STREAM std::cerr

//---------------------------------------------------------------------------//
//  Newline 
//---------------------------------------------------------------------------//
#define NL std::endl;

///////////////////////////////////////////////////////////////////////////////
// Debugging macros
///////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG
//---------------------------------------------------------------------------//
// Print the value of X
//---------------------------------------------------------------------------//
#define DBG(X) STREAM<<#X<<"\t:\t"<<(X)<<NL;

//---------------------------------------------------------------------------//
// Print the array ARR
//---------------------------------------------------------------------------//
#define DBGARR(ARR) \
STREAM<<#ARR<<"\t:\t["; \
for(auto x: (ARR)) { \
  STREAM<<x<<","; \
} \
STREAM<<"]"<<NL;

//---------------------------------------------------------------------------//
// Print the matrix MAT
//---------------------------------------------------------------------------//
#define DBGMAT(MAT) \
STREAM<<#MAT<<"\n"; \
for(auto vec: (MAT)) {\
  STREAM<<"\t:\t["; \
  for(auto x : vec) { \
    STREAM<<x<<","; \
  } \
  STREAM<<"]"<<NL; \
} 

#endif

// If DEBUG is not defined then do not use the debugging features
#ifndef DEBUG
#define DBG(X) 
#define DBGARR(ARR) 
#define DBGMAT(MAT)
#endif

///////////////////////////////////////////////////////////////////////////////
// Datatype definition macros
///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------//
// 1D vector of type TYPE
//---------------------------------------------------------------------------//
#define VEC(TYPE) std::vector< TYPE >

//---------------------------------------------------------------------------//
// 2D matrix of type TYPE
//---------------------------------------------------------------------------//
#define MAT(TYPE) std::vector<std::vector< TYPE > >

///////////////////////////////////////////////////////////////////////////////
// Commonly used macros for vector
///////////////////////////////////////////////////////////////////////////////
#define EMBK emplace_back
#define PSBK push_back
#define RSRV reserve

///////////////////////////////////////////////////////////////////////////////
// Language extensions
///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------//
// The loop iterator data type used
// unsigned int is used by default to be able to handle very large loops
//---------------------------------------------------------------------------//
#define szt unsigned int

//---------------------------------------------------------------------------//
// The ending of a command block.
// NOTE : END,ENDIF,ENDDO etc are all the same.
// Different flavours of end are provided to help writing expressive code.
//---------------------------------------------------------------------------//
// USE : Simple use
// >> DO(i,1,n)
// >>   y[i] = sin(x[i]);
// >>   IF(y[i] > 1.0)
// >>     break;
// >>   END
// >> END 
//
// USE : Cosmetic use
// >> DO(i,1,n)
// >>   y[i] = sin(x[i]);
// >>   IF(y[i] > 1.0)
// >>     break;
// >>   ENDIF
// >> ENDDO
//---------------------------------------------------------------------------//
#define END }

//---------------------------------------------------------------------------//
// Increment variable I in the inclusive range [START,END]
// NOTE : These can be nested together.
//---------------------------------------------------------------------------//
// USE : 1D case
// >> DO(i,1,n)
// >>   y[i] = sqrt(x[i]);
// >> ENDDO
// 
// USE : Nested 2D case
// >> DO(i,1,n)
// >>   DO(j,1,m)
// >>     mat[i][j] = sin(mat[i][j]) + cos(x[j]);
// >>   ENDDO
// >> ENDDO
//---------------------------------------------------------------------------//
#define DO(I,START,END) for(szt (I)=(START); (I)<=(END); ++(I)) {
#define ENDDO END

//---------------------------------------------------------------------------//
// Conditional operations
// USE : IF , ELSE and ELSEIF
// >> IF(x == 0)
// >>   std::cout<<"x == 0 : breaking..."<<std::endl;
// >>   break;
// >> ELSEIF(x == 1)
// >>   std::cout<<"x == 1 : continuing..."<<std::endl;
// >>   continue;
// >> ELSE
// >>   y += x;
// >> ENDIF
//---------------------------------------------------------------------------//
#define IF(CONDITION) if((CONDITION)) {
#define ELSE } else {
#define ELSEIF(CONDITION) } else if((CONDITION)) {
#define ENDIF END

///////////////////////////////////////////////////////////////////////////////
// Basic data types
///////////////////////////////////////////////////////////////////////////////
typedef int16_t         s16;
typedef uint16_t        u16;

typedef int32_t         s32;
typedef uint32_t        u32;

typedef float           f32;
typedef double          f64;

///////////////////////////////////////////////////////////////////////////////
// Commonly used vector types
///////////////////////////////////////////////////////////////////////////////
typedef std::vector<s32>   vs32;
typedef std::vector<u32>   vu32;
typedef std::vector<f32>   vf32;
typedef std::vector<f64>   vf64;

///////////////////////////////////////////////////////////////////////////////
// Commonly used multidimensional vector types
///////////////////////////////////////////////////////////////////////////////
typedef std::vector<std::vector<s32> >   v2s32;
typedef std::vector<std::vector<u32> >   v2u32;
typedef std::vector<std::vector<f32> >   v2f32;
typedef std::vector<std::vector<f64> >   v2f64;
#endif 
