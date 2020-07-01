#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/*���Ԫ�ز���*/
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
//��ʼ���������Ա�L�Ѿ����ڣ�1<=i<=ListLength(L)
//�����������e����L�е�i������Ԫ�ص�ֵ 
 
typedef int Status;
Status GetElem(SqList L,int i,ElemType){
	if(L.length==0||i<1||i>L.length){
		return ERROR;
	}
	*e = L.data[i-1];
	return OK; 
}

/*����Ԫ�ز���*/
/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)*/
/*����������ڵ�i��λ��֮ǰ�����µ�����Ԫ��e��L����+1*/

Status ListInsert(SqlList *L,int i,ElemType e){
	int k;
	if(L->Length == MAXSIZE){
		return FALSE;
	}
	if(i <= L->Length){
		for(k=L-Length-1;k >= i-1;k--){
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;
	L->Length++;
	
	return OK;
} 

/*ɾ��Ԫ�ز���*/
/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)*/
/*���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ,L�ĳ���-1*/
Status ListDelete(SqlList *L,int i,ElemType *e){
	int k;
	 if(L->Length == 0){
	 	return ERROR;
	 }
	 if(i<1 || i>L->Length){
	 	return ERROR;
	 }
	 *e = L->data[i-1];
	 if(i <L->length){
	 	for(k=i;k<length;k++){
	 		L->data[k-1] = L->data[k];
		 }
	 }
	 
	L->length--;
	return OK;
}
