cxclose all; 
%% *************************************************************************
 % Evaluer la meilleur valeur de N et L  (N=2^P et  N=L+M-1...
 M=32;                  % taille du filtre
 N=64;%128;             % taille de la FFT
 L=N-M+1;%124;          % taille de la trame d'echantillons de x
 h=1/M*ones(1,M);
 Nx=10*L;               % taille totale du signal, par souci de simplification Nx multiple de la taille des trames...

 
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Implantation  FIR FFT OLA 
 y1= zeros(1,???);    % initialisation du signal de sortie total
 [msg,x]=generation_tableau_trames('',Nx,1,5/Nx); 
 %[msg,x]=generation_tableau_trames('',Nx,1,0.005); 
 
   H= ???(h,???) ;    %  (zero-padded FFT)
   i = 1;
   while i < Nx
       il = min(i+L-1,Nx);   
       X=???(x(i:???),???);
       yt = ???( ??? .* ???, ???);       % trame de sortie de taille N donc debordement sur la trame suivante
       k  = i + N - 1;
       y1(i:k) = y1(i:k) + ???;         % addition des blocs de sortie qui se superposent sur M-1 valeurs
       i = i+L;
   end

   figure(1)
   xmin=0; xmax=Nx+M-1;
   subplot(3,1,1) ; plot(x);   xlim([xmin xmax]);          title('Input Signal x');
   subplot(3,1,2) ; plot(y1(1:Nx+M-1)); xlim([xmin xmax]); title('y1 Output Signal FFT OLA');
   subplot(3,1,3) ; stem(h); xlim([xmin xmax]);            title('Impulse Response h');

 
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Implantation  FIR OLA en temporel
   y2= zeros(1,???);
   i = 1;
   
   while i < Nx
       il = min(i+L-1,Nx);
       xt2 = x(i:???);
       yt2 = ???(???,???);
       k  = i + (L+M-1) - 1;
       y2(i:k) = y2(i:k) + ???;   % (add the overlapped output blocks)
       i = i+L;
   end
   figure(2)
   subplot(3,1,1) ; plot(x);  xlim([xmin xmax]);            title('Input Signal x');
   subplot(3,1,3) ; plot(y2(1:Nx+M-1)); xlim([xmin xmax]);  title('y2 Output Signal CONV OLA');
   subplot(3,1,2) ; plot(y1(1:Nx+M-1)); xlim([xmin xmax]);  title('y1 Output Signal FFT OLA');
    
%%   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Comparaison des r�sultats
   figure(3)
   
   subplot(4,1,1) ;  plot(x(1:Nx)); xlim([xmin xmax]);       title('x input signal ');
   subplot(4,1,2) ;  plot(y1(1:Nx+M-1)); xlim([xmin xmax]);  title('y1 output signal : FFT OLA');
   subplot(4,1,3) ;  plot(y2(1: Nx+M-1)); xlim([xmin xmax]); title('y2 Output Signal, CONV OLA');
   z=filter(???,???,???);
   subplot(4,1,4) ;  plot(z);  xlim([xmin xmax]);            title('z Output Signal, fonction filter sur le signal entier');