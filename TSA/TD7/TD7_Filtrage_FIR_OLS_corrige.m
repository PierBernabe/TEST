clear;
close all;

Nx=64     % Nb d'echantillons d'entr�e par trame 
Nh=11     % Nb de coef FIR
T=20      % Nb de trames a g�n�rer pour le signal d'entr�e

%% NOMS des VARIABLES ************************************************************************
% trame d'entree avec pr�fixe: input 
% trame d'entr�e :  X
% trame de sortie (filtr�e FIR): Y
% *************************************************************************
%%

%% *************************************************************************
% Definition des coeff du filtre:
%%
% filtre passe bas, FDATool FIR Window Hamming , wc=0.2 ,  11 coef
h= [0.0000    0.0093    0.0476    0.1224    0.2022    0.2370    0.2022    0.1224 0.0476    0.0093    0.0000]
%% *************************************************************************
% Generation d'un tableau de T trames
% *************************************************************************
% Pour tester avec une sin => decommenter la ligne voulue
% param�tre F0 = frequence de la sinusoide, en frequence normalis�e
% Attention FDATool consid�re que 1 correspond � Fe/2 alors qu'ici 1
% correspond � Fe.
% F0 doit �tre choisi tq :  0< F0 < 0.5 autrement dit F0 ne peut pas
% d�passer Fe/2 (Merci Mr Shannon !!!)
[msg,X]=generation_tableau_trames('',Nx,T,0.05);  % Sin BF dans la bande passante
%[msg,X]=generation_tableau_trames('',Nx,T,0.1);   % Sin BF � la frequence de coupure
%[msg,X]=generation_tableau_trames('',Nx,T,0.2);   % Sin HF dans la bande att�nu�e

%%
% *************************************************************************
% Resultat de la convolution : vecteur de Nx+Nh-1 echantillons
% Nh-1 echantillons au d�part correspondant a la phase transitoire
% => Obligation de rallonger artificiellement la trame � filtrer en
% rajoutant Nh-1 �chantillons au debut =>  Gestion du prefixe 
% Signal d'entr�e avec prefixe  : input (= trame d'entr�e avec pr�fixe)
% trame d'entr�e :  X
% trame de sortie : Y
% *************************************************************************

% Traitement particulier de la 1ere trame 
% Pas de trame precedente => on met arbitrairement les echantillons du
% prefixe � 0
prefixe=zeros(1,Nh-1);
input(1,:)=[prefixe  X(1,:)];

% *************************************************************************
% FILTRAGE FIR 
% filtre FIR:  Appel d'une fonction de convolution
% **h= [0.0000    0.0093    0.0476    0.1224    0.2022    0.2370    0.2022    0.1224 0.0476    0.0093    0.0000]
%***********************************************************************
for j=(1:T) % j : index de la trame en cours de traitement
    Y(j,:)=convolution_FIR(input(j,:),h,Nx,Nh);
    %Gestion du prefixe: on recopie les (Nh-1) derniers echantillons de la trame
    % �tendue (avec le pr�fixe) apres le filtrage...
    % !!! attention � la difference de gestion des indices des tableaux 
    % entre Matlab et langage C  (increment de 1 pour Matlab par rapport au C)
    if (j<T)
        input(j+1,:)=[input(j,Nx+1:Nx+Nh-1) X(j+1,:)];
    end;
end

%% Verification effet du filtrage
% comparaison signal d'entr�e et de sortie
sig_Y=[]
sig_X=[]
for j=(1:T)
    sig_Y=[sig_Y Y(j,:)];
    sig_X=[sig_X X(j,:)];
end
    subplot(3,1,1) ; plot(sig_X);title('Input Signal');
    subplot(3,1,2) ; plot(sig_Y);title('Output Signal');
    subplot(3,1,3) ; stem(h);title('Impulse Response');
    
   
figure
freqz(h,1);    title('Frequency Response');
% Spectre du signal d'origine
figure; 
subplot(2,1,1) ;plot((0:1:Nx-1)*1/Nx, abs(fft(sig_X,Nx)));title('Spectre Input Signal');
subplot(2,1,2) ;plot((0:1:Nx-1)*1/Nx, abs(fft(sig_Y,Nx)));title('Spectre Output Signal');

