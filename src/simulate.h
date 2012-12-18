
#ifndef _SIMULATE_H_
#define _SIMULATE_H_

#include"matlabsim.h"

#ifdef MATLAB_SIMULATION
Engine *ep;
#endif

void DispEMFields(const int timestep){


#ifdef MATLAB_SIMULATION
//display 0
#ifdef FIELD_TO_DISPLAY0

		//Matlab Simulation
		if(timestep%LEAPSTEP_OF_DISPLAY==0)
			Simulate0(ep,FIELD_TO_DISPLAY0);

#endif

//display 1
#ifdef FIELD_TO_DISPLAY1

		/*Matlab Simulation*/
		if(timestep%1==0)
			Simulate1(ep,FIELD_TO_DISPLAY1);

#endif


//display 2
#ifdef FIELD_TO_DISPLAY2

		/*Matlab Simulation*/
		if(timestep%1==0)
			Simulate2(ep,FIELD_TO_DISPLAY2);

#endif
#endif

}
void EndMatlabSim(){

#ifdef MATLAB_SIMULATION

	//Close Matlab Engine
	engEvalString(ep,"clear;close all;");
	engClose(ep);

#endif

}
void DispNe(const int timestep){
	
#ifdef MATLAB_SIMULATION

		/*DISPLAY NE*/
		if(timestep%1==0)
			SimulateNe(ep,ne);

#endif	
}
void InitSim(){
#ifdef MATLAB_SIMULATION
	//Define and open matlab engine
	if((ep=engOpen(NULL))==NULL){
        printf("Can't start matlab engine!\n");
        exit(1);
    }
	//engEvalString(ep,"cd 'd:\\Backup\\ÎÒµÄÎÄµµ\\Visual Studio 2008\\AirBreakdownScatter\\AirBreakdownScatter\\'");
	engEvalString(ep,"cd 'c:\\Documents and Settings\\Wenbin Lin\\My Documents\\Visual Studio 2005\\Projects\\AirBreakdnScattered\\AirBreakdnScattered\\';");
#ifdef FIELD_TO_DISPLAY0
	PreSimuAdd0(ep,FIELD_TO_DISPLAY0);
#endif
#ifdef FIELD_TO_DISPLAY1
	PreSimuAdd1(ep,FIELD_TO_DISPLAY1);
#endif
#ifdef FIELD_TO_DISPLAY2
	PreSimuAdd2(ep,FIELD_TO_DISPLAY2);
#endif
#ifdef DISPLAY_NE
	PreSimuAddNE(ep,ne);
#endif
#endif
}

#endif //ifdef _SIMULATE_H_
	
