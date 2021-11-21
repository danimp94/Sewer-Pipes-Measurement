/*
 * LQR_Model_1_input_data.c
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

/* Block parameters (default storage) */
P_LQR_Model_1_input_T LQR_Model_1_input_P = {
  /* Variable: A
   * Referenced by: '<Root>/A1'
   */
  { 0.0, 0.0, 1.0, -3.1363693388533433 },

  /* Variable: B
   * Referenced by: '<Root>/B1'
   */
  { 0.0, 1.0 },

  /* Variable: C
   * Referenced by: '<Root>/C1'
   */
  { 1.0, 1.0 },

  /* Variable: K
   * Referenced by: '<Root>/K1'
   */
  { 0.99999999999999822, 0.44648045282078663 },

  /* Variable: x0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  { 0.39269908169872414, 0.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Input initial condition'
   */
  0.0
};
