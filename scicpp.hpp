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
#include <limits>


//---------------------------------------------------------------------------//
// The loop iterator data type used
// unsigned int is used by default to be able to handle very large loops
//---------------------------------------------------------------------------//
#define szt unsigned int

//---------------------------------------------------------------------------//
// Should the debugging be in cerr/cout/clog ?
// Default : std::cerr
//---------------------------------------------------------------------------//
#define STREAM std::cerr

//---------------------------------------------------------------------------//
//  Newline
//---------------------------------------------------------------------------//
#define NL std::endl;
#define nl "\n"

//---------------------------------------------------------------------------//
// sizeof
//---------------------------------------------------------------------------//
#define SOF sizeof
#define xsof SOF

///////////////////////////////////////////////////////////////////////////////
// Debugging macros
///////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG
//---------------------------------------------------------------------------//
// Print the value of any thing
//---------------------------------------------------------------------------//
  #define DBG(X) STREAM<<"DBG :: "<<#X<<"\t:\t"<<(X)<<NL
  #define xdbg(X) DBG((X))
  #define DBG2(X,Y) DBG((X)); DBG((Y));
  #define xdbg2(X,Y) DBG2((X),(Y))
  #define DBG3(X,Y,Z) DBG((X)); DBG((Y)); DBG((Z));
  #define xdbg3(X,Y,Z) xdbg3((X),(Y),(Z))
  #define DBG4(W,X,Y,Z) DBG((W)); DBG((X)); DBG((Y)); DBG((Z));
  #define xdbg4(W,X,Y,Z) xdbg4((W),(X),(Y),(Z))

//---------------------------------------------------------------------------//
// Print the vector VEC
//---------------------------------------------------------------------------//
  #define DBGVEC(VEC) \
  STREAM<<#VEC<<"\t:\t["; \
  for(szt i=0;i<(VEC).size();++i) { \
    STREAM<<(VEC)[i]<<","; \
  } \
  STREAM<<"]"<<NL;

  #define xdbgvec(VEC) DBGVEC((VEC))

//---------------------------------------------------------------------------//
// Print the matrix VEC2
//---------------------------------------------------------------------------//
  #define DBGVEC2(VEC2) \
  STREAM<<#VEC2; \
  for(szt i=0;i<(VEC2).size();++i) { \
    STREAM<<"\t:\t["; \
    for(szt j=0;j<(VEC2)[i].size();++j) { \
      STREAM<<(VEC2)[i][j]<<","; \
    } \
    STREAM<<"]"<<NL; \
  }

  #define xbdgvec2(VEC2) DBGVEC2((VEC2))

//---------------------------------------------------------------------------//
// Print the array elements from START to END
//---------------------------------------------------------------------------//
  #define DBGARR(ARR,START,END) \
  STREAM<<#ARR<<"\t:\t["; \
  for(szt i=(START);i<=END;++i){ \
    STREAM<<(ARR)[i]<<","; \
  } \
  STREAM<<"]"<<NL;

  #define xdbgarr(ARR,START,END) DBGARR((ARR),(START),(END))
#endif

// If DEBUG is not defined then do not use the debugging features
#ifndef DEBUG
  #define DBG(X)
  #define xdbg(X)
  #define DBG2(X,Y)
  #define xdbg2(X)
  #define DBG3(X,Y,Z)
  #define xdbg3(X,Y,Z)
  #define DBG4(W,X,Y,Z)
  #define xdbg4(W,X,Y,Z)
  #define DBGVEC(VEC)
  #define xdbgvec(VEC)
  #define DBGVEC2(VEC2)
  #define xbdgvec2(VEC2)
  #define DBGARR(ARR,START,END)
  #define xdbgarr(ARR,START,END)
#endif

///////////////////////////////////////////////////////////////////////////////
// Basic datatype definition macros
///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------//
// 1D vector of type TYPE
//---------------------------------------------------------------------------//
#define VEC(TYPE) std::vector< TYPE >
#define xvec(TYPE) std::vector< TYPE >

//---------------------------------------------------------------------------//
// 2D vector( essentially a matrix) of type TYPE
//---------------------------------------------------------------------------//
#define VEC2(TYPE) std::vector<std::vector< TYPE > >
#define xvec2(TYPE) std::vector<std::vector< TYPE > >

//---------------------------------------------------------------------------//
// Tree set of type TYPE
//---------------------------------------------------------------------------//
#define TSET(TYPE) std::set< TYPE >
#define xtset(TYPE) std::set< TYPE >

//---------------------------------------------------------------------------//
// Tree map of type TYPE
//---------------------------------------------------------------------------//
#define TMAP(XTYPE,YTYPE) std::map< XTYPE , YTYPE >
#define xtmap(XTYPE,YTYPE) std::map< XTYPE , YTYPE >

//---------------------------------------------------------------------------//
// Hash set of type TYPE
//---------------------------------------------------------------------------//
#define HSET(TYPE) std::unordered_set< TYPE >
#define xhset(TYPE) std::unordered_set< TYPE >

//---------------------------------------------------------------------------//
// Hash map of type TYPE
//---------------------------------------------------------------------------//
#define HMAP(XTYPE,YTYPE) std::unordered_map< XTYPE , YTYPE >
#define xhmap(XTYPE,YTYPE) std::unordered_map< XTYPE , YTYPE >

//---------------------------------------------------------------------------//
// Pair of type XTYPE,YTYPE
//---------------------------------------------------------------------------//
#define xpair(XTYPE,YTYPE) std::pair< XTYPE, YTYPE >
#define xmkpair std::make_pair
#define xpf first
#define xps second

//---------------------------------------------------------------------------//
// String
//---------------------------------------------------------------------------//
#define xstr std::string

///////////////////////////////////////////////////////////////////////////////
// Commonly used macros for vector and also other containers
///////////////////////////////////////////////////////////////////////////////
#define EMBK emplace_back
#define xembk EMBK
#define PSBK push_back
#define xpsbk PSBK
#define RSRV reserve
#define xrsrv RSRV
#define xsize size()
#define xcapacity capacity()


///////////////////////////////////////////////////////////////////////////////
// Template macros
///////////////////////////////////////////////////////////////////////////////
#define TEM(TYPE) template<typename TYPE >
#define xtem(TYPE) template<typename TYPE >

///////////////////////////////////////////////////////////////////////////////
// Limits
///////////////////////////////////////////////////////////////////////////////
// Absoulte value of N
// Required since C++ has different absolute function for different types.
// And we would like to use a single one and not worry about the type.
// Moreover this is better for templated operations .
#define ABS(N) ( ((N) >= 0 ) ? (N) : -(N) )
#define xabs(N) ABS((N))

// Numeric minimum value for type TYPE
#define ABSMIN(TYPE) std::numeric_limits< TYPE >::min()
#define xabsmin(TYPE) ABSMIN(TYPE)

// Numeric maximum value for type TYPE
#define ABSMAX(TYPE) std::numeric_limits< TYPE >::max()
#define xabsmax(TYPE) ABSMAX(TYPE)

// Machine epsilon
#define EPS(TYPE) std::numeric_limits< TYPE >::epsilon()
#define xeps(TYPE) EPS(TYPE)

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
#define ENDOMP END

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
#define  DO(I,START,END)  for((I)=(START); (I)<=(END); ++(I)) {
#define xdo(I,START,END)  for((I)=(START); (I)<=(END); ++(I)) {

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
#define  RDO(I,START,END) for((I)=(START); (I)>=(END); --(I)) {
#define xrdo(I,START,END) for((I)=(START); (I)>=(END); --(I)) {

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

#define xdox(TYPE,I,START,OP,END,STEP_OP) \
        for(TYPE (I)=(START);(I) OP (END);(STEP_OP)){

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
#define  WHILE(CONDITION) while((CONDITION)) {
#define xwhile(CONDITION) while((CONDITION)) {

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
#define  IF(CONDITION) if((CONDITION)) {
#define xif(CONDITION) if((CONDITION)) {
#define  ELSE } else {
#define xelse } else {
#define  ELSEIF(CONDITION) } else if((CONDITION)) {
#define xelseif(CONDITION) } else if((CONDITION)) {

///////////////////////////////////////////////////////////////////////////////
// OpenMP support
// WARNING : TESTING AND UNSTABLE FOR NOW ...
///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------//
// Multi-line OpenMP command : requires END to brace in the control block
//---------------------------------------------------------------------------//
// USE :
// > OMP("omp parallel for")
// >     printf("Hello World\n");
// > END
//
// RESULT : This should print on a machine with 4 theads as
// Hello World
// Hello World
// Hello World
// Hello World
//---------------------------------------------------------------------------//
#define OMP(PRG)  _Pragma(#PRG) {

//---------------------------------------------------------------------------//
// Multiline-line general OpenMP command.
//---------------------------------------------------------------------------//
// USE :
// > OMPX("omp simd", DO(i,0,n-1))
// >   c[i] = a[i]+b[i];
// > ENDDO
//---------------------------------------------------------------------------//
// NECESSITY :
// This way there is no conflict between scicpp and OpenMP.
// Due to scicpp and OpenMP both using pre-processor directives, the
// OpenMP demands that there be the required C code after some OpenMP command.
// OMPX allows proper expansion of scicpp along with OpenMP.
//
// For ex.
// > #pragma omp simd
// > for(int i=0;i<n;i++)
// >   c[i] = a[i]+b[i];
//
// is valid.
//
// However,
// > #pragma omp simd
// > DO(i,0,n-1)
// >   c[i] = a[i]+b[i];
// > ENDDO
//
// is not valid.
//---------------------------------------------------------------------------//
#define OMPX(PRG,CMD) \
  _Pragma(#PRG) \
  CMD

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
#define xsq(CMD) (CMD)*(CMD)

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
#define xcu(CMD) (CMD)*(CMD)*(CMD)

//---------------------------------------------------------------------------//
// Extracts the  sign of a number
//---------------------------------------------------------------------------//
// xsgn(X) := (1 if X > 0) or (0 if x==0) or (-1 if x < 0)
//---------------------------------------------------------------------------//
// NOTE : This is best used for real numbers.
// However,
// Since the implementation is templated it can support non-real numbers too.
//---------------------------------------------------------------------------//
// NOTE : We will receive -Wtype-limits for the <0 test in GCC.
// Thus we use overloads to take care of that warning.
//---------------------------------------------------------------------------//
// USE :
// >> s32 x = -100; u32 y = 100; s32 z = 0;
// >> cout<<xsgn(x)<<endl;
// >> cout<<xsgn(y)<<endl;
// >> cout<<xsgn(z)<<endl;
//
// RESULT : Should print,
// -1
// 1
// 0
//---------------------------------------------------------------------------//
// If X is of a signed type
// Called by xsgn(TYPE X)
xtem(TYPE) inline constexpr
int xsgn(TYPE X, std::true_type is_signed)
{
  return (X > TYPE(0)) - (X < TYPE(0));
}

// If X is of an unsigned type
// Called by xsgn(TYPE X)
xtem(TYPE) inline constexpr
int xsgn(TYPE X, std::false_type is_signed)
{
  return (X > TYPE(0));
}

// Return the sign of a number
// Calls xsgn(TYPE X,std::true_type) if x is of a signed type
// Calls xsgn(TYPE X,std::false_type) if x is of an unsigned type
xtem(TYPE) inline constexpr
int xsgn(TYPE X)
{
  return xsgn(X, std::is_signed<TYPE>());
}

//---------------------------------------------------------------------------//
// Determinant of a 2*2 matrix
// A  B
// C  D
//---------------------------------------------------------------------------//
#define DET2X2(A,B,C,D) ((A)*(D) - (B)*(C))
#define xdet2x2(A,B,C,D) DET2X2((A),(B),(C),(D))

//---------------------------------------------------------------------------//
// Determinant of a 3*3 matrix
// A B C
// D E F
// I J K
//---------------------------------------------------------------------------//
#define DET3X3(A,B,C,D,E,F,I,J,K) \
        ( ((A)*DET2X2((E),(F),(J),(K))) - \
          ((B)*DET2X2((D),(F),(I),(K))) + \
          ((C)*DET2X2((D),(E),(I),(J)))   \
        )
#define xdet3x3(A,B,C,D,E,F,I,J,K) \
        DET3X3((A),(B),(C),(D),(E),(F),(I),(J),(K))

//---------------------------------------------------------------------------//
// Determinant of a 4*4 matrix
// A B C D
// E F G H
// I J K L
// M N O P
//---------------------------------------------------------------------------//
#define DET4X4(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P) \
        ( ((A)*(DET3X3((F),(G),(H),(J),(K),(L),(N),(O),(P)))) - \
          ((B)*(DET3X3((E),(G),(H),(I),(K),(L),(M),(O),(P)))) + \
          ((C)*(DET3X3((E),(F),(H),(I),(J),(L),(M),(N),(P)))) - \
          ((D)*(DET3X3((E),(F),(G),(I),(J),(K),(M),(N),(O))))   \
        )
#define xdet4x4(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P) \
        DET4X4((A),(B),(C),(D),(E),(F),(G),(H),(I),(J),(K),(L),(M),(N),(O),(P))

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
///////////////////////////////////////////////////////////////////////////////
// Decorations
///////////////////////////////////////////////////////////////////////////////
// Horizontal ruler
// NOTE : Semicolon is required after xhr and xhrd.
#define DEC_STREAM std::cerr

#define xhr DEC_STREAM<< \
"/////////////////////////////////"<< \
"/////////////////////////////////"<<nl \

#define xhrd DEC_STREAM<< \
"................................."<< \
"................................."<<nl \



#endif
