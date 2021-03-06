% filename : nom d'un fichier .wav
% Rem: si filename  = ""      => generation par defaut d'une sinusoide
% N : nb d'echantillons par trame
% T:  nb de trame � g�n�rer
% F0:  frequence de la sinusoide  F0<1/2 (freq. normalis�e)
% F0 non utilis�e qd  'filename' non vide

function[msg,X]=generation_tableau_trames(filename,N,T,F0)
name = filename;
[fid,msg] = fopen(name,'rb','l');   % Little-endian
if fid == -1,
	msg = 'Pb ouverture du fichier';
end
if ~isempty(msg)
   msg ='Generation par defaut d''un signal sinusoidal';
   % Attention F0<1/2 pour Shannon
   sig_sin=sin(2*pi*(1:1:N*T)*F0);
   plot(sig_sin);
    % Conversion du signal en T trames ind�pendantes
   for j =1:T
        X(j,:)=sig_sin((j-1)*N+1:j*N);
   end
else
   msg =['ouverture du fichier:' filename];
   sig= wavread(filename , N*T);
   %plot(sig);
    % Conversion du signal en T trames ind�pendantes
   for j =1:T
        X(j,:)=sig((j-1)*N+1:j*N);
   end
end


