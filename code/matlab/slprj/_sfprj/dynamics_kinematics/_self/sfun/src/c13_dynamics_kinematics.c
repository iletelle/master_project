/* Include files */

#include "blascompat32.h"
#include "dynamics_kinematics_sfun.h"
#include "c13_dynamics_kinematics.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dynamics_kinematics_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c13_debug_family_names[5] = { "nargin", "nargout", "ee_pos",
  "ee_ang", "ref" };

/* Function Declarations */
static void initialize_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static void initialize_params_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static void enable_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static void disable_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static void set_sim_state_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance, const mxArray *c13_st);
static void finalize_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static void sf_c13_dynamics_kinematics(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance);
static void initSimStructsc13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_ref, const char_T *c13_identifier);
static real_T c13_b_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_c_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_d_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_dynamics_kinematics, const
  char_T *c13_identifier);
static uint8_T c13_e_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_is_active_c13_dynamics_kinematics = 0U;
}

static void initialize_params_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static void enable_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  uint8_T c13_b_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T *c13_ref;
  c13_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2), FALSE);
  c13_hoistedGlobal = *c13_ref;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = chartInstance->c13_is_active_c13_dynamics_kinematics;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  real_T *c13_ref;
  c13_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  *c13_ref = c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u,
    0)), "ref");
  chartInstance->c13_is_active_c13_dynamics_kinematics = c13_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
     "is_active_c13_dynamics_kinematics");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_dynamics_kinematics(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static void sf_c13_dynamics_kinematics(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance)
{
  int32_T c13_i0;
  int32_T c13_i1;
  int32_T c13_i2;
  real_T c13_ee_pos[3];
  int32_T c13_i3;
  real_T c13_ee_ang[3];
  uint32_T c13_debug_family_var_map[5];
  real_T c13_nargin = 2.0;
  real_T c13_nargout = 1.0;
  real_T c13_ref;
  real_T c13_b;
  real_T *c13_b_ref;
  real_T (*c13_b_ee_ang)[3];
  real_T (*c13_b_ee_pos)[3];
  c13_b_ee_ang = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_ee_pos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c13_b_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c13_b_ref, 0U);
  for (c13_i0 = 0; c13_i0 < 3; c13_i0++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_ee_pos)[c13_i0], 1U);
  }

  for (c13_i1 = 0; c13_i1 < 3; c13_i1++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_ee_ang)[c13_i1], 2U);
  }

  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    c13_ee_pos[c13_i2] = (*c13_b_ee_pos)[c13_i2];
  }

  for (c13_i3 = 0; c13_i3 < 3; c13_i3++) {
    c13_ee_ang[c13_i3] = (*c13_b_ee_ang)[c13_i3];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c13_debug_family_names,
    c13_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargin, 0U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargout, 1U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c13_ee_pos, 2U, c13_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c13_ee_ang, 3U, c13_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c13_ref, 4U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 3);
  c13_ref = c13_ee_pos[1];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c13_ee_pos[0] >= 1.5)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
    c13_b = c13_ee_pos[0] - 1.5;
    c13_ref = 0.4 * c13_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c13_b_ref = c13_ref;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  sf_debug_check_for_state_inconsistency(_dynamics_kinematicsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc13_dynamics_kinematics
  (SFc13_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc13_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_ref, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_ref), &c13_thisId);
  sf_mex_destroy(&c13_ref);
  return c13_y;
}

static real_T c13_b_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_ref;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc13_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c13_ref = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_ref), &c13_thisId);
  sf_mex_destroy(&c13_ref);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i4;
  real_T c13_b_inData[3];
  int32_T c13_i5;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc13_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    c13_b_inData[c13_i4] = (*(real_T (*)[3])c13_inData)[c13_i4];
  }

  for (c13_i5 = 0; c13_i5 < 3; c13_i5++) {
    c13_u[c13_i5] = c13_b_inData[c13_i5];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

const mxArray *sf_c13_dynamics_kinematics_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo;
  c13_ResolvedFunctionInfo c13_info[1];
  c13_ResolvedFunctionInfo (*c13_b_info)[1];
  const mxArray *c13_m0 = NULL;
  int32_T c13_i6;
  c13_ResolvedFunctionInfo *c13_r0;
  c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  c13_b_info = (c13_ResolvedFunctionInfo (*)[1])c13_info;
  (*c13_b_info)[0].context = "";
  (*c13_b_info)[0].name = "mtimes";
  (*c13_b_info)[0].dominantType = "double";
  (*c13_b_info)[0].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c13_b_info)[0].fileTimeLo = 1289519692U;
  (*c13_b_info)[0].fileTimeHi = 0U;
  (*c13_b_info)[0].mFileTimeLo = 0U;
  (*c13_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c13_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c13_i6 = 0; c13_i6 < 1; c13_i6++) {
    c13_r0 = &c13_info[c13_i6];
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->context)), "context", "nameCaptureInfo",
                    c13_i6);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->name)), "name", "nameCaptureInfo", c13_i6);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      c13_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c13_i6);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->resolved)), "resolved",
                    "nameCaptureInfo", c13_i6);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c13_i6);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c13_i6);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c13_i6);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c13_i6);
  }

  sf_mex_assign(&c13_nameCaptureInfo, c13_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc13_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_c_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i7;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i7, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i7;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc13_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_d_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_dynamics_kinematics, const
  char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_dynamics_kinematics), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_dynamics_kinematics);
  return c13_y;
}

static uint8_T c13_e_emlrt_marshallIn(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_dynamics_kinematicsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c13_dynamics_kinematics_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4170273463U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2533514873U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(730974324U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3747933048U);
}

mxArray *sf_c13_dynamics_kinematics_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("X4RdEazgMKVQUdTSAq5v9");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c13_dynamics_kinematics(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"ref\",},{M[8],M[0],T\"is_active_c13_dynamics_kinematics\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_dynamics_kinematics_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_dynamics_kinematicsInstanceStruct *chartInstance;
    chartInstance = (SFc13_dynamics_kinematicsInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_dynamics_kinematicsMachineNumber_,
           13,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_dynamics_kinematicsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_dynamics_kinematicsMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_dynamics_kinematicsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"ref");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ee_pos");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ee_ang");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,143);
        _SFD_CV_INIT_EML_IF(0,1,0,73,90,-1,132);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c13_ref;
          real_T (*c13_ee_pos)[3];
          real_T (*c13_ee_ang)[3];
          c13_ee_ang = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c13_ee_pos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c13_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_ref);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_ee_pos);
          _SFD_SET_DATA_VALUE_PTR(2U, *c13_ee_ang);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_dynamics_kinematicsMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "wG2wBfyzm2ItrilUspKim";
}

static void sf_opaque_initialize_c13_dynamics_kinematics(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_dynamics_kinematics
    ((SFc13_dynamics_kinematicsInstanceStruct*) chartInstanceVar);
  initialize_c13_dynamics_kinematics((SFc13_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_dynamics_kinematics(void *chartInstanceVar)
{
  enable_c13_dynamics_kinematics((SFc13_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_dynamics_kinematics(void *chartInstanceVar)
{
  disable_c13_dynamics_kinematics((SFc13_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_dynamics_kinematics(void *chartInstanceVar)
{
  sf_c13_dynamics_kinematics((SFc13_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_dynamics_kinematics
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_dynamics_kinematics
    ((SFc13_dynamics_kinematicsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_dynamics_kinematics();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c13_dynamics_kinematics(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_dynamics_kinematics();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_dynamics_kinematics((SFc13_dynamics_kinematicsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_dynamics_kinematics(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c13_dynamics_kinematics(S);
}

static void sf_opaque_set_sim_state_c13_dynamics_kinematics(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_dynamics_kinematics(S, st);
}

static void sf_opaque_terminate_c13_dynamics_kinematics(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_dynamics_kinematicsInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c13_dynamics_kinematics((SFc13_dynamics_kinematicsInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_dynamics_kinematics_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_dynamics_kinematics((SFc13_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_dynamics_kinematics(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_dynamics_kinematics
      ((SFc13_dynamics_kinematicsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_dynamics_kinematics(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dynamics_kinematics_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3532537933U));
  ssSetChecksum1(S,(774437651U));
  ssSetChecksum2(S,(663310423U));
  ssSetChecksum3(S,(3516166858U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c13_dynamics_kinematics(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_dynamics_kinematics(SimStruct *S)
{
  SFc13_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc13_dynamics_kinematicsInstanceStruct *)malloc(sizeof
    (SFc13_dynamics_kinematicsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_dynamics_kinematicsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_dynamics_kinematics;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_dynamics_kinematics;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_dynamics_kinematics;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c13_dynamics_kinematics;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_dynamics_kinematics;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_dynamics_kinematics;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_dynamics_kinematics;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_dynamics_kinematics;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_dynamics_kinematics;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_dynamics_kinematics;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_dynamics_kinematics;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c13_dynamics_kinematics_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_dynamics_kinematics(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_dynamics_kinematics(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_dynamics_kinematics(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_dynamics_kinematics_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
