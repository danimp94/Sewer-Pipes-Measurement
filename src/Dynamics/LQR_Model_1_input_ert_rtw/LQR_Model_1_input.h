//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LQR_Model_1_input.h
//
// Code generated for Simulink model 'LQR_Model_1_input'.
//
// Model version                  : 1.27
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Nov 22 11:49:12 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives:
//    1. RAM efficiency
//    2. Execution efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_LQR_Model_1_input_h_
#define RTW_HEADER_LQR_Model_1_input_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Model Code Variants

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Class declaration for model LQR_Model_1_input
class LQR_Model_1_inputModelClass {
  // public data and function members
 public:
  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      SimTimeStep simTimeStep;
      time_T *t;
      time_T tArray[2];
    } Timing;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  LQR_Model_1_inputModelClass();

  // Destructor
  ~LQR_Model_1_inputModelClass();

  // Real-Time Model get method
  LQR_Model_1_inputModelClass::RT_MODEL * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL rtM;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/A1' : Unused code path elimination
//  Block '<Root>/Add2' : Unused code path elimination
//  Block '<Root>/Add3' : Unused code path elimination
//  Block '<Root>/B1' : Unused code path elimination
//  Block '<Root>/C1' : Unused code path elimination
//  Block '<Root>/Discrete-Time Integrator' : Unused code path elimination
//  Block '<Root>/F2' : Unused code path elimination
//  Block '<Root>/Input initial condition' : Unused code path elimination
//  Block '<Root>/K1' : Unused code path elimination
//  Block '<Root>/M2' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Sum' : Unused code path elimination
//  Block '<S1>/Clock' : Unused code path elimination
//  Block '<S1>/Constant' : Unused code path elimination
//  Block '<S1>/Constant1' : Unused code path elimination
//  Block '<S1>/Output' : Unused code path elimination
//  Block '<S1>/Product' : Unused code path elimination
//  Block '<S1>/Step' : Unused code path elimination
//  Block '<S1>/Sum' : Unused code path elimination
//  Block '<Root>/lc_max' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'LQR_Model_1_input'
//  '<S1>'   : 'LQR_Model_1_input/lc'

#endif                                 // RTW_HEADER_LQR_Model_1_input_h_

//
// File trailer for generated code.
//
// [EOF]
//
