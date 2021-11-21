/*
 * LQR_Model_1_input.c
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

#include "LQR_Model_1_input.h"
#include "LQR_Model_1_input_private.h"

/* Block signals (default storage) */
B_LQR_Model_1_input_T LQR_Model_1_input_B;

/* Block states (default storage) */
DW_LQR_Model_1_input_T LQR_Model_1_input_DW;

/* Real-time model */
static RT_MODEL_LQR_Model_1_input_T LQR_Model_1_input_M_;
RT_MODEL_LQR_Model_1_input_T *const LQR_Model_1_input_M = &LQR_Model_1_input_M_;

/* Model step function */
void LQR_Model_1_input_step(void)
{
  real_T tmp;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  LQR_Model_1_input_B.x[0] = LQR_Model_1_input_DW.DiscreteTimeIntegrator_DSTATE
    [0];

  /* Gain: '<Root>/C1' */
  tmp = LQR_Model_1_input_P.C[0] * LQR_Model_1_input_B.x[0];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  LQR_Model_1_input_B.x[1] = LQR_Model_1_input_DW.DiscreteTimeIntegrator_DSTATE
    [1];

  /* Gain: '<Root>/C1' */
  tmp += LQR_Model_1_input_P.C[1] * LQR_Model_1_input_B.x[1];

  /* Gain: '<Root>/C1' */
  LQR_Model_1_input_B.y = tmp;

  /* Gain: '<Root>/A1' */
  LQR_Model_1_input_B.Ax[0] = 0.0;
  LQR_Model_1_input_B.Ax[0] += LQR_Model_1_input_P.A[0] * LQR_Model_1_input_B.x
    [0];
  LQR_Model_1_input_B.Ax[0] += LQR_Model_1_input_B.x[1] * LQR_Model_1_input_P.A
    [2];

  /* Gain: '<Root>/K1' */
  tmp = LQR_Model_1_input_P.K[0] * LQR_Model_1_input_B.x[0];

  /* Gain: '<Root>/A1' */
  LQR_Model_1_input_B.Ax[1] = 0.0;
  LQR_Model_1_input_B.Ax[1] += LQR_Model_1_input_B.x[0] * LQR_Model_1_input_P.A
    [1];
  LQR_Model_1_input_B.Ax[1] += LQR_Model_1_input_B.x[1] * LQR_Model_1_input_P.A
    [3];

  /* Gain: '<Root>/K1' */
  tmp += LQR_Model_1_input_P.K[1] * LQR_Model_1_input_B.x[1];

  /* Gain: '<Root>/K1' */
  LQR_Model_1_input_B.Kx = tmp;

  /* Sum: '<Root>/Add3' incorporates:
   *  Constant: '<Root>/Input initial condition'
   */
  LQR_Model_1_input_B.u = LQR_Model_1_input_P.Inputinitialcondition_Value -
    LQR_Model_1_input_B.Kx;

  /* Gain: '<Root>/B1' */
  LQR_Model_1_input_B.Bu[0] = LQR_Model_1_input_P.B[0] * LQR_Model_1_input_B.u;

  /* Sum: '<Root>/Add2' */
  LQR_Model_1_input_B.x_dot[0] = LQR_Model_1_input_B.Bu[0] +
    LQR_Model_1_input_B.Ax[0];

  /* Gain: '<Root>/B1' */
  LQR_Model_1_input_B.Bu[1] = LQR_Model_1_input_P.B[1] * LQR_Model_1_input_B.u;

  /* Sum: '<Root>/Add2' */
  LQR_Model_1_input_B.x_dot[1] = LQR_Model_1_input_B.Bu[1] +
    LQR_Model_1_input_B.Ax[1];

  /* Matfile logging */
  rt_UpdateTXYLogVars(LQR_Model_1_input_M->rtwLogInfo,
                      (LQR_Model_1_input_M->Timing.t));

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  LQR_Model_1_input_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    LQR_Model_1_input_P.DiscreteTimeIntegrator_gainval *
    LQR_Model_1_input_B.x_dot[0];
  LQR_Model_1_input_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    LQR_Model_1_input_P.DiscreteTimeIntegrator_gainval *
    LQR_Model_1_input_B.x_dot[1];

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(LQR_Model_1_input_M)!=-1) &&
        !((rtmGetTFinal(LQR_Model_1_input_M)-LQR_Model_1_input_M->Timing.t[0]) >
          LQR_Model_1_input_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(LQR_Model_1_input_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LQR_Model_1_input_M->Timing.clockTick0)) {
    ++LQR_Model_1_input_M->Timing.clockTickH0;
  }

  LQR_Model_1_input_M->Timing.t[0] = LQR_Model_1_input_M->Timing.clockTick0 *
    LQR_Model_1_input_M->Timing.stepSize0 +
    LQR_Model_1_input_M->Timing.clockTickH0 *
    LQR_Model_1_input_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    LQR_Model_1_input_M->Timing.clockTick1++;
    if (!LQR_Model_1_input_M->Timing.clockTick1) {
      LQR_Model_1_input_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void LQR_Model_1_input_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LQR_Model_1_input_M, 0,
                sizeof(RT_MODEL_LQR_Model_1_input_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LQR_Model_1_input_M->solverInfo,
                          &LQR_Model_1_input_M->Timing.simTimeStep);
    rtsiSetTPtr(&LQR_Model_1_input_M->solverInfo, &rtmGetTPtr
                (LQR_Model_1_input_M));
    rtsiSetStepSizePtr(&LQR_Model_1_input_M->solverInfo,
                       &LQR_Model_1_input_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&LQR_Model_1_input_M->solverInfo, (&rtmGetErrorStatus
      (LQR_Model_1_input_M)));
    rtsiSetRTModelPtr(&LQR_Model_1_input_M->solverInfo, LQR_Model_1_input_M);
  }

  rtsiSetSimTimeStep(&LQR_Model_1_input_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&LQR_Model_1_input_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(LQR_Model_1_input_M, &LQR_Model_1_input_M->Timing.tArray[0]);
  rtmSetTFinal(LQR_Model_1_input_M, 35.0);
  LQR_Model_1_input_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    LQR_Model_1_input_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(LQR_Model_1_input_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(LQR_Model_1_input_M->rtwLogInfo, (NULL));
    rtliSetLogT(LQR_Model_1_input_M->rtwLogInfo, "tout");
    rtliSetLogX(LQR_Model_1_input_M->rtwLogInfo, "");
    rtliSetLogXFinal(LQR_Model_1_input_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(LQR_Model_1_input_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(LQR_Model_1_input_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(LQR_Model_1_input_M->rtwLogInfo, 0);
    rtliSetLogDecimation(LQR_Model_1_input_M->rtwLogInfo, 1);
    rtliSetLogY(LQR_Model_1_input_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(LQR_Model_1_input_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(LQR_Model_1_input_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &LQR_Model_1_input_B), 0,
                sizeof(B_LQR_Model_1_input_T));

  /* states (dwork) */
  (void) memset((void *)&LQR_Model_1_input_DW, 0,
                sizeof(DW_LQR_Model_1_input_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(LQR_Model_1_input_M->rtwLogInfo, 0.0,
    rtmGetTFinal(LQR_Model_1_input_M), LQR_Model_1_input_M->Timing.stepSize0,
    (&rtmGetErrorStatus(LQR_Model_1_input_M)));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  LQR_Model_1_input_DW.DiscreteTimeIntegrator_DSTATE[0] =
    LQR_Model_1_input_P.x0[0];
  LQR_Model_1_input_DW.DiscreteTimeIntegrator_DSTATE[1] =
    LQR_Model_1_input_P.x0[1];
}

/* Model terminate function */
void LQR_Model_1_input_terminate(void)
{
  /* (no terminate code required) */
}
