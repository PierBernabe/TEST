Normalised(
THEORY MagicNumberX IS
  MagicNumber(Machine(ECLUSE))==(3.5)
END
&
THEORY UpperLevelX IS
  First_Level(Machine(ECLUSE))==(Machine(ECLUSE));
  Level(Machine(ECLUSE))==(0)
END
&
THEORY LoadedStructureX IS
  Machine(ECLUSE)
END
&
THEORY ListSeesX IS
  List_Sees(Machine(ECLUSE))==(?)
END
&
THEORY ListUsesX IS
  List_Uses(Machine(ECLUSE))==(?)
END
&
THEORY ListIncludesX IS
  Inherited_List_Includes(Machine(ECLUSE))==(?);
  List_Includes(Machine(ECLUSE))==(?)
END
&
THEORY ListPromotesX IS
  List_Promotes(Machine(ECLUSE))==(?)
END
&
THEORY ListExtendsX IS
  List_Extends(Machine(ECLUSE))==(?)
END
&
THEORY ListVariablesX IS
  External_Context_List_Variables(Machine(ECLUSE))==(?);
  Context_List_Variables(Machine(ECLUSE))==(?);
  Abstract_List_Variables(Machine(ECLUSE))==(?);
  Local_List_Variables(Machine(ECLUSE))==(pam,pav,sas);
  List_Variables(Machine(ECLUSE))==(pam,pav,sas);
  External_List_Variables(Machine(ECLUSE))==(pam,pav,sas)
END
&
THEORY ListVisibleVariablesX IS
  Inherited_List_VisibleVariables(Machine(ECLUSE))==(?);
  Abstract_List_VisibleVariables(Machine(ECLUSE))==(?);
  External_List_VisibleVariables(Machine(ECLUSE))==(?);
  Expanded_List_VisibleVariables(Machine(ECLUSE))==(?);
  List_VisibleVariables(Machine(ECLUSE))==(?);
  Internal_List_VisibleVariables(Machine(ECLUSE))==(?)
END
&
THEORY ListInvariantX IS
  Gluing_Seen_List_Invariant(Machine(ECLUSE))==(btrue);
  Gluing_List_Invariant(Machine(ECLUSE))==(btrue);
  Expanded_List_Invariant(Machine(ECLUSE))==(btrue);
  Abstract_List_Invariant(Machine(ECLUSE))==(btrue);
  Context_List_Invariant(Machine(ECLUSE))==(btrue);
  List_Invariant(Machine(ECLUSE))==(sas: NIVEAU & pav: PORTE & pam: PORTE & (pav = ouverte => pam = fermee & sas = bas) & (pam = ouverte => pav = fermee & sas = haut))
END
&
THEORY ListAssertionsX IS
  Expanded_List_Assertions(Machine(ECLUSE))==(btrue);
  Abstract_List_Assertions(Machine(ECLUSE))==(btrue);
  Context_List_Assertions(Machine(ECLUSE))==(btrue);
  List_Assertions(Machine(ECLUSE))==(btrue)
END
&
THEORY ListCoverageX IS
  List_Coverage(Machine(ECLUSE))==(btrue)
END
&
THEORY ListExclusivityX IS
  List_Exclusivity(Machine(ECLUSE))==(btrue)
END
&
THEORY ListInitialisationX IS
  Expanded_List_Initialisation(Machine(ECLUSE))==(sas,pav,pam:=haut,fermee,fermee);
  Context_List_Initialisation(Machine(ECLUSE))==(skip);
  List_Initialisation(Machine(ECLUSE))==(sas,pav,pam:=haut,fermee,fermee)
END
&
THEORY ListParametersX IS
  List_Parameters(Machine(ECLUSE))==(?)
END
&
THEORY ListInstanciatedParametersX END
&
THEORY ListConstraintsX IS
  List_Context_Constraints(Machine(ECLUSE))==(btrue);
  List_Constraints(Machine(ECLUSE))==(btrue)
END
&
THEORY ListOperationsX IS
  Internal_List_Operations(Machine(ECLUSE))==(remplir,vider,ouvrir_amont,fermer_amont,ouvrir_aval,fermer_aval);
  List_Operations(Machine(ECLUSE))==(remplir,vider,ouvrir_amont,fermer_amont,ouvrir_aval,fermer_aval)
END
&
THEORY ListInputX IS
  List_Input(Machine(ECLUSE),remplir)==(?);
  List_Input(Machine(ECLUSE),vider)==(?);
  List_Input(Machine(ECLUSE),ouvrir_amont)==(?);
  List_Input(Machine(ECLUSE),fermer_amont)==(?);
  List_Input(Machine(ECLUSE),ouvrir_aval)==(?);
  List_Input(Machine(ECLUSE),fermer_aval)==(?)
END
&
THEORY ListOutputX IS
  List_Output(Machine(ECLUSE),remplir)==(?);
  List_Output(Machine(ECLUSE),vider)==(?);
  List_Output(Machine(ECLUSE),ouvrir_amont)==(?);
  List_Output(Machine(ECLUSE),fermer_amont)==(?);
  List_Output(Machine(ECLUSE),ouvrir_aval)==(?);
  List_Output(Machine(ECLUSE),fermer_aval)==(?)
END
&
THEORY ListHeaderX IS
  List_Header(Machine(ECLUSE),remplir)==(remplir);
  List_Header(Machine(ECLUSE),vider)==(vider);
  List_Header(Machine(ECLUSE),ouvrir_amont)==(ouvrir_amont);
  List_Header(Machine(ECLUSE),fermer_amont)==(fermer_amont);
  List_Header(Machine(ECLUSE),ouvrir_aval)==(ouvrir_aval);
  List_Header(Machine(ECLUSE),fermer_aval)==(fermer_aval)
END
&
THEORY ListOperationGuardX END
&
THEORY ListPreconditionX IS
  List_Precondition(Machine(ECLUSE),remplir)==(pav = fermee & pam = fermee);
  List_Precondition(Machine(ECLUSE),vider)==(pav = fermee & pam = fermee);
  List_Precondition(Machine(ECLUSE),ouvrir_amont)==(pav = fermee & pam = fermee & sas = haut);
  List_Precondition(Machine(ECLUSE),fermer_amont)==(pav = fermee & pam = ouverte & sas = haut);
  List_Precondition(Machine(ECLUSE),ouvrir_aval)==(pav = fermee & pam = fermee & sas = bas);
  List_Precondition(Machine(ECLUSE),fermer_aval)==(pav = ouverte & pam = fermee & sas = bas)
END
&
THEORY ListSubstitutionX IS
  Expanded_List_Substitution(Machine(ECLUSE),fermer_aval)==(pav = ouverte & pam = fermee & sas = bas | pav:=fermee);
  Expanded_List_Substitution(Machine(ECLUSE),ouvrir_aval)==(pav = fermee & pam = fermee & sas = bas | pav:=ouverte);
  Expanded_List_Substitution(Machine(ECLUSE),fermer_amont)==(pav = fermee & pam = ouverte & sas = haut | pam:=fermee);
  Expanded_List_Substitution(Machine(ECLUSE),ouvrir_amont)==(pav = fermee & pam = fermee & sas = haut | pam:=ouverte);
  Expanded_List_Substitution(Machine(ECLUSE),vider)==(pav = fermee & pam = fermee | sas:=bas);
  Expanded_List_Substitution(Machine(ECLUSE),remplir)==(pav = fermee & pam = fermee | sas:=haut);
  List_Substitution(Machine(ECLUSE),remplir)==(sas:=haut);
  List_Substitution(Machine(ECLUSE),vider)==(sas:=bas);
  List_Substitution(Machine(ECLUSE),ouvrir_amont)==(pam:=ouverte);
  List_Substitution(Machine(ECLUSE),fermer_amont)==(pam:=fermee);
  List_Substitution(Machine(ECLUSE),ouvrir_aval)==(pav:=ouverte);
  List_Substitution(Machine(ECLUSE),fermer_aval)==(pav:=fermee)
END
&
THEORY ListConstantsX IS
  List_Valuable_Constants(Machine(ECLUSE))==(?);
  Inherited_List_Constants(Machine(ECLUSE))==(?);
  List_Constants(Machine(ECLUSE))==(?)
END
&
THEORY ListSetsX IS
  Set_Definition(Machine(ECLUSE),NIVEAU)==({haut,bas});
  Context_List_Enumerated(Machine(ECLUSE))==(?);
  Context_List_Defered(Machine(ECLUSE))==(?);
  Context_List_Sets(Machine(ECLUSE))==(?);
  List_Valuable_Sets(Machine(ECLUSE))==(?);
  Inherited_List_Enumerated(Machine(ECLUSE))==(?);
  Inherited_List_Defered(Machine(ECLUSE))==(?);
  Inherited_List_Sets(Machine(ECLUSE))==(?);
  List_Enumerated(Machine(ECLUSE))==(NIVEAU,PORTE);
  List_Defered(Machine(ECLUSE))==(?);
  List_Sets(Machine(ECLUSE))==(NIVEAU,PORTE);
  Set_Definition(Machine(ECLUSE),PORTE)==({ouverte,fermee})
END
&
THEORY ListHiddenConstantsX IS
  Abstract_List_HiddenConstants(Machine(ECLUSE))==(?);
  Expanded_List_HiddenConstants(Machine(ECLUSE))==(?);
  List_HiddenConstants(Machine(ECLUSE))==(?);
  External_List_HiddenConstants(Machine(ECLUSE))==(?)
END
&
THEORY ListPropertiesX IS
  Abstract_List_Properties(Machine(ECLUSE))==(btrue);
  Context_List_Properties(Machine(ECLUSE))==(btrue);
  Inherited_List_Properties(Machine(ECLUSE))==(btrue);
  List_Properties(Machine(ECLUSE))==(NIVEAU: FIN(INTEGER) & not(NIVEAU = {}) & PORTE: FIN(INTEGER) & not(PORTE = {}))
END
&
THEORY ListSeenInfoX END
&
THEORY ListANYVarX IS
  List_ANY_Var(Machine(ECLUSE),remplir)==(?);
  List_ANY_Var(Machine(ECLUSE),vider)==(?);
  List_ANY_Var(Machine(ECLUSE),ouvrir_amont)==(?);
  List_ANY_Var(Machine(ECLUSE),fermer_amont)==(?);
  List_ANY_Var(Machine(ECLUSE),ouvrir_aval)==(?);
  List_ANY_Var(Machine(ECLUSE),fermer_aval)==(?)
END
&
THEORY ListOfIdsX IS
  List_Of_Ids(Machine(ECLUSE)) == (NIVEAU,PORTE,haut,bas,ouverte,fermee | ? | pam,pav,sas | ? | remplir,vider,ouvrir_amont,fermer_amont,ouvrir_aval,fermer_aval | ? | ? | ? | ECLUSE);
  List_Of_HiddenCst_Ids(Machine(ECLUSE)) == (? | ?);
  List_Of_VisibleCst_Ids(Machine(ECLUSE)) == (?);
  List_Of_VisibleVar_Ids(Machine(ECLUSE)) == (? | ?);
  List_Of_Ids_SeenBNU(Machine(ECLUSE)) == (?: ?)
END
&
THEORY SetsEnvX IS
  Sets(Machine(ECLUSE)) == (Type(NIVEAU) == Cst(SetOf(etype(NIVEAU,0,1)));Type(PORTE) == Cst(SetOf(etype(PORTE,0,1))))
END
&
THEORY ConstantsEnvX IS
  Constants(Machine(ECLUSE)) == (Type(haut) == Cst(etype(NIVEAU,0,1));Type(bas) == Cst(etype(NIVEAU,0,1));Type(ouverte) == Cst(etype(PORTE,0,1));Type(fermee) == Cst(etype(PORTE,0,1)))
END
&
THEORY VariablesEnvX IS
  Variables(Machine(ECLUSE)) == (Type(pam) == Mvl(etype(PORTE,?,?));Type(pav) == Mvl(etype(PORTE,?,?));Type(sas) == Mvl(etype(NIVEAU,?,?)))
END
&
THEORY OperationsEnvX IS
  Operations(Machine(ECLUSE)) == (Type(fermer_aval) == Cst(No_type,No_type);Type(ouvrir_aval) == Cst(No_type,No_type);Type(fermer_amont) == Cst(No_type,No_type);Type(ouvrir_amont) == Cst(No_type,No_type);Type(vider) == Cst(No_type,No_type);Type(remplir) == Cst(No_type,No_type))
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
