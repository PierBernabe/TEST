Normalised(
THEORY MagicNumberX IS
  MagicNumber(Refinement(ATTENTE_R1))==(3.5)
END
&
THEORY UpperLevelX IS
  First_Level(Refinement(ATTENTE_R1))==(Machine(ATTENTE));
  Level(Refinement(ATTENTE_R1))==(1);
  Upper_Level(Refinement(ATTENTE_R1))==(Machine(ATTENTE))
END
&
THEORY LoadedStructureX IS
  Refinement(ATTENTE_R1)
END
&
THEORY ListSeesX IS
  List_Sees(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListIncludesX IS
  Inherited_List_Includes(Refinement(ATTENTE_R1))==(?);
  List_Includes(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListPromotesX IS
  List_Promotes(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListExtendsX IS
  List_Extends(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListVariablesX IS
  External_Context_List_Variables(Refinement(ATTENTE_R1))==(?);
  Context_List_Variables(Refinement(ATTENTE_R1))==(?);
  Abstract_List_Variables(Refinement(ATTENTE_R1))==(nb_elem,attente);
  Local_List_Variables(Refinement(ATTENTE_R1))==(b2,b1,file);
  List_Variables(Refinement(ATTENTE_R1))==(b2,b1,file);
  External_List_Variables(Refinement(ATTENTE_R1))==(b2,b1,file)
END
&
THEORY ListVisibleVariablesX IS
  Inherited_List_VisibleVariables(Refinement(ATTENTE_R1))==(?);
  Abstract_List_VisibleVariables(Refinement(ATTENTE_R1))==(?);
  External_List_VisibleVariables(Refinement(ATTENTE_R1))==(?);
  Expanded_List_VisibleVariables(Refinement(ATTENTE_R1))==(?);
  List_VisibleVariables(Refinement(ATTENTE_R1))==(?);
  Internal_List_VisibleVariables(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListOfNewVariablesX IS
  List_Of_New_Variables(Refinement(ATTENTE_R1))==(b2,b1,file)
END
&
THEORY ListInvariantX IS
  Gluing_Seen_List_Invariant(Refinement(ATTENTE_R1))==(btrue);
  Expanded_List_Invariant(Refinement(ATTENTE_R1))==(btrue);
  Abstract_List_Invariant(Refinement(ATTENTE_R1))==(attente <: VAL & nb_elem: NAT & nb_elem<=nb_max & attente: FIN(attente) & nb_elem = card(attente));
  Context_List_Invariant(Refinement(ATTENTE_R1))==(btrue);
  List_Invariant(Refinement(ATTENTE_R1))==(file: NATURAL +-> VAL & b1: NATURAL & b2: NATURAL & nb_elem = b2-b1 & ran(file) = attente & b1: dom(file) & b2: dom(file))
END
&
THEORY ListVariantX IS
  List_Variant(Refinement(ATTENTE_R1))==(btrue)
END
&
THEORY ListAssertionsX IS
  Expanded_List_Assertions(Refinement(ATTENTE_R1))==(btrue);
  Abstract_List_Assertions(Refinement(ATTENTE_R1))==(btrue);
  Context_List_Assertions(Refinement(ATTENTE_R1))==(btrue);
  List_Assertions(Refinement(ATTENTE_R1))==(btrue)
END
&
THEORY ListCoverageX IS
  List_Coverage(Refinement(ATTENTE_R1))==(btrue)
END
&
THEORY ListExclusivityX IS
  List_Exclusivity(Refinement(ATTENTE_R1))==(btrue)
END
&
THEORY ListInitialisationX IS
  Expanded_List_Initialisation(Refinement(ATTENTE_R1))==(file,b1,b2:={},1,1);
  Context_List_Initialisation(Refinement(ATTENTE_R1))==(skip);
  List_Initialisation(Refinement(ATTENTE_R1))==(file:={} || b1:=1 || b2:=1)
END
&
THEORY ListOperationsX IS
  Internal_List_Operations(Refinement(ATTENTE_R1))==(nb_attente,ajouter,traiter);
  List_Operations(Refinement(ATTENTE_R1))==(nb_attente,ajouter,traiter)
END
&
THEORY ListInputX IS
  List_Input(Refinement(ATTENTE_R1),nb_attente)==(?);
  List_Input(Refinement(ATTENTE_R1),ajouter)==(vv);
  List_Input(Refinement(ATTENTE_R1),traiter)==(?)
END
&
THEORY ListOutputX IS
  List_Output(Refinement(ATTENTE_R1),nb_attente)==(nb);
  List_Output(Refinement(ATTENTE_R1),ajouter)==(?);
  List_Output(Refinement(ATTENTE_R1),traiter)==(vv)
END
&
THEORY ListHeaderX IS
  List_Header(Refinement(ATTENTE_R1),nb_attente)==(nb <-- nb_attente);
  List_Header(Refinement(ATTENTE_R1),ajouter)==(ajouter(vv));
  List_Header(Refinement(ATTENTE_R1),traiter)==(vv <-- traiter)
END
&
THEORY ListOperationGuardX END
&
THEORY ListPreconditionX IS
  Own_Precondition(Refinement(ATTENTE_R1),nb_attente)==(btrue);
  List_Precondition(Refinement(ATTENTE_R1),nb_attente)==(btrue);
  Own_Precondition(Refinement(ATTENTE_R1),ajouter)==(btrue);
  List_Precondition(Refinement(ATTENTE_R1),ajouter)==(vv: VAL & vv/:attente & nb_elem/=nb_max);
  Own_Precondition(Refinement(ATTENTE_R1),traiter)==(b1: dom(file));
  List_Precondition(Refinement(ATTENTE_R1),traiter)==(b1: dom(file) & attente/={})
END
&
THEORY ListSubstitutionX IS
  Expanded_List_Substitution(Refinement(ATTENTE_R1),traiter)==(b1: dom(file) & attente/={} | vv,b1,file:=file(b1),b1+1,file-{b1|->file(b1)});
  Expanded_List_Substitution(Refinement(ATTENTE_R1),ajouter)==(vv: VAL & vv/:attente & nb_elem/=nb_max | file,b2:=file<+{b2|->vv},b2+1);
  Expanded_List_Substitution(Refinement(ATTENTE_R1),nb_attente)==(btrue | nb:=b2-b1);
  List_Substitution(Refinement(ATTENTE_R1),nb_attente)==(nb:=b2-b1);
  List_Substitution(Refinement(ATTENTE_R1),ajouter)==(file(b2):=vv || b2:=b2+1);
  List_Substitution(Refinement(ATTENTE_R1),traiter)==(vv:=file(b1) || b1:=b1+1 || file:=file-{b1|->file(b1)})
END
&
THEORY ListParametersX IS
  List_Parameters(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListInstanciatedParametersX END
&
THEORY ListConstraintsX IS
  List_Constraints(Refinement(ATTENTE_R1))==(btrue);
  List_Context_Constraints(Refinement(ATTENTE_R1))==(btrue)
END
&
THEORY ListConstantsX IS
  List_Valuable_Constants(Refinement(ATTENTE_R1))==(nb_max);
  Inherited_List_Constants(Refinement(ATTENTE_R1))==(nb_max);
  List_Constants(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListSetsX IS
  Set_Definition(Refinement(ATTENTE_R1),VAL)==(?);
  Context_List_Enumerated(Refinement(ATTENTE_R1))==(?);
  Context_List_Defered(Refinement(ATTENTE_R1))==(?);
  Context_List_Sets(Refinement(ATTENTE_R1))==(?);
  List_Valuable_Sets(Refinement(ATTENTE_R1))==(VAL);
  Inherited_List_Enumerated(Refinement(ATTENTE_R1))==(?);
  Inherited_List_Defered(Refinement(ATTENTE_R1))==(VAL);
  Inherited_List_Sets(Refinement(ATTENTE_R1))==(VAL);
  List_Enumerated(Refinement(ATTENTE_R1))==(?);
  List_Defered(Refinement(ATTENTE_R1))==(?);
  List_Sets(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListHiddenConstantsX IS
  Abstract_List_HiddenConstants(Refinement(ATTENTE_R1))==(?);
  Expanded_List_HiddenConstants(Refinement(ATTENTE_R1))==(?);
  List_HiddenConstants(Refinement(ATTENTE_R1))==(?);
  External_List_HiddenConstants(Refinement(ATTENTE_R1))==(?)
END
&
THEORY ListPropertiesX IS
  Abstract_List_Properties(Refinement(ATTENTE_R1))==(nb_max: 1..MAXINT & VAL: FIN(INTEGER) & not(VAL = {}));
  Context_List_Properties(Refinement(ATTENTE_R1))==(btrue);
  Inherited_List_Properties(Refinement(ATTENTE_R1))==(btrue);
  List_Properties(Refinement(ATTENTE_R1))==(btrue)
END
&
THEORY ListSeenInfoX END
&
THEORY ListANYVarX IS
  List_ANY_Var(Refinement(ATTENTE_R1),nb_attente)==(?);
  List_ANY_Var(Refinement(ATTENTE_R1),ajouter)==(?);
  List_ANY_Var(Refinement(ATTENTE_R1),traiter)==(?)
END
&
THEORY ListOfIdsX IS
  List_Of_Ids(Refinement(ATTENTE_R1)) == (? | ? | b2,b1,file | ? | nb_attente,ajouter,traiter | ? | ? | ? | ATTENTE_R1);
  List_Of_HiddenCst_Ids(Refinement(ATTENTE_R1)) == (? | ?);
  List_Of_VisibleCst_Ids(Refinement(ATTENTE_R1)) == (?);
  List_Of_VisibleVar_Ids(Refinement(ATTENTE_R1)) == (? | ?);
  List_Of_Ids_SeenBNU(Refinement(ATTENTE_R1)) == (?: ?)
END
&
THEORY SetsEnvX IS
  Sets(Refinement(ATTENTE_R1)) == (Type(VAL) == Cst(SetOf(atype(VAL,"[VAL","]VAL"))))
END
&
THEORY ConstantsEnvX IS
  Constants(Refinement(ATTENTE_R1)) == (Type(nb_max) == Cst(btype(INTEGER,?,?)))
END
&
THEORY VariablesEnvX IS
  Variables(Refinement(ATTENTE_R1)) == (Type(b2) == Mvl(btype(INTEGER,?,?));Type(b1) == Mvl(btype(INTEGER,?,?));Type(file) == Mvl(SetOf(btype(INTEGER,?,?)*atype(VAL,?,?))))
END
&
THEORY OperationsEnvX IS
  Operations(Refinement(ATTENTE_R1)) == (Type(traiter) == Cst(atype(VAL,?,?),No_type);Type(ajouter) == Cst(No_type,atype(VAL,?,?));Type(nb_attente) == Cst(btype(INTEGER,?,?),No_type))
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
