#ifndef DATA_TYPE_DEFINITION_INCLUDE
#define DATA_TYPE_DEFINITION_INCLUDE

typedef double MyDataF;
typedef const MyDataF CMyDataF;

typedef struct {
	int nx;
	int ny;
	MyDataF* data;
} MyStruct;

void ResetStructData(MyStruct mst){
	int i,j;
	for(i=0;i<mst.nx;i++)
		for(j=0;j<mst.ny;j++)
			mst.data[i*mst.ny+j]=0;
}
void InitMyStr(int nnx,int nny,MyStruct* ms){
	ms->nx=nnx;
	ms->ny=nny;
	
	ms->data=(MyDataF*)malloc(nnx*nny*sizeof(MyDataF));

	if(ms->data==NULL){
		printf("Calloc fail!\n");
		exit(0);
	}
	ResetStructData(*ms);
}

void ResetStructData2(MyStruct mst){
	int i,j;
	for(i=0;i<mst.nx;i++)
		for(j=0;j<mst.ny;j++)
			mst.data[i*mst.ny+j]=0;
}
void PrintData(MyStruct mst){
	int i,j;
	for(i=0;i<mst.nx;i++){
		for(j=0;j<mst.ny;j++)
			printf("%2.3e ",mst.data[i*mst.ny+j]);
		printf("\n");
	}
	//system("pause");
}

int BackupMyStruct(MyStruct st,MyStruct stpre){
	if(st.data==stpre.data||&st==&stpre){
		printf("Cannot Copy to Itself!\n");
		return 0;
	}
	if(st.data==NULL||stpre.data==NULL){
		printf("One of the fields is empty!\n");
		return 0;
	}
	if(st.ny!=stpre.ny||st.nx!=st.nx){
		printf("Fields are not the same size!\n");
		return 0;
	}
	if(st.nx==0||st.ny==0){
		printf("Empty space to be copied from!\n");
		return 0;
	}
	memcpy(stpre.data,st.data,st.nx*st.ny*sizeof(st.data[0]));
	return st.nx*st.ny;
	
}
void CheckStruct(const MyStruct stru)
{
	if(stru.ny<=0||stru.nx<=0||stru.data == NULL)
	{
		fprintf(stderr,"Invalid Structure!");
		exit(EXIT_FAILURE);
	}
}
void CaptData(const int num,const char * const fname,const MyStruct data)
{
	int i,j;
	//const int fnum=0;
	char rfnm[32]={'\0'};//real file name
	//char *pts;
	FILE *fp=NULL;
	if(num<10){
		strcpy(rfnm,fname);
		/*
		//deal with filename
		pts=&rfnm[31];
		while(*pts!='.'&&pts!=rfnm){
			*pts=*(pts-1);
			pts--;
		}
		if(pts-rfnm>0)*pts='0'+(num-fnum);
		*/
		//puts(rfnm);
		if((fp=fopen(rfnm,"w"))==NULL){
			printf("Cannot create file: \t%s\n",rfnm);
			exit(EXIT_FAILURE);
		}
		for(j=0;j<data.ny;j++){
			for(i=0;i<data.nx;i++)
				fprintf(fp,"%4.4e ",data.data[i*data.ny+j]);
			fprintf(fp,"\n");
		}
		fclose(fp);
	}else{
		printf("num larger than or equals  to 10\n");
	}
}

void CaptDataM(const int num,const char*fname,const MyStruct data,int p)
{
	int i,j;
	//const int fnum=0;
	char rfnm[32]={'\0'};//real file name
	//char *pts;
	FILE *fp=NULL;
	if(p<0||p>data.nx||p>data.ny){
		printf("Invalid p in function CaptDataM!\n");
		return;
	}
	if(num<10){
		strcpy(rfnm,fname);
		/*
		//deal with filename
		pts=&rfnm[31];
		while(*pts!='.'&&pts!=rfnm){
			*pts=*(pts-1);
			pts--;
		}
		if(pts-rfnm>0)*pts='0'+(num-fnum);
		*/
		//puts(rfnm);
		if((fp=fopen(rfnm,"w"))==NULL){
			printf("Cannot create file: \t%s\n",rfnm);
			exit(0);
		}
		for(j=0;j<data.ny;j+=p){
			for(i=0;i<data.nx;i+=p)
				fprintf(fp,"%4.4e ",data.data[i*data.ny+j]);
			fprintf(fp,"\n");
		}
		fclose(fp);
	}else{
		printf("num larger than or equals  to 10\n");
	}
}
//Total fields zone posistion
int tpis;
int tpjs;
int tpie;
int tpje;

void SaveToFile(); //defined in savedata.h
#endif
