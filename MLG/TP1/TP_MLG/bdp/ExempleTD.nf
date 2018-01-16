Normalised(
THEORY MagicNumberX IS
  MagicNumber(Machine(ExempleTD))==(3.5)
END
&
THEORY UpperLevelX IS
  First_Level(Machine(ExempleTD))==(Machine(ExempleTD));
  Level(Machine(ExempleTD))==(0)
END
&
THEORY LoadedStructureX IS
  Machine(ExempleTD)
END
&
THEORY ListSeesX IS
  List_Sees(Machine(ExempleTD))==(?)
END
&
THEORY ListUsesX IS
  List_Uses(Machine(ExempleTD))==(?)
END
&
THEORY ListIncludesX IS
  Inherited_List_Includes(Machine(ExempleTD))==(?);
  List_Includes(Machine(ExempleTD))==(?)
END
&
THEORY ListPromotesX IS
  List_Promotes(Machine(ExempleTD))==(?)
END
&
THEORY ListExtendsX IS
  List_Extends(Machine(ExempleTD))==(?)
END
&
THEORY ListVariablesX IS
  External_Context_List_Variables(Machine(ExempleTD))==(?);
  Context_List_Variables(Machine(ExempleTD))==(?);
  Abstract_List_Variables(Machine(ExempleTD))==(?);
  Local_List_Variables(Machine(ExempleTD))==(yy,xx);
  List_Variables(Machine(ExempleTD))==(yy,xx);
  External_List_Variables(Machine(ExempleTD))==(yy,xx)
END
&
THEORY ListVisibleVariablesX IS
  Inherited_List_VisibleVariables(Machine(ExempleTD))==(?);
  Abstract_List_VisibleVariables(Machine(ExempleTD))==(?);
  External_List_VisibleVariables(Machine(ExempleTD))==(?);
  Expanded_List_VisibleVariables(Machine(ExempleTD))==(?);
  List_VisibleVariables(Machine(ExempleTD))==(?);
  Internal_List_VisibleVariables(Machine(ExempleTD))==(?)
END
&
THEORY ListInvariantX IS
  Gluing_Seen_List_Invariant(Machine(ExempleTD))==(btrue);
  Gluing_List_Invariant(Machine(ExempleTD))==(btrue);
  Expanded_List_Invariant(Machine(ExempleTD))==(btrue);
  Abstract_List_Invariant(Machine(ExempleTD))==(btrue);
  Context_List_Invariant(Machine(ExempleTD))==(btrue);
  List_Invariant(Machine(ExempleTD))==(xx: NATURAL & yy: NATURAL & xx>yy)
END
&
THEORY ListAssertionsX IS
  Expanded_List_Assertions(Machine(ExempleTD))==(btrue);
  Abstract_List_Assertions(Machine(ExempleTD))==(btrue);
  Context_List_Assertions(Machine(ExempleTD))==(btrue);
  List_Assertions(Machine(ExempleTD))==(btrue)
END
&
THEORY ListCoverageX IS
  List_Coverage(Machine(ExempleTD))==(btrue)
END
&
THEORY ListExclusivityX IS
  List_Exclusivity(Machine(ExempleTD))==(btrue)
END
&
THEORY ListInitialisationX IS
  Expanded_List_Initialisation(Machine(ExempleTD))==(xx,yy:=1,0);
  Context_List_Initialisation(Machine(ExempleTD))==(skip);
  List_Initialisation(Machine(ExempleTD))==(xx:=1 || yy:=0)
END
&
THEORY ListParametersX IS
  List_Parameters(Machine(ExempleTD))==(?)
END
&
THEORY ListInstanciatedParametersX END
&
THEORY ListConstraintsX IS
  List_Context_Constraints(Machine(ExempleTD))==(btrue);
  List_Constraints(Machine(ExempleTD))==(btrue)
END
&
THEORY ListOperationsX IS
  Internal_List_Operations(Machine(ExempleTD))==(incr,reset);
  List_Operations(Machine(ExempleTD))==(incr,reset)
END
&
THEORY ListInputX IS
  List_Input(Machine(ExempleTD),incr)==(?);
  List_Input(Machine(ExempleTD),reset)==(?)
END
&
THEORY ListOutputX IS
  List_Output(Machine(ExempleTD),incr)==(?);
  List_Output(Machine(ExempleTD),reset)==(?)
END
&
THEORY ListHeaderX IS
  List_Header(Machine(ExempleTD),incr)==(incr);
  List_Header(Machine(ExempleTD),reset)==(reset)
END
&
THEORY ListOperationGuardX END
&
THEORY ListPreconditionX IS
  List_Precondition(Machine(ExempleTD),incr)==(btrue);
  List_Precondition(Machine(ExempleTD),reset)==(btrue)
END
&
THEORY ListSubstitutionX IS
  Expanded_List_Substitution(Machine(ExempleTD),reset)==(btrue | @(nx,ny).(nx: NAT & ny: NAT & nx>ny ==> xx,yy:=nx,ny));
  Expanded_List_Substitution(Machine(ExempleTD),incr)==(btrue | xx:=xx+1 [] (xx = yy+1 ==> yy:=yy [] not(xx = yy+1) ==> yy:=yy+1));
  List_Substitution(Machine(ExempleTD),incr)==(CHOICE xx:=xx+1 OR IF xx = yy+1 THEN yy:=yy ELSE yy:=yy+1 END END);
  List_Substitution(Machine(ExempleTD),reset)==(ANY nx,ny WHERE nx: NAT & ny: NAT & nx>ny THEN xx:=nx || yy:=ny END)
END
&
THEORY ListConstantsX IS
  List_Valuable_Constants(Machine(ExempleTD))==(?);
  Inherited_List_Constants(Machine(ExempleTD))==(?);
  List_Constants(Machine(ExempleTD))==(?)
END
&
THEORY ListSetsX IS
  Context_List_Enumerated(Machine(ExempleTD))==(?);
  Context_List_Defered(Machine(ExempleTD))==(?);
  Context_List_Sets(Machine(ExempleTD))==(?);
  List_Valuable_Sets(Machine(ExempleTD))==(?);
  Inherited_List_Enumerated(Machine(ExempleTD))==(?);
  Inherited_List_Defered(Machine(ExempleTD))==(?);
  Inherited_List_Sets(Machine(ExempleTD))==(?);
  List_Enumerated(Machine(ExempleTD))==(?);
  List_Defered(Machine(ExempleTD))==(?);
  List_Sets(Machine(ExempleTD))==(?)
END
&
THEORY ListHiddenConstantsX IS
  Abstract_List_HiddenConstants(Machine(ExempleTD))==(?);
  Expanded_List_HiddenConstants(Machine(ExempleTD))==(?);
  List_HiddenConstants(Machine(ExempleTD))==(?);
  External_List_HiddenConstants(Machine(ExempleTD))==(?)
END
&
THEORY ListPropertiesX IS
  Abstract_List_Properties(Machine(ExempleTD))==(btrue);
  Context_List_Properties(Machine(ExempleTD))==(btrue);
  Inherited_List_Properties(Machine(ExempleTD))==(btrue);
  List_Properties(Machine(ExempleTD))==(btrue)
END
&
THEORY ListSeenInfoX END
&
THEORY ListANYVarX IS
  List_ANY_Var(Machine(ExempleTD),incr)==(?);
  List_ANY_Var(Machine(ExempleTD),reset)==((Var(nx) == btype(INTEGER,?,?)),(Var(ny) == btype(INTEGER,?,?)))
END
&
THEORY ListOfIdsX IS
  List_Of_Ids(Machine(ExempleTD)) == (? | ? | yy,xx | ? | incr,reset | ? | ? | ? | ExempleTD);
  List_Of_HiddenCst_Ids(Machine(ExempleTD)) == (? | ?);
  List_Of_VisibleCst_Ids(Machine(ExempleTD)) == (?);
  List_Of_VisibleVar_Ids(Machine(ExempleTD)) == (? | ?);
  List_Of_Ids_SeenBNU(Machine(ExempleTD)) == (?: ?)
END
&
THEORY VariablesEnvX IS
  Variables(Machine(ExempleTD)) == (Type(yy) == Mvl(btype(INTEGER,?,?));Type(xx) == Mvl(btype(INTEGER,?,?)))
END
&
THEORY OperationsEnvX IS
  Operations(Machine(ExempleTD)) == (Type(reset) == Cst(No_type,No_type);Type(incr) == Cst(No_type,No_type))
END
&
THEORY TCIntRdX IS
  predB0 == OK;
  extended_sees == KO;
  B0check_tab == KO;
  local_op == OK;
  abstract_constants_visible_in_values == KO;
  project_type == SOFTWARE_TYPE;
  event_b_deadlockfreeness == KO;
  variant_clause_mandatory == KO;
  event_b_coverage == KO;
  event_b_exclusivity == KO;
  genFeasibilityPO == KO
END
)
