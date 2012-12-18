#ifndef __SOURCE_H__
#define __SOURCE_H__
//Delay of time comparing with posistion tpis
//'D' for delay;
//'ez' for electric field Ez;
//'hx' 'hy' for magnetic field Hx and Hy
//'t' for top;'b' for bottom; 'l' for left;'r' for right
//Ez Hx has delay arrays  

//Hx Delay
MyDataF *Dhyl,*Dhyr;
//Hy Delay
MyDataF *Dhxb,*Dhxt;
//Ez Delay
MyDataF *Dezb,*Dezt,*Dezl,*Dezr;

MyDataF cos_phi,sin_phi;
MyDataF t_per_cell; //time wave propagtes per Yee cell
int xs,ys,xe,ye;//


void CalDelays()
{
	int i;
	int Max_Index_Dez_x;
	int Max_Index_Dez_y;

	int Max_Index_Dhx;
	int Max_Index_Dhy;

	//FILE *fp1,*fp2;
	MyDataF delays(MyDataF px,MyDataF py);
	
	
	t_per_cell = dx/c;
	cos_phi=cos(phi);
	sin_phi=sin(phi);

	phi = phi-2*M_PI*(floor(phi/(2*M_PI)));
	if((phi<=0.5*M_PI)){
		xs = tpis;		ys = tpjs;
		xe = tpie;		ye = tpje;
	}else if((phi<=M_PI)){
		xs = tpie;		ys = tpjs;
		xe = tpis;		ye = tpje;
	}else if((phi<=1.5*M_PI)){
		xs = tpie;		ys = tpje;
		xe = tpis;		ye = tpjs;
	}else {
		xs = tpis;		ys = tpje;
		xe = tpie;		ye = tpjs;
	}

	Max_Index_Dhx = Max_Index_Dez_x = abs(xe-xs);
	Max_Index_Dhy = Max_Index_Dez_y = abs(ye-ys);

	Dhxb = (MyDataF*)malloc((Max_Index_Dhx+1)*sizeof(MyDataF));
	Dhxt = (MyDataF*)malloc((Max_Index_Dhx+1)*sizeof(MyDataF));
	if(Dhxb==NULL||Dhxt==NULL){
		printf("Cannot allocate enough memmory for Dhx!\n");
		exit(EXIT_FAILURE);
	}
	Dhyl = (MyDataF*)malloc((Max_Index_Dhy+1)*sizeof(MyDataF));
	Dhyr = (MyDataF*)malloc((Max_Index_Dhy+1)*sizeof(MyDataF));
	if(Dhyl==NULL||Dhyr==NULL){
		printf("Cannot allocate enough memmory for Dhy!\n");
		exit(EXIT_FAILURE);
	}

	Dezb = (MyDataF*)malloc((Max_Index_Dez_x+1)*sizeof(MyDataF));
	Dezt = (MyDataF*)malloc((Max_Index_Dez_x+1)*sizeof(MyDataF));
	Dezl = (MyDataF*)malloc((Max_Index_Dez_y+1)*sizeof(MyDataF));
	Dezr = (MyDataF*)malloc((Max_Index_Dez_y+1)*sizeof(MyDataF));

	if(Dezt==NULL||Dezb==NULL||Dezl==NULL||Dezr==NULL){
		printf("Cannot allocate enough memmory for Dez!\n");
		exit(EXIT_FAILURE);
	}

	
	for(i=0;i<=Max_Index_Dhx;i++)
	{
		Dhxb[i]=delays(tpis+i,tpjs-0.5);
		Dhxt[i]=delays(tpis+i,tpje+0.5);
	}
	for(i=0;i<=Max_Index_Dhy;i++)
	{
		Dhyl[i]=delays(tpis-0.5,tpjs+i);
		Dhyr[i]=delays(tpie+0.5,tpjs+i);
	}
	for(i=0;i<=Max_Index_Dez_x;i++){
		Dezb[i]=delays(tpis+i,tpjs);
		Dezt[i]=delays(tpis+i,tpje);
	}
	for(i=0;i<=Max_Index_Dez_y;i++){
		Dezl[i]=delays(tpis,tpjs+i);
		Dezr[i]=delays(tpie,tpjs+i);
	}

	////save delays
	//fp1=fopen("dhxb.dat","w");
	//fp2=fopen("dhxt.dat","w");
	//for(i=0;i<=Max_Index_Dhx;i++)
	//{
	//	fprintf(fp1,"%12.10e\t",Dhxb[i]);
	//	fprintf(fp2,"%12.10e\t",Dhxt[i]);
	//}
	//fclose(fp1);
	//fclose(fp2);


	//fp1=fopen("dhyl.dat","w");
	//fp2=fopen("dhyr.dat","w");
	//for(i=0;i<=Max_Index_Dhy;i++)
	//{
	//	fprintf(fp1,"%12.10e\t",Dhyl[i]);
	//	fprintf(fp2,"%12.10e\t",Dhyr[i]);
	//}
	//fclose(fp1);fclose(fp2);
	//
	//fp1=fopen("dezb.dat","w");
	//fp2=fopen("dezt.dat","w");
	//for(i=0;i<=Max_Index_Dez_x;i++){
	//	fprintf(fp1,"%12.10e\t",Dezb[i]);
	//	fprintf(fp2,"%12.10e\t",Dezt[i]);
	//}
	//fclose(fp1);fclose(fp2);
	//
	//
	//fp1=fopen("dezl.dat","w");
	//fp2=fopen("dezr.dat","w");
	//for(i=0;i<=Max_Index_Dez_y;i++){
	//	fprintf(fp1,"%12.10e\t",Dezl[i]);
	//	fprintf(fp2,"%12.10e\t",Dezr[i]);
	//}
	//fclose(fp1);fclose(fp2);
	

}
MyDataF Source(MyDataF t)
{
//	MyDataF t_0;
//	MyDataF tau = 3.1E-9;
//	t_0 =  0.8*tau;//dt*ttstep/10;//||t>1000*dt
	//
	if(t<0)return 0;
	return cos(omega*t);//-cos(2*M_PI*f*t)*exp(-4*M_PI*pow((t-t_0)/tau,2));//1;//
	//return 0;1.0;
}

void InitFields()
{
	//Init Fields at t = 0;
	int j;
	for(j=tpjs;j<=tpje;j++)
		Ez_s.data[tpis*Ez_s.ny+j] = Ez0*sin(omega*CurTime);
}
//
MyDataF delays(MyDataF px,MyDataF py)
{
	return ((px-xs)*cos_phi+(py-ys)*sin_phi);
}
void AddEInc(MyDataF t)
{
	int i;
	for(i=tpis;i<=tpie;i++)
	{
		Ez_s.data[i*Ez_s.ny+tpjs]=E0*Source(t-Dezb[i-tpis]*t_per_cell);
		Ez_s.data[i*Ez_s.ny+tpje]=E0*Source(t-Dezt[i-tpis]*t_per_cell);
	}
	for(i=tpjs+1;i<tpje;i++)
	{
		Ez_s.data[tpis*Ez_s.ny+i]=E0*Source(t-Dezl[i-tpjs]*t_per_cell);
		Ez_s.data[tpie*Ez_s.ny+i]=E0*Source(t-Dezr[i-tpjs]*t_per_cell);
	}
}
void FreeDelayArrays()
{
	free(Dezb);
	free(Dezt);
	free(Dezl);
	free(Dezr);

	free(Dhxb);
	free(Dhxt);
	free(Dhyl);
	free(Dhyr);
}

#endif