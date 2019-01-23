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
// Definitions checks
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// General Header file includes
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
#define nl "\n"

///////////////////////////////////////////////////////////////////////////////
// Debugging macros
///////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG
//---------------------------------------------------------------------------//
// Print the value of X
//---------------------------------------------------------------------------//
  #define DBG(X) STREAM<<#X<<"\t:\t"<<(X)<<NL
  #define xdbg(X) DBG((X))
  #define DBG2(X,Y) DBG((X)); DBG((Y));
  #define xdbg2(X,Y) DBG2((X),(Y))
  #define DBG3(X,Y,Z) DBG((X)); DBG((Y)); DBG((Z));
  #define xdbg3(X,Y,Z) xdbg3((X),(Y),(Z))

//---------------------------------------------------------------------------//
// Print the vector VEC
//---------------------------------------------------------------------------//
  #define DBGVEC(VEC) \
  STREAM<<#VEC<<"\t:\t["; \
  for(szt i=1;i<(VEC).size();++i) { \
  STREAM<<(VEC)[i]<<","; \
  } \
  STREAM<<"]"<<NL;

  #define xdbgvec(VEC) DBGVEC((VEC))

//---------------------------------------------------------------------------//
// Print the matrix VEC2
//---------------------------------------------------------------------------//
  #define DBGVEC2(VEC2) \
  STREAM<<#VEC2; \
  for(szt i=1;i<(VEC2).size();++i) { \
    STREAM<<"\t:\t["; \
    for(szt j=1;j<(VEC2)[i].size();++j) { \
      STREAM<<(VEC2)[i][j]<<","; \
    } \
    STREAM<<"]"<<NL; \
  } 

  #define xbdgvec2(VEC2) DBGVEC2((VEC2))

#endif

// If DEBUG is not defined then do not use the debugging features
#ifndef DEBUG
  #define DBG(X) 
  #define xdbg(X) 
  #define DBG2(X,Y) 
  #define xdbg2(X) 
  #define DBG3(X,Y,Z)
  #define xdbg3(X) 
  #define DBGVEC(VEC) 
  #define xdbgvec(VEC)
  #define DBGVEC2(VEC2)
  #define xbdgvec2(VEC2)
#endif

///////////////////////////////////////////////////////////////////////////////
// Basic datatype definition macros
///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------//
// 1D vector of type TYPE
//---------------------------------------------------------------------------//
#define VEC(TYPE) std::vector< TYPE >
#define xvec(TYPE) VEC(TYPE)

//---------------------------------------------------------------------------//
// 2D vector( essentially a matrix) of type TYPE
//---------------------------------------------------------------------------//
#define VEC2(TYPE) std::vector<std::vector< TYPE > >
#define xvec2(TYPE) VEC2(TYPE)

//---------------------------------------------------------------------------//
// Tree set of type TYPE
//---------------------------------------------------------------------------//
#define TSET(TYPE) std::set< TYPE >
#define xtset(TYPE) TSET(TYPE)

//---------------------------------------------------------------------------//
// Tree map of type TYPE 
//---------------------------------------------------------------------------//
#define TMAP(XTYPE,YTYPE) std::map< XTYPE , YTYPE >
#define xtmap(XTYPE,YTYPE) TMAP(XTYPE,YTYPE)

//---------------------------------------------------------------------------//
// Hash set of type TYPE
//---------------------------------------------------------------------------//
#define HSET(TYPE) std::unordered_set< TYPE >
#define xhset(TYPE) HSET(TYPE)

//---------------------------------------------------------------------------//
// Hash map of type TYPE
//---------------------------------------------------------------------------//
#define HMAP(XTYPE,YTYPE) std::unordered_map< XTYPE , YTYPE >
#define xhmap(XTYPE,YTYPE) HMAP(XTYPE,YTYPE)

///////////////////////////////////////////////////////////////////////////////
// Commonly used macros for vector
///////////////////////////////////////////////////////////////////////////////
#define EMBK emplace_back
#define xembk EMBK
#define PSBK push_back
#define xpsbk PSBK
#define RSRV reserve
#define xrsrv RSRV

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
#define xend END
#define ENDDO END
#define xenddo ENDDO
#define ENDIF END
#define xendif ENDIF
#define ENDWHILE END
#define xendwhile ENDWHILE

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
// >> u32 i,j;
// >> DO(i,1,2)
// >>   cout<<i<<endl;
// >>   DO(j,3,4)
// >>     cout<<j<<",";
// >>   ENDDO
// >>   cout<<endl;
// >> ENDDO
//
// RESULT : Should print,
// 1
// 3,4,
// 2
// 3,4,
//---------------------------------------------------------------------------//
#define DO(I,START,END)  for((I)=(START); (I)<=(END); ++(I)) {
#define xdo(I,START,END) DO(I,START,END)

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
// >> u32 i,j;
// >> RDO(i,2,1)
// >>   cout<<i<<endl;
// >>   RDO(j,4,3)
// >>     cout<<j<<",";
// >>   ENDDO
// >>   cout<<endl;
// >> ENDDO
//
// RESULT : Should print,
// 2
// 4,3,
// 1
// 4,3,
//---------------------------------------------------------------------------//
#define RDO(I,START,END) for((I)=(START); (I)>=(END); --(I)) {
#define xrdo(I,START,END) RDO(I,START,END)

//---------------------------------------------------------------------------//
// Macro for 1 variable based general loop
// NOTE : These can be nested together.
//---------------------------------------------------------------------------//
// USE : 1D forward driving inclusive range case
// >> DOX(u32,i,1,<=,5,++i) // >> Expands to : for(u32 i=1;i<=5;++i)
// >>   cout<<i<<",";
// >> ENDDO
// 
// RESULT : Should print,
// 1,2,3,4,5,
//---------------------------------------------------------------------------//
// USE : 1D reverse driving exclusive range case
// >> DOX(u32,i,5,>,1,--i) // >> Expands to : for(u32 i=5;i>1;--1)
// >>   cout<<i<<",";
// >> ENDDO
//
// RESULT : Should print,
// 5,4,3,2,
//---------------------------------------------------------------------------//
#define DOX(TYPE,I,START,OP,END,STEP_OP) \
        for(TYPE (I)=(START);(I) OP (END);(STEP_OP)){

#define xdox(TYPE,I,START,OP,END,STEP_OP) DOX(TYPE,I,START,OP,END,STEP_OP)

//---------------------------------------------------------------------------//
// While loop
//---------------------------------------------------------------------------//
// USE : 
// >> s32 i=10;
// WHILE(i--)
//  cout<<i<<",";
// ENDWHILE
// 
// RESULT : Should print
// 9,8,7,6,5,4,3,2,1,0,
//---------------------------------------------------------------------------//
#define WHILE(CONDITION) while((CONDITION)) {
#define xwhile(CONDITION) WHILE((CONDITION))

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
#define xif(CONDITION) IF((CONDITION))
#define ELSE } else {
#define xelse(CONDITION) ELSE((CONDITION))
#define ELSEIF(CONDITION) } else if((CONDITION)) {
#define xelseif(CONDITION) ELSEIF((CONDITION))

///////////////////////////////////////////////////////////////////////////////
// Mathematics
///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------//
// Square of the given expression 
//---------------------------------------------------------------------------//
// USE : Just pass in an expression to square
// >> VEC(u32) x = {0,1,2,3,4,5};
// >> cout<<SQ(x[5])<<endl;
//
// RESULT : Should print,
// 25
//---------------------------------------------------------------------------//
#define SQ(CMD) (CMD)*(CMD)
#define xsq(CMD) SQ((CMD))

//---------------------------------------------------------------------------//
// Cube of the given  expression 
//---------------------------------------------------------------------------//
// USE : Just pass in an expression to cube
// >> VEC(u32) x = {0,1,2,3,4,5};
// >> cout<<SQ(x[5])<<endl;
//
// RESULT : Should print,
// 125
//---------------------------------------------------------------------------//
#define CU(CMD) (CMD)*(CMD)*(CMD)
#define xcu(CMD) CU((CMD))

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
