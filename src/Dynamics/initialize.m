%% Fixed Simulation Problem
clear all, close all, clc

% Constants
g = 9.81; % Gravity constant

% Box Dimensions
t1 = 0.2; % height of box 1 (m)
l1 = 0.3; % lenght of box 1 (m)
w1 = 0.2; % widht of box 1 (m)

t2 = 0.12; % height of box 2 (m)
l2 = 0.1; % lenght of box 2 (m)
w2 = 0.15; % widht of box 2 (m)

% Box Weights
m1 = 4;   % Mass of box 1 (big box) (kg)
m2 = 1.4;   % Mass of box 2 (little box) (kg)
m3 = 0; % Mass of the stick (kg) --> Distributed in m1 and m2

% Rotational Friction (viscosity)
Br = 2; % Rotational Friction constant

% Parameters needed:

% Variables to control
theta = 0; % Angle to stabilize the system ---------

% IT SHOULD BE ON f(x)
l3o = 0.15; % Initial linear actuator lenght (m)
l3f = l3o + 0.15; % Max lenght of linear actuator (m)
l2f = (l1 + l2)/2 + l3f + l3o; % Max distance from rotation to c.g box 2(m)                   

% Gravity forces
F1 = -m1 * g;
F2 = -m2 * g;
F3 = -m3 * g;

% Inertia for the axis of rotation
I1 = (m1 * (t1^2 + l1^2))/12; % Rotational inertia of box 1 [Kg*m^2]
I2 = (m2 * (t2^2 + l2^2))/12 + (m2 * (l2f)^2) ; % Rotational inertia of box 2 [Kg*m^2]
 
% Inertia constant an the final point of the actuator extension
I = I1 + I2; % Rotational Inertia

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simple model (l2c variable but I constant)
% Matrices Definition
A = [0 1 ; 0 -Br/I]; 
B = [0 0 ; F2/I 1];
B = [0 ;1];
%B = [B(:,2)];

C = [1 0];
D = 0;
 
eig(A);

% Number of states 
n = length(A);

% Output matrix

x0 = [pi/4;0]; % Initial conditions
u0 = [-m2*g*(l2f+l3o-l3f)] % Initial Input

% LQR
Q = eye(size(C,1))*1;
%Q(1,1) = 1e-6;
%Q(2,2) = 1e-6;
%Q = C'*C;
R = 1;
K = lqr(A,B,Q,R);

% Closed loop system
Ac = [(A-B*K)];
Bc = [B];
Cc = [C];
Dc = [D];

eig(Ac);

sys_cl = ss(Ac,Bc,Cc,Dc);

















