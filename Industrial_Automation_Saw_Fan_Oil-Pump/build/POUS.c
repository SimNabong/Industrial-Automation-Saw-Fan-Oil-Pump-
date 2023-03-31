void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void INDUSTRIAL_AUTOMATION_PRACTICE_SAW_FAN_OIL_PUMP_init__(INDUSTRIAL_AUTOMATION_PRACTICE_SAW_FAN_OIL_PUMP *data__, BOOL retain) {
  __INIT_VAR(data__->SAW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OIL_PUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START_BUTTON,1,retain)
  SR_init__(&data__->SR0,retain);
  __INIT_VAR(data__->SAW_RUN_20S,__BOOL_LITERAL(FALSE),retain)
  SR_init__(&data__->SR1,retain);
  __INIT_VAR(data__->SAW_OFF,0,retain)
  SR_init__(&data__->SR2,retain);
  __INIT_VAR(data__->FAN_RESET_BUTTON,0,retain)
  __INIT_VAR(data__->SAW_RUN_20S_RESET,0,retain)
  R_TRIG_init__(&data__->R_TRIG0,retain);
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  SR_init__(&data__->SR3,retain);
  __INIT_VAR(data__->_TMP_NOT19_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT20_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND6_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND23_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND22_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR5_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void INDUSTRIAL_AUTOMATION_PRACTICE_SAW_FAN_OIL_PUMP_body__(INDUSTRIAL_AUTOMATION_PRACTICE_SAW_FAN_OIL_PUMP *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->START_BUTTON,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->R_TRIG0.Q,));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->SAW_OFF,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,SAW,,__GET_VAR(data__->SR0.Q1,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->SAW,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->SR3.,S1,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->SR3.,R,,__GET_VAR(data__->SAW_RUN_20S_RESET,));
  SR_body__(&data__->SR3);
  __SET_VAR(data__->,SAW_RUN_20S,,__GET_VAR(data__->SR3.Q1,));
  __SET_VAR(data__->,_TMP_NOT19_OUT,,!(__GET_VAR(data__->SAW,)));
  __SET_VAR(data__->,_TMP_NOT20_OUT,,!(__GET_VAR(data__->SAW_RUN_20S,)));
  __SET_VAR(data__->,_TMP_AND6_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT19_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT20_OUT,)));
  __SET_VAR(data__->,_TMP_AND23_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT19_OUT,),
    (BOOL)__GET_VAR(data__->SAW_RUN_20S,)));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->_TMP_AND23_OUT,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,_TMP_OR7_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND6_OUT,),
    (BOOL)__GET_VAR(data__->TON1.Q,)));
  __SET_VAR(data__->SR1.,S1,,__GET_VAR(data__->R_TRIG0.Q,));
  __SET_VAR(data__->SR1.,R,,__GET_VAR(data__->_TMP_OR7_OUT,));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->,OIL_PUMP,,__GET_VAR(data__->SR1.Q1,));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->_TMP_AND6_OUT,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,_TMP_AND22_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND23_OUT,),
    (BOOL)__GET_VAR(data__->FAN_RESET_BUTTON,)));
  __SET_VAR(data__->,_TMP_OR5_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TON2.Q,),
    (BOOL)__GET_VAR(data__->_TMP_AND22_OUT,)));
  __SET_VAR(data__->SR2.,S1,,__GET_VAR(data__->R_TRIG0.Q,));
  __SET_VAR(data__->SR2.,R,,__GET_VAR(data__->_TMP_OR5_OUT,));
  SR_body__(&data__->SR2);
  __SET_VAR(data__->,FAN,,__GET_VAR(data__->SR2.Q1,));

  goto __end;

__end:
  return;
} // INDUSTRIAL_AUTOMATION_PRACTICE_SAW_FAN_OIL_PUMP_body__() 





