/*
*		This file defines functions that update scatter fields.
*
*
*
*
*/

///////////////////////////////
//formation 3
///////////////////////////////

void UpdateEField(){

	//created 2011.03.23 21.20
	//changed at 03.35 11:39
	//Details: changed to only the E fields in domain are updated,
	//			with those in bondaries egnored.
	int i,j,index;
	int indx,indy;
	//MyDataF Eztmp;
	if(IsTMx){
		BackupMyStruct(Ex_s,Ex_s_pre);
		BackupMyStruct(Ey_s,Ey_s_pre);
		for(i=0;i<Ex_s.nx;i++)
			for(j=pjs+1;j<pje;j++){
				index = i*Hz_s.ny+j;
				indx=i*Ex_s.ny+j;
				Ex_s.data[indx]=Ceex.data[indx]*(Ex_s_pre.data[indx])+
					Cevx.data[indx]*Vex.data[indx]+Cehx.data[indx]*
					(Hz_s.data[index]-Hz_s.data[index-1])/dy;
			}
		for(i=1+pis;i<pie;i++)
			for(j=0;j<Ey_s.ny-1;j++){
				indy = i*Ey_s.ny+j;
				index= i*Hz_s.ny+j;
				Ey_s.data[indy]=Ceey.data[indy]*(Ey_s_pre.data[indy])
					+Cevy.data[indy]*Vey.data[indy]+Cehy.data[indy]*
					(Hz_s.data[index]-Hz_s.data[index-Hz_s.ny])/dx;
			}
		//AdjustEFieldAtCnntIntfc();
	}
	if(IsTEx){
		BackupMyStruct(Ez_s,Ez_s_pre);
		for(i=pis+1;i<pie;i++)
			for(j=pjs+1;j<pje;j++){
				index	= i*Ez_s.ny+j;
				indy	= i*Hy_s.ny+j;
				indx	= i*Hx_s.ny+j;

				Ez_s.data[index]=Ceez.data[index]*(Ez_s.data[index])+
					Cevz.data[index]*Vez.data[index]+Cehz.data[index]*(
					(Hy_s.data[indy]-Hy_s.data[indy-Hy_s.ny])/dx-
					(Hx_s.data[indx]-Hx_s.data[indx-1])/dy);
				//Eztmp = fabs(Ez_s.data[index])*M_SQRT1_2;
				//if(Eztmp>Erms.data[i*m*Erms.ny+j*m])
				//	Erms.data[i*m*Erms.ny+j*m] = Eztmp;
				/*if((Ez_s.data[index]>1e15)||(Ez_s.data[index]<-1e15))
				{
					printf("Ceez = %2.2e\nStep = %d",Ceez.data[index],Step);
					printf("i = %d\tj =%d\n",i,j);
					printf("Cevz = %2.2e\n",Cevz.data[index]);
					printf("Cevz*Vez = %2.2e\n",Cevz.data[index]*Vez.data[index]);
					printf("Cehz = %2.2e\n",Cehz.data[index]);
					CaptData(1,"ne.dat",ne);
					CaptData(1,"Ezsp.dat",Ez_s_pre);
					//system("pause");
				}*/
			}
	}
}
void UpdateMField(){


	//created 2011.03.23 21.20
	//checked 03.23 21:23
	//changed at 03.35 11:29
	//Details: changed to only the M fields in domain are updated,
	//			with those in bondaries egnored.
	
	int i,j,index,ind,ind2;
	//double tmp1,tmp2,tmp3;
	if(IsTEx){

		for(i=0;i<Hx_s.nx;i++)
			for(j=pjs;j<pje;j++){
				index=i*Hx_s.ny+j;
				ind = i*Ez_s.ny+j;

				Hx_s.data[index]=Hx_s.data[index]+Chxez*(Ez_s.data[ind+1]-Ez_s.data[ind]);
			}

		for(i=pis;i<pie;i++)
			for(j=0;j<Hy_s.ny;j++){
				index=i*Hy_s.ny+j;
				ind = i*Ez_s.ny+j;
				Hy_s.data[index]=Hy_s.data[index]+Chyez*(Ez_s.data[ind+Ez_s.ny]-Ez_s.data[ind]);
			}
	}
	if(IsTMx){

		for(i=pis;i<pie;i++)
			for(j=pjs;j<pje;j++){
				
				index=i*Hz_s.ny+j;
				ind = i*Ex_s.ny+j;
				ind2 = i*Ey_s.ny+j;
				Hz_s.data[index]=Hz_s.data[index]+
					Chzey*(Ex_s.data[ind+1]-Ex_s.data[ind])+
					Chzex*(Ey_s.data[ind2+Ey_s.ny]-Ey_s.data[ind2]);
			}
	}
}

