/*
 * LQR_Model_1_input.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Model_1_input".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Nov 21 16:01:36 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LQR_Model_1_input_h_
#define RTW_HEADER_LQR_Model_1_input_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef LQR_Model_1_input_COMMON_INCLUDES_
#define LQR_Model_1_input_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* LQR_Model_1_input_COMMON_INCLUDES_ */

#include "LQR_Model_1_input_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T x[2];                         /* '<Root>/Discrete-Time Integrator' */
  real_T y;                            /* '<Root>/C1' */
  real_T Ax[2];                        /* '<Root>/A1' */
  real_T Kx;                           /* '<Root>/K1' */
  real_T u;                            /* '<Root>/Add3' */
  real_T Bu[2];                        /* '<Root>/B1' */
  real_T x_dot[2];                     /* '<Root>/Add2' */
} B_LQR_Model_1_input_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[2];/* '<Root>/Discrete-Time Integrator' */
} DW_LQR_Model_1_input_T;

/* Parameters (default storage) */
struct P_LQR_Model_1_input_T_ {
  real_T A[4];                         /* Variable: A
                                        * Referenced by: '<Root>/A1'
                                        */
  real_T B[2];                         /* Variable: B
                                        * Referenced by: '<Root>/B1'
                                        */
  real_T C[2];                         /* Variable: C
                                        * Referenced by: '<Root>/C1'
                                        */
  real_T K[2];                         /* Variable: K
                                        * Referenced by: '<Root>/K1'
                                        */
  real_T x0[2];                        /* Variable: x0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T Inputinitialcondition_Value;  /* Expression: 0
                                        * Referenced by: '<Root>/Input initial condition'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LQR_Model_1_input_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_LQR_Model_1_input_T LQR_Model_1_input_P;

/* Block signals (default storage) */
extern B_LQR_Model_1_input_T LQR_Model_1_input_B;

/* Block states (default storage) */
extern DW_LQR_Model_1_input_T LQR_Model_1_input_DW;

/* Model entry point functions */
extern void LQR_Model_1_input_initialize(void);
extern void LQR_Model_1_input_step(void);
extern void LQR_Model_1_input_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LQR_Model_1_input_T *const LQR_Model_1_input_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/F2' : Unused code path elimination
 * Block '<Root>/M2' : Unused code path elimination
 * Block '<Root>/Sum' : Unused code path elimination
 * Block '<S1>/Clock' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S1>/Output' : Unused code path elimination
 * Block '<S1>/Product' : Unused code path elimination
 * Block '<S1>/Step' : Unused code path elimination
 * Block '<S1>/Sum' : Unused code path elimination
 * Block '<Root>/lc_max' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LQR_Model_1_input'
 * '<S1>'   : 'LQR_Model_1_input/lc'
 */
#endif                                 /* RTW_HEADER_LQR_Model_1_input_h_ */
