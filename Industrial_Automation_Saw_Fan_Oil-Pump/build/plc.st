TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM Industrial_Automation_practice_Saw_Fan_Oil_pump
  VAR_IN_OUT
    Saw : BOOL;
  END_VAR
  VAR_OUTPUT
    Fan : BOOL;
    Oil_Pump : BOOL;
  END_VAR
  VAR_INPUT
    Start_Button : BOOL := 1;
  END_VAR
  VAR
    SR0 : SR;
    Saw_run_20s : BOOL;
    SR1 : SR;
  END_VAR
  VAR_INPUT
    saw_off : BOOL := 0;
  END_VAR
  VAR
    SR2 : SR;
  END_VAR
  VAR_INPUT
    Fan_reset_button : BOOL := 0;
    Saw_run_20s_reset : BOOL := 0;
  END_VAR
  VAR
    R_TRIG0 : R_TRIG;
    TON0 : TON;
    TON1 : TON;
    TON2 : TON;
    SR3 : SR;
    _TMP_NOT19_OUT : BOOL;
    _TMP_NOT20_OUT : BOOL;
    _TMP_AND6_OUT : BOOL;
    _TMP_AND23_OUT : BOOL;
    _TMP_OR7_OUT : BOOL;
    _TMP_AND22_OUT : BOOL;
    _TMP_OR5_OUT : BOOL;
  END_VAR

  R_TRIG0(CLK := Start_Button);
  SR0(S1 := R_TRIG0.Q, R := saw_off);
  Saw := SR0.Q1;
  TON0(IN := Saw, PT := T#20s);
  SR3(S1 := TON0.Q, R := Saw_run_20s_reset);
  Saw_run_20s := SR3.Q1;
  _TMP_NOT19_OUT := NOT(Saw);
  _TMP_NOT20_OUT := NOT(Saw_run_20s);
  _TMP_AND6_OUT := AND(_TMP_NOT19_OUT, _TMP_NOT20_OUT);
  _TMP_AND23_OUT := AND(_TMP_NOT19_OUT, Saw_run_20s);
  TON1(IN := _TMP_AND23_OUT, PT := T#10s);
  _TMP_OR7_OUT := OR(_TMP_AND6_OUT, TON1.Q);
  SR1(S1 := R_TRIG0.Q, R := _TMP_OR7_OUT);
  Oil_Pump := SR1.Q1;
  TON2(IN := _TMP_AND6_OUT, PT := T#5s);
  _TMP_AND22_OUT := AND(_TMP_AND23_OUT, Fan_reset_button);
  _TMP_OR5_OUT := OR(TON2.Q, _TMP_AND22_OUT);
  SR2(S1 := R_TRIG0.Q, R := _TMP_OR5_OUT);
  Fan := SR2.Q1;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Industrial_Automation_practice_Saw_Fan_Oil_pump;
  END_RESOURCE
END_CONFIGURATION
