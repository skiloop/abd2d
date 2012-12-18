#ifndef __CONNECTING_H__
#define __CONNECTING_H__

MyDataF *Ei,*Hi;
int eilen,hilen;
MyDataF CMur;
int start_index_x;
int start_index_y;
MyDataF Vp_ratio;//phase velocity ratio
#define INC_SIZE 0
void initconnect()
{
//#ifdef  MATLAB_SIMULATION
//	mxArray *MyArray;
//
//#endif
	int i;
	MyDataF ds;
	MyDataF PhaseVelRatio(MyDataF);
	ds = dx;
	eilen = tpie-tpis+5;
	hilen = eilen - 1;
	start_index_x = -tpis;
	start_index_y = -tpjs;

	CMur = (c*dt-ds)/(c*dt+ds);
	Ei=(MyDataF*)malloc(eilen*sizeof(MyDataF));
	Hi=(MyDataF*)malloc(hilen*sizeof(MyDataF));

	if(Ei==NULL||Hi==NULL){
		exit(EXIT_FAILURE);
	}

	for(i=1;i<eilen;i++)Ei[i]=0;
	for(i=0;i<hilen;i++)Hi[i]=0;
	Ei[0]=E0*Source(0);
//#ifdef  MATLAB_SIMULATION
//	MyArray=mxCreateDoubleMatrix(1,eilen,mxREAL);
//	memcpy(mxGetPr(MyArray), Ei,eilen*sizeof(MyDataF));
//	engPutVariable(ep,"Ei",MyArray);
//	engEvalString(ep,"figure,eih=plot(Ei);grid on;set(gca,'ylim',[-10 10]);");//%surf(data1);");//
//	
//	mxDestroyArray(MyArray);
//#endif


	//calclulate phase velocity ratio
	Vp_ratio = PhaseVelRatio(0)/PhaseVelRatio(phi);

}
void econnect(MyDataF t)
{
//#ifdef  MATLAB_SIMULATION
//	mxArray *MyArray;
//
//#endif
	int i,index,ind;
	int di;

	MyDataF ceihi = dt/eps_0/dx;
	MyDataF ei_last,ei_last2,ds,df,d;

	ds = dx;
	ei_last = Ei[eilen-1];
	ei_last2 = Ei[eilen-2];
	Ei[0]=E0*Source(t);
	for(i=1;i<=eilen-2;i++)
		Ei[i]=Ei[i]+ceihi*(Hi[i]-Hi[i-1]);

	//mur boundary 
	Ei[eilen-1]=ei_last2+CMur*(Ei[eilen-2]-ei_last);
	

//#ifdef  MATLAB_SIMULATION
//	MyArray=mxCreateDoubleMatrix(1,eilen,mxREAL);
//	memcpy(mxGetPr(MyArray), Ei,eilen*sizeof(MyDataF));
//	engPutVariable(ep,"Ei",MyArray);
//	engEvalString(ep,"set(eih,'ydata',Ei);");//surf(data1);");//
//	//engEvalString(ep,"title(ind);ind=ind+1;");
//	mxDestroyArray(MyArray);
//#endif
	for(ind = tpis;ind<=tpie;ind++){
		index = ind*Ez_s.ny;
		//bottom 
		d		=	Dhxb[ind+start_index_x]+0.5;
		di		=	(int)floor(d);
		df		=	d - di;
		Ez_s.data[index+tpjs]+=	Cehz.data[index+tpjs]*Ratio_x*(Hi[di]+df*(Hi[di+1]-Hi[di]))/dy;

		//top
		d		=	Dhxt[ind+start_index_x]+0.5;
		di		=	(int)floor(d);
		df		=	d - di;
		Ez_s.data[index+tpje]-=	Cehz.data[index+tpje]*Ratio_x*(Hi[di]+df*(Hi[di+1]-Hi[di]))/dy;
	}
	//bound xn,xp
	for(ind = tpjs;ind<=tpje;ind++){
		//left side
		index	=	tpis*Ez_s.ny+ind;
		d		=	Dhyl[ind+start_index_y]+0.5;
		di		=	(int)floor(d);
		df		=	d - di;
		Ez_s.data[index]	-=	Cehz.data[index]*(-Ratio_y)*(Hi[di]+df*(Hi[di+1]-Hi[di]))/dx;

		//right side
		index	=	tpie*Ez_s.ny+ind;
		d		=	Dhyr[ind+start_index_y]+0.5;
		di		=	(int)floor(d);
		df		=	d - di;
		Ez_s.data[index]	+=	Cehz.data[index]*(-Ratio_y)*(Hi[di]+df*(Hi[di+1]-Hi[di]))/dx;
	}
}
void mconnect(MyDataF t)
{

	int i,ind;
	MyDataF chiei = dt/mu_0/dx;
	MyDataF hi_last,hi_last2,ds;

	int di;
	MyDataF df;
	//double tmp1;

	ds=dx;
	hi_last = Hi[hilen-1];
	hi_last2 = Hi[hilen-2];
	for(i=0;i<hilen-1;i++)
		Hi[i]=Hi[i]+chiei*(Ei[i+1]-Ei[i]);
	

	//Mur boundary
	Hi[hilen-1]=hi_last2+CMur*(Hi[hilen-2]-hi_last);
	for(ind=tpjs;ind<=tpje;ind++){
		//left side
		di = (int)floor(Dezl[ind+start_index_y]);
		df = Dezl[ind+start_index_y] - di;
		di = di+1;
		Hy_s.data[(tpis-1)*Hy_s.ny+ind]	-=	Chyez*(Ei[di]+df*(Ei[di+1]-Ei[di]));//0;//
		//right side
		di = (int)floor(Dezr[ind+start_index_y]);
		df = Dezr[ind+start_index_y] - di;
		di = di+1;
		Hy_s.data[tpie*Hy_s.ny+ind]		+=	Chyez*(Ei[di]+df*(Ei[di+1]-Ei[di]));
	}
	//Adjust Hy
	for(ind=tpis;ind<=tpie;ind++){
		// bottom
		di = (int)floor(Dezb[ind+start_index_x]);
		df = Dezb[ind+start_index_x] - di;
		di = di+1;
		//if(ind==tpis){
		//	tmp1 = Ei[di]+df*(Ei[di+1]-Ei[di]);
		//	printf("tmp1= %lf\n",tmp1);
		//	tmp1;
		//}

		Hx_s.data[ind*Hx_s.ny+tpjs-1]	-=	Chxez*(Ei[di]+df*(Ei[di+1]-Ei[di]));
		//yp
		di = (int)floor(Dezt[ind+start_index_x]);
		df = Dezt[ind+start_index_x] - di;
		di = di+1;
		Hx_s.data[ind*Hx_s.ny+tpje]		+=	Chxez*(Ei[di]+df*(Ei[di+1]-Ei[di]));
	}

}
void end_connect()
{
	free(Ei);
	free(Hi);
}

MyDataF PhaseVelRatio(MyDataF angle)
{
	MyDataF A,B,C,S,k,N,kp;

	N = lamda/dx;
	S = c*dt/dx;
	A = 0.5*dx*cos(angle);
	B = 0.5*dx*sin(angle);
	C = sin(M_PI*S/N)*sin(M_PI*S/N)/S/S;

	k=0.5;kp=1;
	while(fabs(k-kp)>1e-4)
	{
		kp=k;
		k=kp-(sin(A*kp)*sin(A*kp)+sin(B*kp)*sin(B*kp)-C)/(A*sin(2*A*kp)+B*sin(2*B*kp));
	}

	return 2*M_PI*c/k;
}
#endif
