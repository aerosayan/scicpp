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
/// @file    main.cpp
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

// NOTE : For debugging macros define DEBUG before including scicpp.hpp
#define DEBUG
#include "scicpp.hpp"
#include <fstream>

using namespace std;

// prints a horizontal line
void hruler();

// Solves the 1D nonliner convection equation using Finite Difference Method
void run_nonlinear_convection_test();

// Runs necessary unit tests
void run_unit_tests();

int main()
{
  // Run non-linear convection test to show the use of scicpp for science
  run_nonlinear_convection_test();

  // Run unit tests to show the internal operation of scicpp
  // run_unit_tests(); 

  return 0;
}

// Solves the 1D nonliner convection equation using Finite Difference Method
// 1D nonlinear convection equation is :
// 
//                     d(u)/dt + u*d(u)/dx = 0
//
// where,
// u is the dependent variable.
// d(u)/dt is the partial derivative of u w.r.t time(t)
// d(u)/dx is the partial derivative of u w.r.t space(x)
// 
// We shall be using FTBS( Forward in Time Backward in Space) scheme to solve.
void run_nonlinear_convection_test()
{
  // Loop iterators
  // NOTE: We define the type first 
  u32 i,t;
  // No. of spatial nodes
  u32 nx = 801;
  // No. of temporal iterations
  u32 nt = 3000;
  // Minimum and maximum space domain which will be discretized
  f64 min_x = 0.0; f64 max_x = 2.0;
  // Spatial discretization 
  f64 dx = (max_x-min_x)/(nx-1);
  // Temporal discretization
  f64 dt = 0.00015;

  // Spatial mesh
  VEC(f64) x(nx+1);
  // NOTE : The type for i is set earlier
  DO(i,1,nx)
    x[i] = min_x + (dx*(i-1));
  ENDDO

  // Dependent variable to simulate and solve
  // un is u at time n
  // un1 is u at time n+1
  VEC(f64) un(nx+1),un1(nx+1);

  // Set initial conditions
  DO(i,1,nx)
    un1[i] = 1.0;
  ENDDO
  // We shall be using a  hat function for intial condition
  DO(i,30,300)
    un1[i] = 2.0;
  ENDDO

  // Write input to file input.dat
  ofstream input_file;
  input_file.open("input.dat",ios::out);

  IF(input_file.is_open())
    DO(i,1,nx)
      input_file<<x[i]<<"\t"<<un1[i]<<"\n";
    ENDDO
  ELSE
    cout<<"ERROR :: INPUT FILE NOT OPENED CORRECTLY"<<endl;
  ENDIF

  f64 dtdx = dt/dx;
  // Start temporal iterations
  DO(t,1,nt)
    un = un1;
    DO(i,2,nx)
      un1[i] = un[i] - un[i]*dtdx*(un[i]-un[i-1]);
    ENDDO
  ENDDO

  // Write output to file output.dat
  ofstream output_file;
  output_file.open("output.dat",ios::out);

  IF(output_file.is_open())
    DO(i,1,nx)
      output_file<<x[i]<<"\t"<<un1[i]<<"\n";
    ENDDO
  ELSE
    cout<<"ERROR :: OUTPUT FILE NOT OPENED CORRECTLY"<<endl;
  ENDIF

  // Close all open files
  input_file.close();
  output_file.close();
}

// Runs necessary unit tests
void run_unit_tests()
{
  // Loop iterators
  // NOTE: We define the type first 
  u32 i;

  hruler();
  cout<<"TST :: Testing DBG,DB2,DBG3"<<endl;
  s32 varx = 1;
  s32 vary = 2;
  s32 varz = 3;
  DBG(varx);
  DBG2(varx,vary);
  DBG3(varx,vary,varz);

  hruler();
  cout<<"TST :: Testing VEC,DBGVEC "<<endl;
  VEC(s32) vecx = {0,1,2,3,4,5,6,7,8,9,10};
  DBGVEC(vecx);

  hruler();
  cout<<"TST :: Testing VEC2,DBGMAT "<<endl;
  VEC2(s32) matx = {{0,0,0,0,0,0},{0,1,2,3,4,5},{0,6,7,8,9,10}};
  DBGVEC2(matx);

  hruler();
  cout<<"TST :: Testing DO in forward direction"<<endl;
  cout<<"i\t:\t";
  DO(i,1,10)
    cout<<i<<",";
  ENDDO
  cout<<endl;

  hruler();
  cout<<"TST :: Testing RDO in reverse direction"<<endl;
  cout<<"i\t:\t";
  RDO(i,10,1)
    cout<<i<<",";
  ENDDO
  cout<<endl;

  hruler();
  cout<<"TST :: Testing DOX in forward direction"<<endl;
  cout<<"j\t:\t";
  DOX(u32,j,1,<=,10,++j)
    cout<<j<<",";
  ENDDO
  cout<<endl;

  hruler();
  cout<<"TST :: Testing DOX in forward direction with step=2"<<endl;
  cout<<"j\t:\t";
  DOX(u32,j,2,<=,20,j+=2)
    cout<<j<<",";
  ENDDO
  cout<<endl;

  hruler();
  cout<<"TST :: Testing DOX in reverse direction"<<endl;
  cout<<"j\t:\t";
  DOX(u32,j,10,>=,1,--j)
    cout<<j<<",";
  ENDDO
  cout<<endl;
 
  hruler();
  cout<<"TST :: Testing DOX in reverse direction with step=2"<<endl;
  cout<<"j\t:\t";
  DOX(u32,j,20,>=,2,j-=2)
    cout<<j<<",";
  ENDDO
  cout<<endl;

  hruler();
  cout<<"TST :: Testing WHILE"<<endl; 
  i=10;
  cout<<"i\t:\t";
  WHILE(i--)
    cout<<i<<",";
  ENDWHILE
  cout<<endl;
  
  hruler();
  cout<<"TST :: Testing IF,ELSE,ELSEIF..."<<endl;
  IF(varx == 1)
    cout<<"    :: IF      :: varx == 1"<<endl;
  ELSE
    cout<<"    :: ELSE    :: varx != 1"<<endl;
  ENDIF

  IF(vary == 1)
    cout<<"    :: IF      :: vary == 1"<<endl;
  ELSEIF(vary==2)
    cout<<"    :: ELSEIF  :: vary == 2"<<endl;
  ELSE
    cout<<"    :: ELSE    :: vary != 1 and 2"<<endl;
  ENDIF

  IF(varz == 1)
    cout<<"    :: IF      :: varz == 1"<<endl;
  ELSEIF(varz == 2)
    cout<<"    :: ELSEIF  :: varz == 2"<<endl;
  ELSE
    cout<<"    :: ELSE    :: varz != 1 and 2"<<endl;
  ENDIF

}

// Prints a horizontal line
void hruler()
{
cout<<
"-----------------------------------------------------------------------------"
<<endl;
}
