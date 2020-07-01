#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/*获得元素操作*/
//Status是函数的类型，其值是函数结果状态代码，如OK等
//初始条件：线性表L已经存在，1<=i<=ListLength(L)
//操作结果：用e返回L中第i个数据元素的值 
 
typedef int Status;
Status GetElem(SqList L,int i,ElemType){
	if(L.length==0||i<1||i>L.length){
		return ERROR;
	}
	*e = L.data[i-1];
	return OK; 
}

/*插入元素操作*/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在第i个位置之前插入新的数据元素e，L长度+1*/

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

/*删除元素操作*/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：删除L的第i个数据元素，并用e返回其值,L的长度-1*/
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
