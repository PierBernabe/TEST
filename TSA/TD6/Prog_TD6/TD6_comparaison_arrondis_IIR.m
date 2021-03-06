% Mise en �vidence des Pb d'arrondis sur filtre IIR, m�thode OLS
clear;
close all;
Nx=48     % Nb d'echantillons par trame 
T=20      % Nb de trames
Nh=11      % Nb de coef IIR => ordre Nh


% ************************************************************************
% trame d'entree avec pr�fixe: input 
% trame de sortie avec pr�fixe: output (attention ne gere que le pr�fixe) 
% trame d'entr�e :  X
% trame de sortie (filtr�e IIR): Y
% *************************************************************************

% *************************************************************************
% Definition des coeff du filtre
% *************************************************************************
% *************************************************************************
% Test des filtres AR du TP DSP IIR_coeff.h  
% des projets IIR_trame et IIR_non_trame
% *************************************************************************

% coefficients arrondis avec 5 chiffres significatifs
b_arro =   1.0e-003 *[ 0.0017  0.0168    0.0758    0.2020    0.3536    0.4243    0.3536  0.2020    0.0758    0.0168    0.0017];
a_arro= [1.0000     -5.9876     16.6722    -22.2588      32.1598  -25.6017   14.4057  -5.6471    1.4737  -0.2309    0.0165];

% coefficients arrondis avec 8 chiffres significatifs
b_arro_1 =   1.0e-003 *[ 0.0016835  0.016835    0.075761    0.202029    0.353552    0.424262    0.35355  0.202029    0.075761    0.016835    0.0016835];
a_arro_1= [1.0000     -5.987589     16.672193    -22.258787      32.159756  -25.601749   14.405687  -5.647074    1.473727  -0.230919    0.016479];

% avec export dans un fichier Header C=> Pr�cision double flottant, OK
b_reel=[1.683581407233e-006, 1.683581407233e-005, 7.576116332548e-005, 0.000202029768868, 0.0003535520955189, 0.0004242625146227, 0.0003535520955189, 0.000202029768868,  7.576116332548e-005, 1.683581407233e-005, 1.683581407233e-006]
a_reel=[ 1,   -5.987589629817,      16.672193323,    -28.2587879002,       32.15975648769,   -25.60174959705,    14.40568742621,   -5.647074344132, 1.473727936974,   -0.230919345862,  0.01647963054713]

%%
a=a_reel;    % initialisation des coeff IIR
b=b_reel;

%% *************************************************************************
% Generation d'un tableau de T trames
% Si pas de fichier wav, par defaut genration d'un signa sinusoidal 
% *************************************************************************
% Pour choisir le fr�quence du sin => decommenter la ligne voulue
% param�tre F0 = frequence de la sinusoide, en frequence normalis�e
% Attention FDATool consid�re que 1 correspond � Fe/2 alors qu'ici 1
% correspond � Fe.
% F0 doit �tre choisi tq :  0< F0 < 0.5 autrement dit F0 ne peut pas
% d�passer Fe/2 (Merci Mr Shannon !!!)
[msg,X]=generation_tableau_trames('',Nx,T,0.05);   % Sin BF dans la bande passante
%[msg,X]=generation_tableau_trames('',Nx,T,0.1);   % Sin BF � la frequence de coupure
%[msg,X]=generation_tableau_trames('',Nx,T,0.2);   % Sin HF dans la bande att�nu�e

%% *************************************************************************
% IIR r�gi par une equation aux differences : 
% Besoin de connaitre les Nh-1 echantillons pr�cedentes de l'entr�e et 
%                     les Nh-1 echantillons de la sortie
% 
% => Obligation de concat�ner les Nh-1 derniers �chantillons de la trame d'entr�e precedente au debut 
%      � la trame � filtrer   =>  Gestion du prefixe  (prefixe_X)
%    trame resultante : input
% => Obligation de concat�ner  les Nh-1 derniers �chantillons de la trame de sortie precedente au debut 
%      � la trame de sortie suivante   =>  Gestion du prefixe (prefixe_Y)
%    trame resultante : output (attention, contrairement au programme C,
%    output ne gere que le prefixe et Nx'est pas mis � jour par les
%    echantillons de sortie du filtrage...
% *************************************************************************
%
%% Traitement particulier des 1ere trames d'entr�e et de sortie (pas de trame precedente, on met les
% echantillons du prefixe � 0)
prefixe_X=zeros(1,Nh-1);
input(1,:)=[prefixe_X  X(1,:)];
output(1,:)=[prefixe_X  zeros(1,Nx)];

%%

%% *************************************************************************
% FILTRAGE IIR 
% filtre IIR:  Implantation de l'equation aux differences 
%   y[Nx]= b1 x[Nx] + .. + bm x[Nx-m] - a2 y[Nx-1] + .. + am y[Nx-m]
% *************************************************************************
for j=(1:T)
    Y(j,:)=Eq_diff_IIR(input(j,:),output(j,:),b,a,Nx,Nh);
    % mise � jour de la trame de sortie suivante avec le pr�fixe constitu� des derniers echantillons de la trame de sortie 
    if (j<T)
        prefixe_X = input(j, Nx+1 : Nx+Nh-1)    % prefixe pour la trame d'entr�e
        input(j+1,:)=[prefixe_X   X(j+1,:)];
        prefixe_Y = Y( j , Nx-(Nh-1)+1:Nx );    % prefixe pour la trame de sortie
        output(j+1,:)=[prefixe_Y   zeros(1,Nx)];
         % !!! attention � la difference de gestion des indices des tableaux 
         % entre Matlab et langage C  (increment de 1 pour Matlab par rapport au C)
     end
end

%% Verification effet du filtrage
% comparaison signal d'entr�e et de sortie
sig_Y = []
sig_X = []
for j=(1:T)
    sig_Y=[sig_Y Y(j,:)];
    sig_X=[sig_X X(j,:)];
end

figure
subplot(2,1,1) ; plot((1:1:Nx*T)/Nx,sig_X);   title('Input Signal');
subplot(2,1,2) ; plot((1:1:Nx*T)/Nx,sig_Y);   title('Output Signal');

figure;
freqz(b,a);         title('Frequency Response');
figure
[h,t]=impz(b,a);     
plot(t,h);          title('Impulse Response');
% Spectre du signal d'origine
figure;
subplot(2,1,1) ;plot((0:1:Nx-1)*1/Nx, abs(fft(sig_X,Nx)));title('Spectre Input Signal');
subplot(2,1,2) ;plot((0:1:Nx-1)*1/Nx, abs(fft(sig_Y,Nx)));title('Spectre Output Signal');

