%***********************************************************************
% output: Trame filtr�e de Nx echantillons
% input:  Trame � filtrer de Nx+Nh-1 echantillons 
%         (trame courante  concat�n�e avec un pr�fixe correspondant aux
%         derniers �chantillons de la trame pr�c�dente)
% h: coefficients du filtre FIR
% Nx: Nb �chantillons de la trame de sortie
% Nh: nb de coef du filtre
%*************************************************************************

function[output]= convolution_FIR(input,h,Nx,Nh)
for i=(1:Nx)
    sum=0;
    for k=(1:Nh)
        sum=sum+h(k)*input(i+Nh-k);
        % Shift de Nh-1 echantillons pour Nh'echantillon courant, du fait du prefixe
    end
    output(i)=sum;
end