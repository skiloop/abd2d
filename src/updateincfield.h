#ifndef __UPDATE_INC_FIELD_H__
#define __UPDATE_INC_FIELD_H__

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
void AddIncSource(MyDataF t){
	int j;
	for(j=tpis;j<=tpje;j++)
		Ez_i.data[(pis+2)*Ez_i.ny+j]=Ez0*cos(omega*t);
}
void UpdateIncEField(){

	//created 2011.03.23 21.20
	//changed at 03.35 11:39
	//Details: changed to only the E fields in domain are updated,
	//			with those in bondaries egnored.
	int i,j,index;
	int indx,indy;
	if(IsTMx){
		//BackupMyStruct(Ex_i,Ex_i_pre);
		//BackupMyStruct(Ey_i,Ey_i_pre);
		for(i=0;i<Ex_i.nx;i++)
			for(j=pjs+1;j<pje;j++){
				index = i*Hz_i.ny+j;
				indx=i*Ex_i.ny+j;
				Ex_i.data[indx]=Ceex.data[indx]*(Ex_i.data[indx])+
					Cevx.data[indx]*Vex.data[indx]+Cehx.data[indx]*
					(Hz_i.data[index]-Hz_i.data[index-1])/dy;
			}
		for(i=1+pis;i<pie;i++)
			for(j=0;j<Ey_i.ny-1;j++){
				indy = i*Ey_i.ny+j;
				index= i*Hz_i.ny+j;
				Ey_i.data[indy]=Ceey.data[indy]*(Ey_i.data[indy])
					+Cevy.data[indy]*Vey.data[indy]+Cehy.data[indy]*
					(Hz_i.data[index]-Hz_i.data[index-Hz_i.ny])/dx;
			}
	}
	if(IsTEx){
		//BackupMyStruct(Ez_i,Ez_i_pre);
		for(i=pis+1;i<pie;i++)
			for(j=pjs+1;j<pje;j++){
				index=i*Ez_i.ny+j;
				indy = i*Hy_i.ny+j;
				indx = i*Hx_i.ny+j;
				Ez_i.data[index]=Ceez.data[index]*(Ez_i.data[index])+
					Cevz.data[index]*Vez.data[index]+Cehz.data[index]*(
					(Hy_i.data[indy]-Hy_i.data[indy-Hy_i.ny])/dx-
					(Hx_i.data[indx]-Hx_i.data[indx-1])/dy);
			}
	}
}
void UpdateIncMField(){


	//created 2011.03.23 21.20
	//checked 03.23 21:23
	//changed at 03.35 11:29
	//Details: changed to only the M fields in domain are updated,
	//			with those in bondaries egnored.
	
	int i,j,index,ind;
	if(IsTEx){
		//BackupMyStruct(Hx_i,Hx_i_pre);
		//CheckIfNonZeros(Ez_i);
		for(i=0;i<Hx_i.nx;i++)
			for(j=pjs;j<pje;j++){
				index=i*Hx_i.ny+j;
				ind = i*Ez_i.ny+j;
				Hx_i.data[index]=Hx_i.data[index]+Chxez*(Ez_i.data[ind+1]-Ez_i.data[ind]);
			}
		//BackupMyStruct(Hy_i,Hy_i_pre);
		for(i=pis;i<pie;i++)
			for(j=0;j<Hy_i.ny;j++){
				index=i*Hy_i.ny+j;
				ind = i*Ez_i.ny+j;
				Hy_i.data[index]=Hy_i.data[index]
				+Chyez*(Ez_i.data[ind+Ez_i.ny]-Ez_i.data[ind]);
			}
	}
	if(IsTMx){
		//BackupMyStruct(Hz_i,Hz_i_pre);
		for(i=pis;i<pie;i++)
			for(j=pjs;j<pje;j++){
				int ind2;
				index=i*Hz_i.ny+j;
				ind = i*Ex_i.ny+j;
				ind2 = i*Ey_i.ny+j;
				Hz_i.data[index]=Hz_i.data[index]+
					Chzey*(Ex_i.data[ind+1]-Ex_i.data[ind])+
					Chzex*(Ey_i.data[ind2+Ey_i.ny]-Ey_i.data[ind2]);
			}
	}
}

#endif
