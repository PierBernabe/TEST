Normalised(
THEORY MagicNumberX IS
  MagicNumber(Machine(Genealogie))==(3.5)
END
&
THEORY UpperLevelX IS
  First_Level(Machine(Genealogie))==(Machine(Genealogie));
  Level(Machine(Genealogie))==(0)
END
&
THEORY LoadedStructureX IS
  Machine(Genealogie)
END
&
THEORY ListSeesX IS
  List_Sees(Machine(Genealogie))==(?)
END
&
THEORY ListUsesX IS
  List_Uses(Machine(Genealogie))==(?)
END
&
THEORY ListIncludesX IS
  Inherited_List_Includes(Machine(Genealogie))==(?);
  List_Includes(Machine(Genealogie))==(?)
END
&
THEORY ListPromotesX IS
  List_Promotes(Machine(Genealogie))==(?)
END
&
THEORY ListExtendsX IS
  List_Extends(Machine(Genealogie))==(?)
END
&
THEORY ListVariablesX IS
  External_Context_List_Variables(Machine(Genealogie))==(?);
  Context_List_Variables(Machine(Genealogie))==(?);
  Abstract_List_Variables(Machine(Genealogie))==(?);
  Local_List_Variables(Machine(Genealogie))==(Mere,Pere,Femmes,Hommes);
  List_Variables(Machine(Genealogie))==(Mere,Pere,Femmes,Hommes);
  External_List_Variables(Machine(Genealogie))==(Mere,Pere,Femmes,Hommes)
END
&
THEORY ListVisibleVariablesX IS
  Inherited_List_VisibleVariables(Machine(Genealogie))==(?);
  Abstract_List_VisibleVariables(Machine(Genealogie))==(?);
  External_List_VisibleVariables(Machine(Genealogie))==(?);
  Expanded_List_VisibleVariables(Machine(Genealogie))==(?);
  List_VisibleVariables(Machine(Genealogie))==(?);
  Internal_List_VisibleVariables(Machine(Genealogie))==(?)
END
&
THEORY ListInvariantX IS
  Gluing_Seen_List_Invariant(Machine(Genealogie))==(btrue);
  Gluing_List_Invariant(Machine(Genealogie))==(btrue);
  Expanded_List_Invariant(Machine(Genealogie))==(btrue);
  Abstract_List_Invariant(Machine(Genealogie))==(btrue);
  Context_List_Invariant(Machine(Genealogie))==(btrue);
  List_Invariant(Machine(Genealogie))==(Hommes <: PERSONNES & Femmes <: PERSONNES & Hommes/\Femmes = {} & Pere: (Hommes\/Femmes)-H0-F0 --> Hommes & Mere: (Hommes\/Femmes)-H0-F0 --> Femmes)
END
&
THEORY ListAssertionsX IS
  Expanded_List_Assertions(Machine(Genealogie))==(btrue);
  Abstract_List_Assertions(Machine(Genealogie))==(btrue);
  Context_List_Assertions(Machine(Genealogie))==(btrue);
  List_Assertions(Machine(Genealogie))==(btrue)
END
&
THEORY ListCoverageX IS
  List_Coverage(Machine(Genealogie))==(btrue)
END
&
THEORY ListExclusivityX IS
  List_Exclusivity(Machine(Genealogie))==(btrue)
END
&
THEORY ListInitialisationX IS
  Expanded_List_Initialisation(Machine(Genealogie))==(Hommes,Femmes,Pere,Mere:=H0,F0,{},{});
  Context_List_Initialisation(Machine(Genealogie))==(skip);
  List_Initialisation(Machine(Genealogie))==(Hommes:=H0 || Femmes:=F0 || Pere:={} || Mere:={})
END
&
THEORY ListParametersX IS
  List_Parameters(Machine(Genealogie))==(?)
END
&
THEORY ListInstanciatedParametersX END
&
THEORY ListConstraintsX IS
  List_Context_Constraints(Machine(Genealogie))==(btrue);
  List_Constraints(Machine(Genealogie))==(btrue)
END
&
THEORY ListOperationsX IS
  Internal_List_Operations(Machine(Genealogie))==(naitre);
  List_Operations(Machine(Genealogie))==(naitre)
END
&
THEORY ListInputX IS
  List_Input(Machine(Genealogie),naitre)==(pere,mere)
END
&
THEORY ListOutputX IS
  List_Output(Machine(Genealogie),naitre)==(?)
END
&
THEORY ListHeaderX IS
  List_Header(Machine(Genealogie),naitre)==(naitre(pere,mere))
END
&
THEORY ListOperationGuardX END
&
THEORY ListPreconditionX IS
  List_Precondition(Machine(Genealogie),naitre)==(pere: Hommes & mere: Femmes)
END
&
THEORY ListSubstitutionX IS
  Expanded_List_Substitution(Machine(Genealogie),naitre)==(pere: Hommes & mere: Femmes | @alien.(alien: PERSONNES-Hommes-Femmes ==> (Pere,Mere:=Pere<+{alien|->pere},Mere<+{alien|->mere} || (Hommes:=Hommes\/{alien} [] Femmes:=Femmes\/{alien}))));
  List_Substitution(Machine(Genealogie),naitre)==(ANY alien WHERE alien: PERSONNES-Hommes-Femmes THEN Pere(alien):=pere || Mere(alien):=mere || CHOICE Hommes:=Hommes\/{alien} OR Femmes:=Femmes\/{alien} END END)
END
&
THEORY ListConstantsX IS
  List_Valuable_Constants(Machine(Genealogie))==(H0,F0);
  Inherited_List_Constants(Machine(Genealogie))==(?);
  List_Constants(Machine(Genealogie))==(H0,F0)
END
&
THEORY ListSetsX IS
  Set_Definition(Machine(Genealogie),PERSONNES)==(?);
  Context_List_Enumerated(Machine(Genealogie))==(?);
  Context_List_Defered(Machine(Genealogie))==(?);
  Context_List_Sets(Machine(Genealogie))==(?);
  List_Valuable_Sets(Machine(Genealogie))==(PERSONNES);
  Inherited_List_Enumerated(Machine(Genealogie))==(?);
  Inherited_List_Defered(Machine(Genealogie))==(?);
  Inherited_List_Sets(Machine(Genealogie))==(?);
  List_Enumerated(Machine(Genealogie))==(?);
  List_Defered(Machine(Genealogie))==(PERSONNES);
  List_Sets(Machine(Genealogie))==(PERSONNES)
END
&
THEORY ListHiddenConstantsX IS
  Abstract_List_HiddenConstants(Machine(Genealogie))==(?);
  Expanded_List_HiddenConstants(Machine(Genealogie))==(?);
  List_HiddenConstants(Machine(Genealogie))==(?);
  External_List_HiddenConstants(Machine(Genealogie))==(?)
END
&
THEORY ListPropertiesX IS
  Abstract_List_Properties(Machine(Genealogie))==(btrue);
  Context_List_Properties(Machine(Genealogie))==(btrue);
  Inherited_List_Properties(Machine(Genealogie))==(btrue);
  List_Properties(Machine(Genealogie))==(H0 <: PERSONNES & F0 <: PERSONNES & H0/\F0 = {} & PERSONNES: FIN(INTEGER) & not(PERSONNES = {}))
END
&
THEORY ListSeenInfoX END
&
THEORY ListANYVarX IS
  List_ANY_Var(Machine(Genealogie),naitre)==(Var(alien) == atype(PERSONNES,?,?))
END
&
THEORY ListOfIdsX IS
  List_Of_Ids(Machine(Genealogie)) == (H0,F0,PERSONNES | ? | Mere,Pere,Femmes,Hommes | ? | naitre | ? | ? | ? | Genealogie);
  List_Of_HiddenCst_Ids(Machine(Genealogie)) == (? | ?);
  List_Of_VisibleCst_Ids(Machine(Genealogie)) == (H0,F0);
  List_Of_VisibleVar_Ids(Machine(Genealogie)) == (? | ?);
  List_Of_Ids_SeenBNU(Machine(Genealogie)) == (?: ?)
END
&
THEORY SetsEnvX IS
  Sets(Machine(Genealogie)) == (Type(PERSONNES) == Cst(SetOf(atype(PERSONNES,"[PERSONNES","]PERSONNES"))))
END
&
THEORY ConstantsEnvX IS
  Constants(Machine(Genealogie)) == (Type(H0) == Cst(SetOf(atype(PERSONNES,"[H0","]H0")));Type(F0) == Cst(SetOf(atype(PERSONNES,"[F0","]F0"))))
END
&
THEORY VariablesEnvX IS
  Variables(Machine(Genealogie)) == (Type(Mere) == Mvl(SetOf(atype(PERSONNES,?,?)*atype(PERSONNES,?,?)));Type(Pere) == Mvl(SetOf(atype(PERSONNES,?,?)*atype(PERSONNES,?,?)));Type(Femmes) == Mvl(SetOf(atype(PERSONNES,?,?)));Type(Hommes) == Mvl(SetOf(atype(PERSONNES,?,?))))
END
&
THEORY OperationsEnvX IS
  Operations(Machine(Genealogie)) == (Type(naitre) == Cst(No_type,atype(PERSONNES,?,?)*atype(PERSONNES,?,?)))
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
