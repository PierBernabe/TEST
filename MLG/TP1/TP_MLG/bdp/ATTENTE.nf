Normalised(
THEORY MagicNumberX IS
  MagicNumber(Machine(ATTENTE))==(3.5)
END
&
THEORY UpperLevelX IS
  First_Level(Machine(ATTENTE))==(Machine(ATTENTE));
  Level(Machine(ATTENTE))==(0)
END
&
THEORY LoadedStructureX IS
  Machine(ATTENTE)
END
&
THEORY ListSeesX IS
  List_Sees(Machine(ATTENTE))==(?)
END
&
THEORY ListUsesX IS
  List_Uses(Machine(ATTENTE))==(?)
END
&
THEORY ListIncludesX IS
  Inherited_List_Includes(Machine(ATTENTE))==(?);
  List_Includes(Machine(ATTENTE))==(?)
END
&
THEORY ListPromotesX IS
  List_Promotes(Machine(ATTENTE))==(?)
END
&
THEORY ListExtendsX IS
  List_Extends(Machine(ATTENTE))==(?)
END
&
THEORY ListVariablesX IS
  External_Context_List_Variables(Machine(ATTENTE))==(?);
  Context_List_Variables(Machine(ATTENTE))==(?);
  Abstract_List_Variables(Machine(ATTENTE))==(?);
  Local_List_Variables(Machine(ATTENTE))==(nb_elem,attente);
  List_Variables(Machine(ATTENTE))==(nb_elem,attente);
  External_List_Variables(Machine(ATTENTE))==(nb_elem,attente)
END
&
THEORY ListVisibleVariablesX IS
  Inherited_List_VisibleVariables(Machine(ATTENTE))==(?);
  Abstract_List_VisibleVariables(Machine(ATTENTE))==(?);
  External_List_VisibleVariables(Machine(ATTENTE))==(?);
  Expanded_List_VisibleVariables(Machine(ATTENTE))==(?);
  List_VisibleVariables(Machine(ATTENTE))==(?);
  Internal_List_VisibleVariables(Machine(ATTENTE))==(?)
END
&
THEORY ListInvariantX IS
  Gluing_Seen_List_Invariant(Machine(ATTENTE))==(btrue);
  Gluing_List_Invariant(Machine(ATTENTE))==(btrue);
  Expanded_List_Invariant(Machine(ATTENTE))==(btrue);
  Abstract_List_Invariant(Machine(ATTENTE))==(btrue);
  Context_List_Invariant(Machine(ATTENTE))==(btrue);
  List_Invariant(Machine(ATTENTE))==(attente <: VAL & nb_elem: NAT & nb_elem<=nb_max & attente: FIN(attente) & nb_elem = card(attente))
END
&
THEORY ListAssertionsX IS
  Expanded_List_Assertions(Machine(ATTENTE))==(btrue);
  Abstract_List_Assertions(Machine(ATTENTE))==(btrue);
  Context_List_Assertions(Machine(ATTENTE))==(btrue);
  List_Assertions(Machine(ATTENTE))==(btrue)
END
&
THEORY ListCoverageX IS
  List_Coverage(Machine(ATTENTE))==(btrue)
END
&
THEORY ListExclusivityX IS
  List_Exclusivity(Machine(ATTENTE))==(btrue)
END
&
THEORY ListInitialisationX IS
  Expanded_List_Initialisation(Machine(ATTENTE))==(nb_elem,attente:=0,{});
  Context_List_Initialisation(Machine(ATTENTE))==(skip);
  List_Initialisation(Machine(ATTENTE))==(nb_elem:=0 || attente:={})
END
&
THEORY ListParametersX IS
  List_Parameters(Machine(ATTENTE))==(?)
END
&
THEORY ListInstanciatedParametersX END
&
THEORY ListConstraintsX IS
  List_Context_Constraints(Machine(ATTENTE))==(btrue);
  List_Constraints(Machine(ATTENTE))==(btrue)
END
&
THEORY ListOperationsX IS
  Internal_List_Operations(Machine(ATTENTE))==(nb_attente,ajouter,traiter);
  List_Operations(Machine(ATTENTE))==(nb_attente,ajouter,traiter)
END
&
THEORY ListInputX IS
  List_Input(Machine(ATTENTE),nb_attente)==(?);
  List_Input(Machine(ATTENTE),ajouter)==(vv);
  List_Input(Machine(ATTENTE),traiter)==(?)
END
&
THEORY ListOutputX IS
  List_Output(Machine(ATTENTE),nb_attente)==(nb);
  List_Output(Machine(ATTENTE),ajouter)==(?);
  List_Output(Machine(ATTENTE),traiter)==(vv)
END
&
THEORY ListHeaderX IS
  List_Header(Machine(ATTENTE),nb_attente)==(nb <-- nb_attente);
  List_Header(Machine(ATTENTE),ajouter)==(ajouter(vv));
  List_Header(Machine(ATTENTE),traiter)==(vv <-- traiter)
END
&
THEORY ListOperationGuardX END
&
THEORY ListPreconditionX IS
  List_Precondition(Machine(ATTENTE),nb_attente)==(btrue);
  List_Precondition(Machine(ATTENTE),ajouter)==(vv: VAL & vv/:attente & nb_elem/=nb_max);
  List_Precondition(Machine(ATTENTE),traiter)==(attente/={})
END
&
THEORY ListSubstitutionX IS
  Expanded_List_Substitution(Machine(ATTENTE),traiter)==(attente/={} | @val.(val: VAL & val: attente ==> vv,attente,nb_elem:=val,attente-{val},nb_elem-1));
  Expanded_List_Substitution(Machine(ATTENTE),ajouter)==(vv: VAL & vv/:attente & nb_elem/=nb_max | attente,nb_elem:=attente\/{vv},nb_elem+1);
  Expanded_List_Substitution(Machine(ATTENTE),nb_attente)==(btrue | nb:=nb_elem);
  List_Substitution(Machine(ATTENTE),nb_attente)==(nb:=nb_elem);
  List_Substitution(Machine(ATTENTE),ajouter)==(attente:=attente\/{vv} || nb_elem:=nb_elem+1);
  List_Substitution(Machine(ATTENTE),traiter)==(ANY val WHERE val: VAL & val: attente THEN vv:=val || attente:=attente-{val} || nb_elem:=nb_elem-1 END)
END
&
THEORY ListConstantsX IS
  List_Valuable_Constants(Machine(ATTENTE))==(nb_max);
  Inherited_List_Constants(Machine(ATTENTE))==(?);
  List_Constants(Machine(ATTENTE))==(nb_max)
END
&
THEORY ListSetsX IS
  Set_Definition(Machine(ATTENTE),VAL)==(?);
  Context_List_Enumerated(Machine(ATTENTE))==(?);
  Context_List_Defered(Machine(ATTENTE))==(?);
  Context_List_Sets(Machine(ATTENTE))==(?);
  List_Valuable_Sets(Machine(ATTENTE))==(VAL);
  Inherited_List_Enumerated(Machine(ATTENTE))==(?);
  Inherited_List_Defered(Machine(ATTENTE))==(?);
  Inherited_List_Sets(Machine(ATTENTE))==(?);
  List_Enumerated(Machine(ATTENTE))==(?);
  List_Defered(Machine(ATTENTE))==(VAL);
  List_Sets(Machine(ATTENTE))==(VAL)
END
&
THEORY ListHiddenConstantsX IS
  Abstract_List_HiddenConstants(Machine(ATTENTE))==(?);
  Expanded_List_HiddenConstants(Machine(ATTENTE))==(?);
  List_HiddenConstants(Machine(ATTENTE))==(?);
  External_List_HiddenConstants(Machine(ATTENTE))==(?)
END
&
THEORY ListPropertiesX IS
  Abstract_List_Properties(Machine(ATTENTE))==(btrue);
  Context_List_Properties(Machine(ATTENTE))==(btrue);
  Inherited_List_Properties(Machine(ATTENTE))==(btrue);
  List_Properties(Machine(ATTENTE))==(nb_max: 1..MAXINT & VAL: FIN(INTEGER) & not(VAL = {}))
END
&
THEORY ListSeenInfoX END
&
THEORY ListANYVarX IS
  List_ANY_Var(Machine(ATTENTE),nb_attente)==(?);
  List_ANY_Var(Machine(ATTENTE),ajouter)==(?);
  List_ANY_Var(Machine(ATTENTE),traiter)==(Var(val) == atype(VAL,?,?))
END
&
THEORY ListOfIdsX IS
  List_Of_Ids(Machine(ATTENTE)) == (nb_max,VAL | ? | nb_elem,attente | ? | nb_attente,ajouter,traiter | ? | ? | ? | ATTENTE);
  List_Of_HiddenCst_Ids(Machine(ATTENTE)) == (? | ?);
  List_Of_VisibleCst_Ids(Machine(ATTENTE)) == (nb_max);
  List_Of_VisibleVar_Ids(Machine(ATTENTE)) == (? | ?);
  List_Of_Ids_SeenBNU(Machine(ATTENTE)) == (?: ?)
END
&
THEORY SetsEnvX IS
  Sets(Machine(ATTENTE)) == (Type(VAL) == Cst(SetOf(atype(VAL,"[VAL","]VAL"))))
END
&
THEORY ConstantsEnvX IS
  Constants(Machine(ATTENTE)) == (Type(nb_max) == Cst(btype(INTEGER,?,?)))
END
&
THEORY VariablesEnvX IS
  Variables(Machine(ATTENTE)) == (Type(nb_elem) == Mvl(btype(INTEGER,?,?));Type(attente) == Mvl(SetOf(atype(VAL,?,?))))
END
&
THEORY OperationsEnvX IS
  Operations(Machine(ATTENTE)) == (Type(traiter) == Cst(atype(VAL,?,?),No_type);Type(ajouter) == Cst(No_type,atype(VAL,?,?));Type(nb_attente) == Cst(btype(INTEGER,?,?),No_type));
  Observers(Machine(ATTENTE)) == (Type(nb_attente) == Cst(btype(INTEGER,?,?),No_type))
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
