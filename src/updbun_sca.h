
/*******************************************************************************************************
UpdMagFldForPML_TEx.h
update magnetic fields at PML regions
TEx
***********************************************************************************************************/
void UpdMFieldForPMLTEx(){
	int i,j;
	if(IsPMLxn){
		for(i=0;i<pis;i++)
			for(j=1;j<=nym1;j++){
				Hy_s.data[i*Hy_s.ny+j] = Chyh_xn.data[i*Chyh_xn.ny+j-1]*Hy_s.data[i*Hy_s.ny+j]
				+Chyez_xn.data[i*Chyez_xn.ny+j-1]*(Ez_s.data[(i+1)*Ez_s.ny+j]-Ez_s.data[i*Ez_s.ny+j]);
/*******************************************************************************************************************/
			}
	}
	if(IsPMLxp){
		for(i=pie;i<=nxm1;i++)
			for(j=1;j<=nym1;j++){
				Hy_s.data[i*Hy_s.ny+j] = Chyh_xp.data[(i-pie)*Chyh_xp.ny+j-1]*Hy_s.data[i*Hy_s.ny+j]
				+Chyez_xp.data[(i-pie)*Chyez_xp.ny+j-1]*(Ez_s.data[(i+1)*Ez_s.ny+j]-Ez_s.data[i*Ez_s.ny+j]);
/*******************************************************************************************************************/
			}
	}
	
	if(IsPMLyn){
		for(i=1;i<=nxm1;i++)
			for(j=0;j<pjs;j++)
				Hx_s.data[i*Hx_s.ny+j] = Chxh_yn.data[(i-1)*Chxh_yn.ny+j]*Hx_s.data[i*Hx_s.ny+j]
				+Chxez_yn.data[(i-1)*Chxez_yn.ny+j]*(Ez_s.data[i*Ez_s.ny+j+1]-Ez_s.data[i*Ez_s.ny+j]);
	}
	
	if(IsPMLyp){
		for(i=1;i<=nxm1;i++)
			for(j=pje;j<=nym1;j++)
				Hx_s.data[i*Hx_s.ny+j] = Chxh_yp.data[(i-1)*Chxh_yp.ny+j-pje]*Hx_s.data[i*Hx_s.ny+j]
				+Chxez_yp.data[(i-1)*Chxez_yp.ny+j-pje]*(Ez_s.data[i*Ez_s.ny+j+1]-Ez_s.data[i*Ez_s.ny+j]);
	}
}
/*********************************************************************
UpdMagFldForPML_TMx.h
update magnetic fields at PML regions
TMx
*********************************************************************/
void UpdMFieldForPMLTMx(){
	int i,j,ind,ind2;
	if(IsPMLxn){
		for(i=0;i<Hzx_xn.nx;++i)
			for(j=0;j<Hzx_xn.ny;j++){
				ind = i*Hzx_xn.ny+j;
				ind2 = i*Ey_s.ny+j;
				Hzx_xn.data[ind] = Chzxh_xn.data[ind]*Hzx_xn.data[ind]
				+Chzxey_xn.data[ind]*(Ey_s.data[ind2+Ey_s.ny]-Ey_s.data[ind2]);
			}
		for(i=0;i<Hzy_xn.nx;++i)
			for(j=0;j<Hzy_xn.ny;j++){
				ind = i*Hzy_xn.ny+j;
				ind2 = i*Ex_s.ny+j+pjs;
				Hzy_xn.data[ind] = Chzyh_xn.data[ind]*Hzy_xn.data[ind]
				+Chzyex_xn.data[ind]*(Ex_s.data[ind2+1]-Ex_s.data[ind]);
				
			}
	}
/*============================================================================================================*/
	if(IsPMLxp){
		for(i=0;i<Hzx_xp.nx;++i)
			for(j=0;j<Hzx_xp.ny;j++){
				ind = i*Hzx_xp.ny+j;
				ind2 = (i+pie)*Ey_s.ny+j;
				Hzx_xp.data[ind] = Chzxh_xp.data[ind]*Hzx_xp.data[ind]
				+Chzxey_xp.data[ind]*(Ey_s.data[ind2+Ey_s.ny]-Ey_s.data[ind2]);

				//if(fabs(Hzx_xp.data[i*Hzx_xp.ny+j])>(1.8e-2)*eps)
				//	puts("Hello!");
			}
		for(i=0;i<Hzy_xp.nx;++i)
			for(j=0;j<Hzy_xp.ny;j++){
				ind = i*Hzy_xp.ny+j;
				ind2 = (pie+i)*Ex_s.ny+j+pjs;
				Hzy_xp.data[ind] = Chzyh_xp.data[ind]*Hzy_xp.data[ind]
				+Chzyex_xp.data[ind]*(Ex_s.data[ind2+1]-Ex_s.data[ind2]);
				//if(fabs(Hzx_xp.data[i*Hzx_xp.ny+j])>(1.8e-2)*eps)
				//	puts("Hello!");
			}
	}
/*===============================================================================================================*/
	if(IsPMLyn){
		for(i=0;i<Hzx_yn.nx;++i)
			for(j=0;j<Hzx_yn.ny;j++){
				ind = i*Hzx_yn.ny+j;
				ind2 = (i+pis)*Ey_s.ny+j;
				Hzx_yn.data[ind] = Chzxh_yn.data[ind]*Hzx_yn.data[ind]
				+Chzxey_yn.data[ind]*(Ey_s.data[ind2+Ey_s.ny]-Ey_s.data[ind2]);
			}
		for(i=0;i<Hzy_yn.nx;++i)
			for(j=0;j<Hzy_yn.ny;j++){
				ind = i*Hzy_yn.ny+j;
				ind2 = i*Ex_s.ny+j;
				Hzy_yn.data[ind] = Chzyh_yn.data[ind]*Hzy_yn.data[ind]
				+Chzyex_yn.data[ind]*(Ex_s.data[ind2+1]-Ex_s.data[ind2]);
			}
	
	}
/*===============================================================================================================*/
	if(IsPMLyp){
		for(i=0;i<Hzx_yp.nx;++i)
			for(j=0;j<Hzx_yp.ny;j++){
				ind = i*Hzx_yp.ny+j;
				ind2 =(i+pis)*Ey_s.ny+j+pje;
				Hzx_yp.data[ind] = Chzxh_yp.data[ind]*Hzx_yp.data[ind]
				+Chzxey_yp.data[ind]*(Ey_s.data[ind2+Ey_s.ny]-Ey_s.data[ind2]);
				//if(fabs(Hzx_yp.data[i*Hzx_yp.ny+j])>((1e-2)*eps))
				//	i=i;
			}
		for(i=0;i<Hzy_yp.nx;++i)
			for(j=0;j<Hzy_yp.ny;j++){
				ind = i*Hzy_yp.ny+j;
				ind2 = i*Ex_s.ny+j+pje;
				Hzy_yp.data[ind] = Chzyh_yp.data[ind]*Hzy_yp.data[ind]
				+Chzyex_yp.data[ind]*(Ex_s.data[ind2+1]-Ex_s.data[ind2]);
				//if(fabs(Hzy_yp.data[i*Hzy_yp.ny+j])>((1e-2)*eps))
				//	i=i;
			}
	}
/*===================================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=0;j<pjs;j++){
			Hz_s.data[i*Hz_s.ny+j]=Hzx_xn.data[i*Hzx_xn.ny+j]+Hzy_yn.data[i*Hzy_yn.ny+j];
		}
	}
	for(i=0;i<pis;i++){
		for(j=pje;j<ny;j++){
			Hz_s.data[i*Hz_s.ny+j]=Hzx_xn.data[i*Hzx_xn.ny+j]+Hzy_yp.data[i*Hzy_yp.ny+j-pje];
		}
	}
	for(i=pie;i<nx;i++){
		for(j=0;j<pjs;j++){
			Hz_s.data[i*Hz_s.ny+j]=Hzx_xp.data[(i-pie)*Hzx_xp.ny+j]+Hzy_yn.data[i*Hzy_yn.ny+j];
		}
	}
	for(i=pie;i<nx;i++){
		for(j=pje;j<ny;j++){
			Hz_s.data[i*Hz_s.ny+j]=Hzx_xp.data[(i-pie)*Hzx_xp.ny+j]+Hzy_yp.data[i*Hzy_yp.ny+j-pje];
		}
	}
/*=======================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=pjs;j<pje;j++){
			Hz_s.data[i*Hz_s.ny+j]=Hzx_xn.data[i*Hzx_xn.ny+j]+Hzy_xn.data[i*Hzy_xn.ny+j-pjs];
		}
	}
	for(i=0;i<PMLCellxp;i++){
		for(j=pjs;j<pje;j++){
			Hz_s.data[(i+pie)*Hz_s.ny+j]=Hzx_xp.data[i*Hzx_xp.ny+j]+Hzy_xp.data[i*Hzy_xp.ny+j-pjs];
		}
	}
	for(i=pis;i<pie;i++){
		for(j=0;j<pjs;j++){
			Hz_s.data[i*Hz_s.ny+j]=Hzx_yn.data[(i-pis)*Hzx_yn.ny+j]+Hzy_yn.data[i*Hzy_yn.ny+j];
		}
	}
	for(i=pis;i<pie;i++){
		for(j=0;j<PMLCellyp;j++){
			Hz_s.data[i*Hz_s.ny+j+pje]=Hzx_yp.data[(i-pis)*Hzx_yp.ny+j]+Hzy_yp.data[i*Hzy_yp.ny+j];
		}
	}
}
/*******************************************************************************************************
UpdMEltFldForPML_TMx.h
update electric fields at PML regions
TMx
***********************************************************************************************************/
void UpdEFieldForPMLTMx(){
	int i,j;
	if(IsPMLxn){
		for(i=1;i<=pis;i++)
			for(j=0;j<Ey_s.ny;j++){
				Ey_s.data[i*Ey_s.ny+j] = Ceye_xn.data[(i-1)*Ceye_xn.ny+j]*Ey_s.data[i*Ey_s.ny+j]
				+Ceyhz_xn.data[(i-1)*Ceyhz_xn.ny+j]*(Hz_s.data[i*Hz_s.ny+j]-Hz_s.data[(i-1)*Hz_s.ny+j]);
			}
	}
	if(IsPMLxp){
		for(i=pie;i<nx;i++)
			for(j=0;j<ny;j++){
				Ey_s.data[i*Ey_s.ny+j] = Ceye_xp.data[(i-pie)*Ceye_xp.ny+j]*Ey_s.data[i*Ey_s.ny+j]
				+Ceyhz_xp.data[(i-pie)*Ceyhz_xp.ny+j]*(Hz_s.data[i*Hz_s.ny+j]-Hz_s.data[(i-1)*Hz_s.ny+j]);
				
			}
	}
	if(IsPMLyn){
		for(i=0;i<=nxm1;i++)
			for(j=1;j<=pjs;j++){
				Ex_s.data[i*Ex_s.ny+j] = Cexe_yn.data[i*Cexe_yn.ny+j-1]*Ex_s.data[i*Ex_s.ny+j]
				+Cexhz_yn.data[i*Cexhz_yn.ny+j-1]*(Hz_s.data[i*Hz_s.ny+j]-Hz_s.data[i*Hz_s.ny+j-1]);
				
			}
	}
	if(IsPMLyp){
		for(i=0;i<=nxm1;i++)
			for(j=pje;j<ny;j++){
				Ex_s.data[i*Ex_s.ny+j] = Cexe_yp.data[i*Cexe_yp.ny+j-pje]*Ex_s.data[i*Ex_s.ny+j]
				+Cexhz_yp.data[i*Cexhz_yp.ny+j-pje]*(Hz_s.data[i*Hz_s.ny+j]-Hz_s.data[i*Hz_s.ny+j-1]);
			}
	}

}
/*********************************************************************
UpdMEltFldForPML_TEx.h
update electric fields at PML regions
TEx
*********************************************************************/
void UpdEFieldForPMLTEx(){
	int i,j;
	int ind,ind2;
	if(IsPMLxn){
		for(i=0;i<Ezx_xn.nx;++i)
			for(j=0;j<Ezx_xn.ny;j++){
				ind = i*Ezx_xn.ny+j;
				ind2 = i*Hy_s.ny+j+1;
				Ezx_xn.data[ind] = Cezxe_xn.data[ind]*Ezx_xn.data[ind]
				+Cezxhy_xn.data[ind]*(Hy_s.data[ind2+Hy_s.ny]-Hy_s.data[ind2]);
			}
		for(i=0;i<Ezy_xn.nx;++i)
			for(j=0;j<Ezy_xn.ny;j++){
				ind = i*Ezy_xn.ny+j;
				ind2 = (i+1)*Hx_s.ny+j+pjs;
				Ezy_xn.data[ind] = Cezye_xn.data[ind]*Ezy_xn.data[ind]
				+Cezyhx_xn.data[ind]*(Hx_s.data[ind2+1]-Hx_s.data[ind2]);
			}
	}
/*============================================================================================================*/
	if(IsPMLxp){
		for(i=0;i<Ezx_xp.nx;++i)
			for(j=0;j<Ezx_xp.ny;j++){
				ind = i*Ezx_xp.ny+j;
				ind2 = (i+pie)*Hy_s.ny+j+1;
				Ezx_xp.data[ind] = Cezxe_xp.data[ind]*Ezx_xp.data[ind]
				+Cezxhy_xp.data[ind]*(Hy_s.data[ind2]-Hy_s.data[ind2-Hy_s.ny]);
			}
		for(i=0;i<Ezy_xp.nx;++i)
			for(j=0;j<Ezy_xp.ny;j++){
				ind = i*Ezy_xp.ny+j;
				ind2 = (pie+i)*Hx_s.ny+j+pjs;
				Ezy_xp.data[ind] = Cezye_xp.data[ind]*Ezy_xp.data[ind]
				+Cezyhx_xp.data[ind]*(Hx_s.data[ind2+1]-Hx_s.data[ind2]);
			}
	}
/*===============================================================================================================*/
	if(IsPMLyn){
		for(i=0;i<Ezx_yn.nx;++i)
			for(j=0;j<Ezx_yn.ny;j++){
				ind = i*Ezx_yn.ny+j;
				ind2 = (i+pis)*Hy_s.ny+j+1;
				Ezx_yn.data[ind] = Cezxe_yn.data[ind]*Ezx_yn.data[ind]
				+Cezxhy_yn.data[ind]*(Hy_s.data[ind2+Hy_s.ny]-Hy_s.data[ind2]);
			}
		for(i=0;i<Ezy_yn.nx;++i)
			for(j=0;j<Ezy_yn.ny;j++){
				ind = i*Ezy_yn.ny+j;
				ind2 = (i+1)*Hx_s.ny+j;
				Ezy_yn.data[ind] = Cezye_yn.data[ind]*Ezy_yn.data[ind]
				+Cezyhx_yn.data[ind]*(Hx_s.data[ind2+1]-Hx_s.data[ind2]);
/*******************************************************************************************************************/
			}
	
	}
/*===============================================================================================================*/
	if(IsPMLyp){
		for(i=0;i<Ezx_yp.nx;++i)
			for(j=0;j<Ezx_yp.ny;j++){
				ind = i*Ezx_yp.ny+j;
				ind2 = (i+pis)*Hy_s.ny+j+pje;
				Ezx_yp.data[ind] = Cezxe_yp.data[ind]*Ezx_yp.data[ind]
				+Cezxhy_yp.data[ind]*(Hy_s.data[ind2+Hy_s.ny]-Hy_s.data[ind2]);
/*******************************************************************************************************************/
			}
		for(i=0;i<Ezy_yp.nx;++i)
			for(j=0;j<Ezy_yp.ny;j++){
				ind = i*Ezy_yp.ny+j;
				ind2 = (1+i)*Hx_s.ny+j+pje;
				Ezy_yp.data[ind] = Cezye_yp.data[ind]*Ezy_yp.data[ind]
				+Cezyhx_yp.data[ind]*(Hx_s.data[ind2]-Hx_s.data[ind2-1]);
/*******************************************************************************************************************/
			}
	}
/*===================================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=0;j<pjs;j++){
			Ez_s.data[(i+1)*Ez_s.ny+j+1]=Ezx_xn.data[i*Ezx_xn.ny+j]+Ezy_yn.data[i*Ezy_yn.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=0;i<pis;i++){
		for(j=0;j<PMLCellyp;j++){
			Ez_s.data[(i+1)*Ez_s.ny+j+pje]=Ezx_xn.data[i*Ezx_xn.ny+j+pje-1]+Ezy_yp.data[i*Ezy_yp.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=pie;i<nx;i++){
		for(j=pje;j<ny;j++){
			Ez_s.data[i*Ez_s.ny+j]=Ezx_xp.data[(i-pie)*Ezx_xp.ny+j-1]+Ezy_yp.data[(i-1)*Ezy_yp.ny+j-pje];
/*******************************************************************************************************************/
		}
	}
	for(i=pie;i<nx;i++){
		for(j=0;j<pjs;j++){
			Ez_s.data[i*Ez_s.ny+j+1]=Ezx_xp.data[(i-pie)*Ezx_xp.ny+j]+Ezy_yn.data[(i-1)*Ezy_yn.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=pis;i<pie-1;i++){
		for(j=0;j<pjs;j++){
			Ez_s.data[(i+1)*Ez_s.ny+j+1]=Ezx_yn.data[(i-pis)*Ezx_yn.ny+j]+Ezy_yn.data[i*Ezy_yn.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=pis;i<pie-1;i++){
		for(j=0;j<PMLCellyp;j++){
			Ez_s.data[(i+1)*Ez_s.ny+j+pje]=Ezx_yp.data[(i-pis)*Ezx_yp.ny+j]+Ezy_yp.data[i*Ezy_yp.ny+j];
/*******************************************************************************************************************/
		}
	}
/*=======================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=pjs;j<pje-1;j++){
			Ez_s.data[(i+1)*Ez_s.ny+j+1]=Ezx_xn.data[i*Ezx_xn.ny+j]+Ezy_xn.data[i*Ezy_xn.ny+j-pjs];
/*******************************************************************************************************************/
		}
	}
	for(i=0;i<PMLCellxp;i++){
		for(j=pjs;j<pje-1;j++){
			Ez_s.data[(i+pie)*Ez_s.ny+j+1]=Ezx_xp.data[i*Ezx_xp.ny+j]+Ezy_xp.data[i*Ezy_xp.ny+j-pjs];
		}
	}
}

void UpdEFieldForPML(){
	/* update E fields at PML regions */
	
	if(IsTMx){
		UpdEFieldForPMLTMx();
	}
	if(IsTEx){
		UpdEFieldForPMLTEx();
	}

}



void UpdMFieldForPML(){
	/* update M fields at PML regions */
	
	if(IsTEx){
		UpdMFieldForPMLTEx();

	}
	if(IsTMx){
		UpdMFieldForPMLTMx();
	}
	
}