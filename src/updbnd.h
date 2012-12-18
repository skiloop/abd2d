#ifndef __UPDBND_H__
#define __UPDBND_H__

/*******************************************************************************************************
UpdMagFldForPML_TEz.h
update magnetic fields at PML regions
TEz
***********************************************************************************************************/
void UpdMagFldForPML_TEz(MyStruct hx,MyStruct hy,MyStruct ez){
	int i,j;
	if(IsPMLxn){
		for(i=0;i<pis;i++)
			for(j=1;j<=nym1;j++){
				hy.data[i*hy.ny+j] = Chyh_xn_i.data[i*Chyh_xn_i.ny+j-1]*hy.data[i*hy.ny+j]
				+Chyez_xn_i.data[i*Chyez_xn_i.ny+j-1]*(ez.data[(i+1)*ez.ny+j]-ez.data[i*ez.ny+j]);
/*******************************************************************************************************************/
			}
	}
	if(IsPMLxp){
		for(i=pie;i<=nxm1;i++)
			for(j=1;j<=nym1;j++){
				hy.data[i*hy.ny+j] = Chyh_xp_i.data[(i-pie)*Chyh_xp_i.ny+j-1]*hy.data[i*hy.ny+j]
				+Chyez_xp_i.data[(i-pie)*Chyez_xp_i.ny+j-1]*(ez.data[(i+1)*ez.ny+j]-ez.data[i*ez.ny+j]);
/*******************************************************************************************************************/
			}
	}
	
	if(IsPMLyn){
		for(i=1;i<=nxm1;i++)
			for(j=0;j<pjs;j++)
				hx.data[i*hx.ny+j] = Chxh_yn_i.data[(i-1)*Chxh_yn_i.ny+j]*hx.data[i*hx.ny+j]
				+Chxez_yn_i.data[(i-1)*Chxez_yn_i.ny+j]*(ez.data[i*ez.ny+j+1]-ez.data[i*ez.ny+j]);
	}
	
	if(IsPMLyp){
		for(i=1;i<=nxm1;i++)
			for(j=pje;j<=nym1;j++)
				hx.data[i*hx.ny+j] = Chxh_yp_i.data[(i-1)*Chxh_yp_i.ny+j-pje]*hx.data[i*hx.ny+j]
				+Chxez_yp_i.data[(i-1)*Chxez_yp_i.ny+j-pje]*(ez.data[i*ez.ny+j+1]-ez.data[i*ez.ny+j]);
	}
}
/*********************************************************************
UpdMagFldForPML_TMz.h
update magnetic fields at PML regions
TMz
*********************************************************************/
void UpdMagFldForPML_TMz(MyStruct hz,MyStruct ex,MyStruct ey){
	int i,j;
	if(IsPMLxn){
		for(i=0;i<Hzx_xn_i.nx;++i)
			for(j=0;j<Hzx_xn_i.ny;j++)
				Hzx_xn_i.data[i*Hzx_xn_i.ny+j] = Chzxh_xn_i.data[i*Chzxh_xn_i.ny+j]*Hzx_xn_i.data[i*Hzx_xn_i.ny+j]
				+Chzxey_xn_i.data[i*Chzxey_xn_i.ny+j]*(ey.data[(i+1)*ey.ny+j]-ey.data[i*ey.ny+j]);
		for(i=0;i<Hzy_xn_i.nx;++i)
			for(j=0;j<Hzy_xn_i.ny;j++){
				Hzy_xn_i.data[i*Hzy_xn_i.ny+j] = Chzyh_xn_i.data[i*Chzyh_xn_i.ny+j]*Hzy_xn_i.data[i*Hzy_xn_i.ny+j]
				+Chzyex_xn_i.data[i*Chzyex_xn_i.ny+j]*(ex.data[i*ex.ny+j+pjs+1]-ex.data[i*ex.ny+j+pjs]);
				
			}
	}
/*============================================================================================================*/
	if(IsPMLxp){
		for(i=0;i<Hzx_xp_i.nx;++i)
			for(j=0;j<Hzx_xp_i.ny;j++){
				Hzx_xp_i.data[i*Hzx_xp_i.ny+j] = Chzxh_xp_i.data[i*Chzxh_xp_i.ny+j]*Hzx_xp_i.data[i*Hzx_xp_i.ny+j]
				+Chzxey_xp_i.data[i*Chzxey_xp_i.ny+j]*(ey.data[(i+pie+1)*ey.ny+j]-ey.data[(i+pie)*ey.ny+j]);

				//if(fabs(Hzx_xp_i.data[i*Hzx_xp_i.ny+j])>(1.8e-2)*eps)
				//	puts("Hello!");
			}
		for(i=0;i<Hzy_xp_i.nx;++i)
			for(j=0;j<Hzy_xp_i.ny;j++){
				Hzy_xp_i.data[i*Hzy_xp_i.ny+j] = Chzyh_xp_i.data[i*Chzyh_xp_i.ny+j]*Hzy_xp_i.data[i*Hzy_xp_i.ny+j]
				+Chzyex_xp_i.data[i*Chzyex_xp_i.ny+j]*(ex.data[(pie+i)*ex.ny+j+pjs+1]-ex.data[(pie+i)*ex.ny+j+pjs]);
				//if(fabs(Hzx_xp_i.data[i*Hzx_xp_i.ny+j])>(1.8e-2)*eps)
				//	puts("Hello!");
			}
	}
/*===============================================================================================================*/
	if(IsPMLyn){
		for(i=0;i<Hzx_yn_i.nx;++i)
			for(j=0;j<Hzx_yn_i.ny;j++)
				Hzx_yn_i.data[i*Hzx_yn_i.ny+j] = Chzxh_yn_i.data[i*Chzxh_yn_i.ny+j]*Hzx_yn_i.data[i*Hzx_yn_i.ny+j]
				+Chzxey_yn_i.data[i*Chzxey_yn_i.ny+j]*(ey.data[(i+1+pis)*ey.ny+j]-ey.data[(i+pis)*ey.ny+j]);
		for(i=0;i<Hzy_yn_i.nx;++i)
			for(j=0;j<Hzy_yn_i.ny;j++)
				Hzy_yn_i.data[i*Hzy_yn_i.ny+j] = Chzyh_yn_i.data[i*Chzyh_yn_i.ny+j]*Hzy_yn_i.data[i*Hzy_yn_i.ny+j]
				+Chzyex_yn_i.data[i*Chzyex_yn_i.ny+j]*(ex.data[i*ex.ny+j+1]-ex.data[i*ex.ny+j]);
	
	}
/*===============================================================================================================*/
	if(IsPMLyp){
		for(i=0;i<Hzx_yp_i.nx;++i)
			for(j=0;j<Hzx_yp_i.ny;j++){
				Hzx_yp_i.data[i*Hzx_yp_i.ny+j] = Chzxh_yp_i.data[i*Chzxh_yp_i.ny+j]*Hzx_yp_i.data[i*Hzx_yp_i.ny+j]
				+Chzxey_yp_i.data[i*Chzxey_yp_i.ny+j]*(ey.data[(i+pis+1)*ey.ny+j+pje]-ey.data[(i+pis)*ey.ny+j+pje]);
				//if(fabs(Hzx_yp_i.data[i*Hzx_yp_i.ny+j])>((1e-2)*eps))
				//	i=i;
			}
		for(i=0;i<Hzy_yp_i.nx;++i)
			for(j=0;j<Hzy_yp_i.ny;j++){
				Hzy_yp_i.data[i*Hzy_yp_i.ny+j] = Chzyh_yp_i.data[i*Chzyh_yp_i.ny+j]*Hzy_yp_i.data[i*Hzy_yp_i.ny+j]
				+Chzyex_yp_i.data[i*Chzyex_yp_i.ny+j]*(ex.data[i*ex.ny+j+pje+1]-ex.data[i*ex.ny+j+pje]);
				//if(fabs(Hzy_yp_i.data[i*Hzy_yp_i.ny+j])>((1e-2)*eps))
				//	i=i;
			}
	}
/*===================================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=0;j<pjs;j++){
			hz.data[i*hz.ny+j]=Hzx_xn_i.data[i*Hzx_xn_i.ny+j]+Hzy_yn_i.data[i*Hzy_yn_i.ny+j];
		}
	}
	for(i=0;i<pis;i++){
		for(j=pje;j<ny;j++){
			hz.data[i*hz.ny+j]=Hzx_xn_i.data[i*Hzx_xn_i.ny+j]+Hzy_yp_i.data[i*Hzy_yp_i.ny+j-pje];
		}
	}
	for(i=pie;i<nx;i++){
		for(j=0;j<pjs;j++){
			hz.data[i*hz.ny+j]=Hzx_xp_i.data[(i-pie)*Hzx_xp_i.ny+j]+Hzy_yn_i.data[i*Hzy_yn_i.ny+j];
		}
	}
	for(i=pie;i<nx;i++){
		for(j=pje;j<ny;j++){
			hz.data[i*hz.ny+j]=Hzx_xp_i.data[(i-pie)*Hzx_xp_i.ny+j]+Hzy_yp_i.data[i*Hzy_yp_i.ny+j-pje];
		}
	}
/*=======================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=pjs;j<pje;j++){
			hz.data[i*hz.ny+j]=Hzx_xn_i.data[i*Hzx_xn_i.ny+j]+Hzy_xn_i.data[i*Hzy_xn_i.ny+j-pjs];
		}
	}
	for(i=0;i<PMLCellxp;i++){
		for(j=pjs;j<pje;j++){
			hz.data[(i+pie)*hz.ny+j]=Hzx_xp_i.data[i*Hzx_xp_i.ny+j]+Hzy_xp_i.data[i*Hzy_xp_i.ny+j-pjs];
		}
	}
	for(i=pis;i<pie;i++){
		for(j=0;j<pjs;j++){
			hz.data[i*hz.ny+j]=Hzx_yn_i.data[(i-pis)*Hzx_yn_i.ny+j]+Hzy_yn_i.data[i*Hzy_yn_i.ny+j];
		}
	}
	for(i=pis;i<pie;i++){
		for(j=0;j<PMLCellyp;j++){
			hz.data[i*hz.ny+j+pje]=Hzx_yp_i.data[(i-pis)*Hzx_yp_i.ny+j]+Hzy_yp_i.data[i*Hzy_yp_i.ny+j];
		}
	}
}
/*******************************************************************************************************
UpdMEltFldForPML_TMz.h
update electric fields at PML regions
TEz
***********************************************************************************************************/
void UpdEltFldForPML_TMz(MyStruct ex,MyStruct ey,MyStruct hz)
{
	int i,j;
	if(IsPMLxn){
		for(i=1;i<=pis;i++)
			for(j=0;j<ey.ny;j++){
				ey.data[i*ey.ny+j] = Ceye_xn_i.data[(i-1)*Ceye_xn_i.ny+j]*ey.data[i*ey.ny+j]
				+Ceyhz_xn_i.data[(i-1)*Ceyhz_xn_i.ny+j]*(hz.data[i*hz.ny+j]-hz.data[(i-1)*hz.ny+j]);
			}
	}
	if(IsPMLxp){
		for(i=pie;i<nx;i++)
			for(j=0;j<ny;j++){
				ey.data[i*ey.ny+j] = Ceye_xp_i.data[(i-pie)*Ceye_xp_i.ny+j]*ey.data[i*ey.ny+j]
				+Ceyhz_xp_i.data[(i-pie)*Ceyhz_xp_i.ny+j]*(hz.data[i*hz.ny+j]-hz.data[(i-1)*hz.ny+j]);
				
			}
	}
	if(IsPMLyn){
		for(i=0;i<=nxm1;i++)
			for(j=1;j<=pjs;j++){
				ex.data[i*ex.ny+j] = Cexe_yn_i.data[i*Cexe_yn_i.ny+j-1]*ex.data[i*ex.ny+j]
				+Cexhz_yn_i.data[i*Cexhz_yn_i.ny+j-1]*(hz.data[i*hz.ny+j]-hz.data[i*hz.ny+j-1]);
				
			}
	}
	if(IsPMLyp){
		for(i=0;i<=nxm1;i++)
			for(j=pje;j<ny;j++){
				ex.data[i*ex.ny+j] = Cexe_yp_i.data[i*Cexe_yp_i.ny+j-pje]*ex.data[i*ex.ny+j]
				+Cexhz_yp_i.data[i*Cexhz_yp_i.ny+j-pje]*(hz.data[i*hz.ny+j]-hz.data[i*hz.ny+j-1]);
			}
	}

}
/*********************************************************************
UpdMEltFldForPML_TEz.h
update electric fields at PML regions
TMz
*********************************************************************/
void UpdEltFldForPML_TEz(MyStruct ez,MyStruct hx,MyStruct hy){
	int i,j;
	if(IsPMLxn){
		for(i=0;i<Ezx_xn_i.nx;++i)
			for(j=0;j<Ezx_xn_i.ny;j++){
				Ezx_xn_i.data[i*Ezx_xn_i.ny+j] = Cezxe_xn_i.data[i*Cezxe_xn_i.ny+j]*Ezx_xn_i.data[i*Ezx_xn_i.ny+j]
				+Cezxhy_xn_i.data[i*Cezxhy_xn_i.ny+j]*(hy.data[(i+1)*hy.ny+j+1]-hy.data[i*hy.ny+j+1]);
			}
		for(i=0;i<Ezy_xn_i.nx;++i)
			for(j=0;j<Ezy_xn_i.ny;j++)
				Ezy_xn_i.data[i*Ezy_xn_i.ny+j] = Cezye_xn_i.data[i*Cezye_xn_i.ny+j]*Ezy_xn_i.data[i*Ezy_xn_i.ny+j]
				+Cezyhx_xn_i.data[i*Cezyhx_xn_i.ny+j]*(hx.data[(i+1)*hx.ny+j+pjs+1]-hx.data[(i+1)*hx.ny+j+pjs]);
	}
/*============================================================================================================*/
	if(IsPMLxp){
		for(i=0;i<Ezx_xp_i.nx;++i)
			for(j=0;j<Ezx_xp_i.ny;j++){
				Ezx_xp_i.data[i*Ezx_xp_i.ny+j] = Cezxe_xp_i.data[i*Cezxe_xp_i.ny+j]*Ezx_xp_i.data[i*Ezx_xp_i.ny+j]
				+Cezxhy_xp_i.data[i*Cezxhy_xp_i.ny+j]*(hy.data[(i+pie)*hy.ny+j+1]-hy.data[(i+pie-1)*hy.ny+j+1]);
			}
		for(i=0;i<Ezy_xp_i.nx;++i)
			for(j=0;j<Ezy_xp_i.ny;j++){
				Ezy_xp_i.data[i*Ezy_xp_i.ny+j] = Cezye_xp_i.data[i*Cezye_xp_i.ny+j]*Ezy_xp_i.data[i*Ezy_xp_i.ny+j]
				+Cezyhx_xp_i.data[i*Cezyhx_xp_i.ny+j]*(hx.data[(pie+i)*hx.ny+j+pjs+1]-hx.data[(pie+i)*hx.ny+j+pjs]);
			}
	}
/*===============================================================================================================*/
	if(IsPMLyn){
		for(i=0;i<Ezx_yn_i.nx;++i)
			for(j=0;j<Ezx_yn_i.ny;j++){
				Ezx_yn_i.data[i*Ezx_yn_i.ny+j] = Cezxe_yn_i.data[i*Cezxe_yn_i.ny+j]*Ezx_yn_i.data[i*Ezx_yn_i.ny+j]
				+Cezxhy_yn_i.data[i*Cezxhy_yn_i.ny+j]*(hy.data[(i+1+pis)*hy.ny+j+1]-hy.data[(i+pis)*hy.ny+j+1]);
			}
		for(i=0;i<Ezy_yn_i.nx;++i)
			for(j=0;j<Ezy_yn_i.ny;j++){
				Ezy_yn_i.data[i*Ezy_yn_i.ny+j] = Cezye_yn_i.data[i*Cezye_yn_i.ny+j]*Ezy_yn_i.data[i*Ezy_yn_i.ny+j]
				+Cezyhx_yn_i.data[i*Cezyhx_yn_i.ny+j]*(hx.data[(i+1)*hx.ny+j+1]-hx.data[(i+1)*hx.ny+j]);
/*******************************************************************************************************************/
			}
	
	}
/*===============================================================================================================*/
	if(IsPMLyp){
		for(i=0;i<Ezx_yp_i.nx;++i)
			for(j=0;j<Ezx_yp_i.ny;j++){
				Ezx_yp_i.data[i*Ezx_yp_i.ny+j] = Cezxe_yp_i.data[i*Cezxe_yp_i.ny+j]*Ezx_yp_i.data[i*Ezx_yp_i.ny+j]
				+Cezxhy_yp_i.data[i*Cezxhy_yp_i.ny+j]*(hy.data[(i+pis+1)*hy.ny+j+pje]-hy.data[(i+pis)*hy.ny+j+pje]);
/*******************************************************************************************************************/
			}
		for(i=0;i<Ezy_yp_i.nx;++i)
			for(j=0;j<Ezy_yp_i.ny;j++){
				Ezy_yp_i.data[i*Ezy_yp_i.ny+j] = Cezye_yp_i.data[i*Cezye_yp_i.ny+j]*Ezy_yp_i.data[i*Ezy_yp_i.ny+j]
				+Cezyhx_yp_i.data[i*Cezyhx_yp_i.ny+j]*(hx.data[(1+i)*hx.ny+j+pje]-hx.data[(1+i)*hx.ny+j+pje-1]);
/*******************************************************************************************************************/
			}
	}
/*===================================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=0;j<pjs;j++){
			ez.data[(i+1)*ez.ny+j+1]=Ezx_xn_i.data[i*Ezx_xn_i.ny+j]+Ezy_yn_i.data[i*Ezy_yn_i.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=0;i<pis;i++){
		for(j=0;j<PMLCellyp;j++){
			ez.data[(i+1)*ez.ny+j+pje]=Ezx_xn_i.data[i*Ezx_xn_i.ny+j+pje-1]+Ezy_yp_i.data[i*Ezy_yp_i.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=pie;i<nx;i++){
		for(j=pje;j<ny;j++){
			ez.data[i*ez.ny+j]=Ezx_xp_i.data[(i-pie)*Ezx_xp_i.ny+j-1]+Ezy_yp_i.data[(i-1)*Ezy_yp_i.ny+j-pje];
/*******************************************************************************************************************/
		}
	}
	for(i=pie;i<nx;i++){
		for(j=0;j<pjs;j++){
			ez.data[i*ez.ny+j+1]=Ezx_xp_i.data[(i-pie)*Ezx_xp_i.ny+j]+Ezy_yn_i.data[(i-1)*Ezy_yn_i.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=pis;i<pie-1;i++){
		for(j=0;j<pjs;j++){
			ez.data[(i+1)*ez.ny+j+1]=Ezx_yn_i.data[(i-pis)*Ezx_yn_i.ny+j]+Ezy_yn_i.data[i*Ezy_yn_i.ny+j];
/*******************************************************************************************************************/
		}
	}
	for(i=pis;i<pie-1;i++){
		for(j=0;j<PMLCellyp;j++){
			ez.data[(i+1)*ez.ny+j+pje]=Ezx_yp_i.data[(i-pis)*Ezx_yp_i.ny+j]+Ezy_yp_i.data[i*Ezy_yp_i.ny+j];
/*******************************************************************************************************************/
		}
	}
/*=======================================================================================================*/
	for(i=0;i<pis;i++){
		for(j=pjs;j<pje-1;j++){
			ez.data[(i+1)*ez.ny+j+1]=Ezx_xn_i.data[i*Ezx_xn_i.ny+j]+Ezy_xn_i.data[i*Ezy_xn_i.ny+j-pjs];
/*******************************************************************************************************************/
		}
	}
	for(i=0;i<PMLCellxp;i++){
		for(j=pjs;j<pje-1;j++){
			ez.data[(i+pie)*ez.ny+j+1]=Ezx_xp_i.data[i*Ezx_xp_i.ny+j]+Ezy_xp_i.data[i*Ezy_xp_i.ny+j-pjs];
		}
	}
}

void UpdateMFieldForPML(MyStruct hx,MyStruct hy,MyStruct hz,MyStruct ex,MyStruct ey,MyStruct ez){
	/* update magnetic fields at PML regions */
	
	if(IsTEx){
		UpdMagFldForPML_TEz(hx,hy,ez);
	}
	if(IsTMx){
		UpdMagFldForPML_TMz(hz,ex,ey);
	}

}



void UpdateEFieldForPML(MyStruct hx,MyStruct hy,MyStruct hz,MyStruct ex,MyStruct ey,MyStruct ez){
	/* update electric fields at PML regions */
	
	if(IsTEx){
		UpdEltFldForPML_TEz(ez,hx,hy);
	}
	if(IsTMx){
		UpdEltFldForPML_TMz(ex,ey,hz);
	}
	
}
#endif
