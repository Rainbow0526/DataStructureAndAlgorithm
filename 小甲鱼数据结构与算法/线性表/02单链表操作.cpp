//������� 
//��ʼ������ ˳�����Ա�L�Ѿ����ڣ�1<=i<=ListLength(L)
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 
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
//ɾ������
//��ʼ������˳�����Ա�L�Ѿ����ڣ�1<=i<=ListLength(L)
//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ���-1 
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

//ͷ�巨����������ʾ��	
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
	
//β�巨����������
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

//����ɾ��
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
	
//��̬�����α�ʵ�ַ��������������ָ��ʵ�ֵ�����
//�Ծ�̬������г�ʼ���൱�ڳ�ʼ������
//��һ�������һ��data��������ݣ���һ�����α��Ǳ���������±����һ�����α��ǵ�һ�����ݵ��±� ��������ݵ����һ���α���0 
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
 
 //��̬����Ĳ������ ��ɾ����i��Ԫ��ʡ�ԣ� 
 //�ھ�̬����L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e 
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
