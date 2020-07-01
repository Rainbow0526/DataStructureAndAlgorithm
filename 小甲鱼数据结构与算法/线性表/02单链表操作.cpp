//插入操作 
//初始条件： 顺序线性表L已经存在，1<=i<=ListLength(L)
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 
Status ListInsert(LinkList *L,int i,ElemType e){
	int j;
	LinkList p,s;
	
	p = *L;
	j = 1;
	
	while(p&&j<i){
		p=p->next;
		j++; 
	}
	
	if(!p||j>i){
		return ERROR;
	} 
	
	s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	
	s->next=p->next;
	p->next=s;
	
	return OK;
}
//删除操作
//初始条件：顺序线性表L已经存在，1<=i<=ListLength(L)
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度-1 
Status ListDelet(LinkList *L,int i,ElemType *e){
	int j;
	LinkList p,q;
	
	p=*L;
	j=1;
	
	while(p->next && j<i){
		p=p->next;
		++j;
	} 
	
	if(!(p->next)||j>i){
		return ERROR;
	}
	
	q=p->next;
	p->next=q->next;
	
	*e=q->data;
	free(q);
	
	return OK;

//头插法建立单链表示例	
void CreateListHead(LinkList *L,int n){
	LinkList p;
	int i;
	
	srand(time(0));
	
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	
	for(i=0;i<n;i++){
		p =(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		p->next=(*L)->next;
		(*L)->next=p; 
	}
} 
	
//尾插法建立单链表
void CreatListtTail(LinkList *L,int n){
	LinkList p,r;
	int i;
	
	srand(time(o=0));
	*L= (LinkList)malloc(sizeof(Node));
	r=*L;
	
	for(i=0;i<n;i++){
		p=(Node *)malloc(sizeof(Node));
		p->data=rand()%100+1;
		r->next = p;
		r=p;
	}
	r->next=NULL;
} 

//整表删除
Status ClearList(LinkList *L){
	LinkList p,q;
	p=(*L)->next;
	
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;
	
	return OK;
} 
	
//静态链表（游标实现法）：用数组代替指针实现单链表
//对静态链表进行初始化相当于初始化数组
//第一个和最后一个data不存放数据；第一个的游标是备用链表的下表、最后一个的游标是第一个数据的下标 ；存放数据的最后一个游标是0 
Status InitList(StaticLinkList space)
{
	int i;
	for(i=0;i<MAXSIZE-1;i++)
	{
		space[i].cur=i+1; 
	 } 
	 space[MAXSIZE-1].cur=0;
	 
	 return OK;
 } 
 
 //静态链表的插入操作 （删除第i个元素省略） 
 //在静态链表L中第i个元素之前插入新的数据元素e 
int Malloc_SLL(StaticLinkList space)
{
	int i=space[0].cur;
	if(space[0].cur)
		space[0].cur=space[i].cur;
		return i;
}
Status ListInsert(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k=MAX_SIZE -1;
	if(i<1||i>ListLength(L)) 
	{
		return ERROR;
	}
	j=Malloc_SLL(L);
	if(j)
	{
		L[j].data=e;
		for(l=1;l<=i-1;l++)
		{
			k=L[k].cur;
		 } 
		 L[j].cur=L[k].cur;
		 L[k].cur=j;
		 
		 return OK;
	}
	return ERROR;
 } 
	
	
	
	
	
	
	
	
	
	
	
} 
