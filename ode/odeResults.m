%% k	x	yEuler(1)	yIEuler(1)	yRKutta(1)	yEuler(2)	yIEuler(2)	yRKutta(2)	yAnalytic	
ode_data=[
0	1	1	0	0	1	0	0	0.454649	
1	1.1	1.1	0	0	0.6	0	0	0.404248	
2	1.2	1.16	0	0	0.16	0	0	0.337732	
3	1.3	1.176	0	0	-0.304	0	0	0.257751	
4	1.4	1.1456	0	0	-0.7744	0	0	0.167494	
5	1.5	1.06816	0	0	-1.23264	0	0	0.07056	
6	1.6	0.944896	0	0	-1.6599	0	0	-0.0291871	
7	1.7	0.778906	0	0	-2.03786	0	0	-0.127771	
8	1.8	0.575119	0	0	-2.34942	0	0	-0.22126	
9	1.9	0.340177	0	0	-2.57947	0	0	-0.305929	
10	2	0.0822297	0	0	-2.71554	0	0	-0.378401	
11	2.1	-0.189325	0	0	-2.74844	0	0	-0.435788	
12	2.2	-0.464168	0	0	-2.67271	0	0	-0.475801	
13	2.3	-0.731439	0	0	-2.48704	0	0	-0.496846	
14	2.4	-0.980142	0	0	-2.19446	0	0	-0.498082	
15	2.5	-1.19959	0	0	-1.80241	0	0	-0.479462	
16	2.6	-1.37983	0	0	-1.32257	0	0	-0.441727	
17	2.7	-1.51209	0	0	-0.770638	0	0	-0.386382	
18	2.8	-1.58915	0	0	-0.165804	0	0	-0.315633	
19	2.9	-1.60573	0	0	0.469856	0	0	-0.232301	
20	3	-1.55874	0	0	1.11215	0	0	-0.139708	
];
figure(1);
plot(ode_data(:,2),ode_data(:,3),ode_data(:,2),ode_data(:,4),ode_data(:,2),ode_data(:,5),ode_data(:,2),ode_data(:,9));
legend('yEuler','yIEuler','yRKutta','yAnalytic','Location','Best');
xlabel('x');
ylabel('y');
title({'Solution to d2ydx2+a^2y = 0 where a = 2', 'y(1)=( 1 1 )', 'h=0.1, n=20'});
figure(2);
plot(ode_data(:,2),ode_data(:,3)-ode_data(:,9),ode_data(:,2),ode_data(:,4)-ode_data(:,9),ode_data(:,2),ode_data(:,5)-ode_data(:,9));
legend('Euler','IEuler','RKutta','Location','Best');
xlabel('x');
ylabel('Error');
title({'Error in solution to d2ydx2+a^2y = 0 where a = 2', 'y(1)=( 1 1 )', 'h=0.1, n=20'});