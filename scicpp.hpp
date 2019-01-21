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
/// @project scicpp
/// @file    scicpp.hpp
/// @version 0.0.1 (alpha)
/// @brief   Scientific coding standard and library for C++.
/// @date    20-JAN-2019
/// @author  Sayan Bhattacharjee (aerosayan)
/// @email   aero.sayan@gmail.com
/// @license DEFAULT. Will be made Open-Source after development is completed.
///////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER :
/// This is the intellectual property of the author Sayan Bhattacharjee.
/// Currently this is not being distributed since development is incomplete.
/// In future, proper licensing will be done and this coding standard and 
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
// The loop iterator data type used
// unsigned int is used by default to be able to handle very large loops
//---------------------------------------------------------------------------//
#define szt unsigned int

//---------------------------------------------------------------------------//
// Should the debugging be in cerr/cout/clog ?
// Default : std::cout
//---------------------------------------------------------------------------//
#define STREAM std::cout

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
#define DBG(X) STREAM<<#X<<"\t:\t"<<(X)<<NL
#define DBG2(X,Y) DBG(X); DBG(Y)
#define DBG3(X,Y,Z) DBG(X); DBG(Y); DBG(Z);

//---------------------------------------------------------------------------//
// Print the array ARR
//---------------------------------------------------------------------------//
#define DBGARR(ARR) \
STREAM<<#ARR<<"\t:\t["; \
for(szt i=1;i<(ARR).size();++i) { \
  STREAM<<(ARR)[i]<<","; \
} \
STREAM<<"]"<<NL;

//---------------------------------------------------------------------------//
// Print the matrix MAT
//---------------------------------------------------------------------------//
#define DBGMAT(MAT) \
STREAM<<#MAT; \
for(szt i=1;i<(MAT).size();++i) { \
  STREAM<<"\t:\t["; \
  for(szt j=1;j<(MAT)[i].size();++j) { \
    STREAM<<(MAT)[i][j]<<","; \
  } \
  STREAM<<"]"<<NL; \
} 

#endif

// If DEBUG is not defined then do not use the debugging features
#ifndef DEBUG
#define DBG(X) 
#define DBG2(X,Y) 
#define DBG3(X,Y,Z)
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
//---------------------------------------------------------------------------//
// USE : Cosmetic use
// >> DO(i,1,n)
// >>   y[i] = sin(x[i]);
// >>   IF(y[i] > 1.0)
// >>     break;
// >>   ENDIF
// >> ENDDO
//---------------------------------------------------------------------------//
#define END }
#define ENDDO END
#define ENDIF END

//---------------------------------------------------------------------------//
// Increment variable I in the inclusive range [START,END] with step=+1
// NOTE : These can be nested together.
//---------------------------------------------------------------------------//
// NOTE : TYPE for varialbe I needs to be set before calling DO
//---------------------------------------------------------------------------//
// USE : 1D case
// >> u32 i;
// >> DO(i,1,5)
// >>   cout<<i<<",";
// >> ENDDO
// 
// RESULT : Should print,
// 1,2,3,4,5,
//---------------------------------------------------------------------------//
// USE : Nested 2D case
// >> u32 i;
// >> DO(i,1,2)
// >>   cout<<i<<endl;
// >>   DO(j,3,4)
// >>     cout<<j<<",";
// >>   ENDDO
// >> ENDDO
//
// RESULT : Should print,
// 1
// 3,4,
// 2
// 3,4,
//---------------------------------------------------------------------------//
#define DO(I,START,END)  for((I)=(START); (I)<=(END); ++(I)) {

//---------------------------------------------------------------------------//
// Decrement variable I in the inclusive range [START,END] with step=-1
// NOTE : These can be nested together.
//---------------------------------------------------------------------------//
// NOTE : TYPE for varialbe I needs to be set before calling DO
//---------------------------------------------------------------------------//
// USE : 1D case 
// >> u32 i;
// >> RDO(i,5,1)
// >>   cout<<i<<",";
// >> ENDDO
// 
// RESULT : Should print,
// 5,4,3,2,1
//---------------------------------------------------------------------------//
// USE : Nested 2D case
// >> u32 i;
// >> RDO(i,2,1)
// >>   cout<<i<<endl;
// >>   RDO(j,4,3)
// >>     cout<<j<<",";
// >>   ENDDO
// >> ENDDO
//
// RESULT : Should print,
// 2
// 4,3,
// 1
// 4,3,
//---------------------------------------------------------------------------//
#define RDO(I,START,END) for((I)=(START); (I)>=(END); --(I)) {

//---------------------------------------------------------------------------//
// Macro for 1 variable based for loop
// NOTE : These can be nested together.
//---------------------------------------------------------------------------//
// USE : 1D forward driving inclusive range case
// >> DOX(u32,i,1,<=,5,1) // >> Expands to : for(u32 i=1;i<=5;i+=1)
// >>   cout<<i<<",";
// >> ENDDO
// 
// RESULT : Should print,
// 1,2,3,4,5,
//---------------------------------------------------------------------------//
// USE : 1D reverse driving exclusive range case
// >> DOX(u32,i,5,>,1,-1) // >> Expands to : for(u32 i=5;i>1;i+=-1)
// >>   cout<<i<<",";
// >> ENDDO
//
// RESULT : Should print,
// 5,4,3,2,
//---------------------------------------------------------------------------//
#define DOX(TYPE,I,START,OP,END,STEP) \
        for(TYPE (I)=(START);(I) OP (END);(I)+=(STEP)){

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

///////////////////////////////////////////////////////////////////////////////
// Mathematics
///////////////////////////////////////////////////////////////////////////////
#define SQ(CMD) (CMD)*(CMD)
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
