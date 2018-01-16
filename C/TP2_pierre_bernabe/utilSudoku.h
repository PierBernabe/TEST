int lireSudoku(FILE *fich,int sudoku[9][9]);
int ecrireSudoku(FILE *fich,int sudoku[9][9]);
int verifLigne(int sudoku[9][9]);
int verifCol(int sudoku[9][9]);
int verifCas(int sudoku[9][9]);
int sudokuValide(int sudoku[9][9]);
void interdireValeur(int val,int lin,int col,int sudoku2[9][9][9]);
void initInterdiction(int sudoku[9][9],int sudoku2[9][9][9]);
void sudokuFacil(int sudoku[9][9]);
void afficheInterdiction(int sudoku2[9][9][9]);
void afficheSudoku(int sudoku[9][9]);

