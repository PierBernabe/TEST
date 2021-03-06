%***********************************************************************
% output: Trame filtr�e de Nx echantillons
% pre_input:  Trame � filtrer de Nx+Nh-1 echantillons 
%         (trame courante  concat�n�e avec un pr�fixe correspondant aux
%         derniers �chantillons de la trame pr�c�dente)
% pre_output:  Trame de sortie de Nx+Nh-1 echantillons 
%         (trame de sortie concat�n�e avec un pr�fixe correspondant aux
%         derniers �chantillons de la trame de sortie pr�c�dente)
% a: coefficients du Denominateur
% b: coefficients du Numerateur
% Nx: Nb �chantillons de la trame de sortie
% Nh: nb de coef (egal au num et au den)
%*************************************************************************



function[output]= Eq_diff_IIR(pre_input,pre_output,b,a,Nx,Nh)
    sum=0;
    for i=(1:Nx)
        sum = b(1)*pre_input(i+Nh-1);
        for k=(2:Nh)
            % Attention a[1]=1 par convention
            sum = sum + b(k)*pre_input(i+Nh-k) - a(k)*pre_output(i+Nh-k);
            
        end
        pre_output(i+Nh-1)= sum /a(1);  % en fait, a(1) est choisi pour �tre egal � 1
        output(i)= sum /a(1);          % en fait, a(1) est choisi pour �tre egal � 1
        
        % Shift de Nh-1 echantillons pour Nh'echantillon courant, du fait du
        % prefixe
    end

