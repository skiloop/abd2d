
#ifndef INIT_COMMOM_DATA_INCLUDE
#define INIT_COMMOM_DATA_INCLUDE
#include"common_data.h"
int first,second,third;
void InitComData(){
/////////////////////////////////////
//SET COMMOM DATA ZERO
//////////////////////////////////////
	De=0;
	Da=0;
	mu_e=0;
	mu_i=0;
	vi=va=0;
	kasi=0;
	alpha=0;
	rei=0;


//FDTD DATA
	dt=dt_F=dt_M=0;
	ds_F=ds_M=0;
	dx=0;
	dy=0;
	m=n=0;

//DOMAIN DATA
    nx=nxp1=nxm1=0;
    ny=nyp1=nym1=0;
    nbound=0;

//PARAMETERS OF INCIDENT WAVE
	f=0;//frequency
	k=0;
	E0=H0=0;
	Hx0=Hz0=Hy0=Ez0=Ex0=Ey0=0;
	lamda=0;
	omega=0;
//////////////////////////////////////////////
///END OF SET COMMON DATA ZERO
//////////////////////////////////////////////

	mu_e	= e/me/vm;//3.7e-2;
	mu_i	= 8.73e-2;//mu_e/100.0;//mu_e/mu_i ranges from 100 to 200
	De		= mu_e*2*1.6021e-19/e;//
	Da		= De*mu_i/mu_e;
	vi		= 5.4e9;
	va		= 1.6e9;
	kasi	= 0;
	rei		= 0;//2.2e-13;
	D_kasi_max = (Da > De ? Da :De);
	
	f		= FREQUENCY;
	lamda	= c/f;
	E0		= E_0;
	H0		= E0*sqrt(eps_0/mu_0);
	k		= omega/c;
	T		= 1/f;
	nbound  = NUMBER_OF_CELLS_IN_PML_BOUND;
	omega	= 2*M_PI*f;

	Ratio_x = sin(phi);//sin(0.5*M_PI);
	Ratio_y = -cos(phi);//cos(0.5*M_PI);
	if(IsTMx){
		Ex0=Ratio_x*E0;
		Hz0=H0;
		Ey0=Ratio_y*E0;
	}
	if(IsTEx){
		Hx0=Ratio_x*H0;
		Hy0=Ratio_y*H0;
		Ez0=E0;
	}

	dx=dy=lamda*MAXWELL_MESH_SIZE;//
	dt_M=dt=0.5*dx/c;//CourantFactor/c/sqrt(1/dx/dx+1/dy/dy+2.8e-13*M_PI*1e9);//
	//if(dt>1.0/12.0/f)dt=1.0/12.0/f;
	m = FINE_GRID_SIZE;
	TotalTimeStep = (int)(0.5+TOTAL_TIME/dt);
	ds_M = dx;
	ds_F = ds_M/m;
	dt_F = T;//CFL_factor*ds_F*ds_F*0.5/D_kasi_max;
	half_dt = dt/2;

	
	/*if(dt_F*1000<dt_M||dt_F>dt_M)
		dt_F = dt_M/m;*/
	printf("\nT\t=\t%5.4e ns\nf\t=\t%-11lf GHz\n",T/1e-9,f/1e9);
	printf("lamda\t=\t%5.4e mm\nomega\t=\t%5.4e rad/s\n",lamda/1e-3,omega);
	printf("dx\t=\t%5.4e mm\ndt\t=\t%5.4e ns\n",dx/1e-3,dt/1e-9);
	printf("\ndt_M\t=\t%5.4e ns\ndt_F\t=\t%5.4e ns\n",dt_M/1e-9,dt_F/1e-9);
	printf("ds_M\t=\t%5.4e mm\nds_F\t=\t%5.4e mm\n",ds_M/1e-3,ds_F/1e-3);
	printf("Ratio_x\t=\t%5.4e\nRatio_y\t=\t%5.4e\n",Ratio_x,Ratio_y);
	printf("\ndt_F/dt\t\t:\t%d\n",(int)(0.5+dt_F/dt));
	printf("PML size\t:\t%d\n",nbound);
	printf("Fine Mesh Grid\t:\t%d\n",m);
	printf("Total propagating time\t:\t%f ns\n",TOTAL_TIME/1E-9);
	printf("\n*************************************************************\n");
	//system("pause");

}
#endif
